/**
 * Ansteuerung eines MIDI-Gerätes über den UART-Controller
 *
 * http://arduino.cc/en/Tutorial/Midi
 * http://www.mikrocontroller.net/articles/UART
 */

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "midi.h"

/**
 * Pointer zum gespeicherten Clock-Interrupt-Callback
 */
volatile midi_clock_interrupt clock_callback;

/**
 * gespeicherter Clock-Prescaler
 */
volatile uint8_t clock_callback_prescale;

/**
 * Clock-Counter-Reset, abgeletitet von der gewünschten Beats-Zahl
 */
volatile uint8_t clock_callback_reset;

/**
 * Zähler der interupt-routine
 */
volatile uint8_t clock_callback_cnt;

uint8_t midi_triggered_instruments = 0;

/**
 * Die Midi-Kommunikation initialisieren
 */
void midi_init(void)
{
	// BAUD-Konstante auf den Wert von MIDI_BAUD setzen
	#undef BAUD
	#define BAUD MIDI_BAUD

	// setbaud.h laden, welches die UART-Prescaler-Werte anhand des
	// CPU-Taktes errechnet
	#include <util/setbaud.h>

	// Die Baudrate High/Low setzen, welche in setbaud.h errechnet wurde
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;

	// wenn nötig, aktivierung des 2X Modus
	#if USE_2X
		UCSRA |= (1 << U2X);
	#else
		UCSRA &= ~(1 << U2X);
	#endif

	// Asynchron 8N1 (8 Datenbits, keine Parität, 1 Stop-Bit)
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);

	// Das TransmitEnable-Bit und das ReceiveEnable-Bit im UartControlAndStatusRegisterB setzen
	UCSRB |= (1<<TXEN) | (1<<RXEN);

	// Variablen nullen
	clock_callback = NULL;
	clock_callback_prescale = 1;
	clock_callback_cnt = 0;
 }

/**
 * Die Clock-Interrupt-Callback-Routine setzen
 */
void midi_set_clock_interrupt(midi_clock_interrupt cb, uint8_t prescale, uint8_t beats)
{
	// Das ReceiveCompleteInterruptEnable im UartControlAndStatusRegisterB setzen
	UCSRB |= (1<<RXCIE);

	// Interupts global aktivieren
	sei();

	// Den callback speichern
	clock_callback = cb;

	// Den Prescaler speichern
	clock_callback_prescale = prescale;

	// Die Beats-Zahl speichern
	clock_callback_reset = prescale * beats;
}

/**
 * Midi-Daten über den UART übermitteln
 */
void midi_send(uint8_t data)
{
	//  warten bis Senden möglich ist
	while(!(UCSRA & (1<<UDRE)));

	// Daten senden
    UDR = data;
}

void midi_detrigger_instruments(void)
{
	for(uint8_t instrument = 0; instrument < 8; instrument++)
	{
		if(BITSET(midi_triggered_instruments, instrument))
		{
			midi_noteoff(midi_channel, midi_instruments[instrument]);
		}
	}
	midi_triggered_instruments = 0;
}

void midi_trigger_instrument(uint8_t instrument, uint8_t velocity)
{
	SETBIT(midi_triggered_instruments, instrument);
	midi_noteon(midi_channel, midi_instruments[instrument], velocity);
}

/**
 * Ein NoteOn-Kommando senden
 *  channel gibt dabei im Bereich von 0-15 den Midi-Kanal an
 *  note kann von 0-127 eine Note zwischen C -1 und G 9 angeben
 *  velocity gibt die Anschlagsstärke im Bereich von 1-127 an (0 = NoteOff)
 */
void midi_noteon(uint8_t channel, uint8_t note, uint8_t velocity)
{
	// Midi-Kanal senden
	midi_send((channel & 0x0F) | MIDI_NOTEON);

	// Noten-Wert senden
	midi_send(note & 0x7F);

	// Anschlagstärke senden
	midi_send(velocity & 0x7F);
}

/**
 * Ein NoteOff-Kommando senden
 */
void midi_noteoff(uint8_t channel, uint8_t note)
{
	// Midi-Kanal senden
	midi_send((channel & 0x0F) | MIDI_NOTEOFF);

	// Noten-Wert senden
	midi_send(note & 0x7F);

	// Anschlagstärke 0 senden
	midi_send(0);
}

void midi_cc(uint8_t channel, uint8_t controller, uint8_t value)
{
	// Midi-Kanal senden
	midi_send((channel & 0x0F) | MIDI_CC);

	// Controller-Nummer
	midi_send(controller & 0x7F);

	// Controller-Wert
	midi_send(value & 0x7F);
}


/**
 * Den Namen einer Note zusammenbauen
 * Gibt einen Pointer auf einen statischen Speicherbereich zurück, der
 * gültig bleibt, bis die Methode erneut aufgerufen wird.
 *
 *  Midi-Note 0  =  C -1
 *            1  =  C#-1
 *            2  =  D -1
 *               …
 *          125  =  F 9
 *          126  =  F#9
 *          127  =  G 9
 */
const char* midi_notename(uint8_t note)
{
	// statischer String-Puffer von 6 Bytes
	//  3 Bytes für den Notennamen (siehe midi.h)
	//  2 Bytes für die Oktave (-1 bis 9)
	//  1 Null-Byte (Stringende)
	static char notename[6] = "";

	// Index der Basisnote (C-B ? 0-11)
	uint8_t basenote = note % 12;

	// Name der Note aus dem Namen-Array kopieren
	strcpy(notename, midi_notenames[basenote]);

	// Postfix der Note (-1 bis 9)
	int8_t postfix = (note / 12) - 1;

	// Postix in einen String umwandeln
	char postfix_str[3] = "";
	itoa(postfix, postfix_str, 10);

	// an den Notennamen anhängen
	strcat(notename, postfix_str);

	// Pointer auf statisches Array zurückgeben
	return notename;
}

/**
 * UART Empfangs-Interrupt
 */
ISR(USART_RXC_vect)
{
	// anliegendes Kommando aus dem Puffer lesen
	uint8_t input = UDR;

	// Befehl auswerten
	switch(input)
	{
		case MIDI_CLOCK: {
			uint8_t clk = clock_callback_cnt, prescale = clock_callback_prescale, reset = clock_callback_reset;

			if(clk % prescale == 0)
			{
				if(clock_callback) clock_callback(clk / prescale);
			}

			if(++clk == reset)
			{
				clk = 0;
			}

			clock_callback_cnt = clk;
			break;
		}

		case MIDI_START: {
			clock_callback_cnt = 0;
			break;
		}
	}
}

