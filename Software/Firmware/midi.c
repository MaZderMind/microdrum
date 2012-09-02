/**
 * @file
 * Ansteuerung eines MIDI-Gerätes über den UART-Controller
 */

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include <avr/interrupt.h>

#include "bits.h"
#include "io_config.h"
#include "midi.h"

/**
 * Pointer zum gespeicherten Clock-Interrupt-Callback
 */
volatile midi_clock_handler clock_callback;

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

/**
 * 8-Bit-Feld zum speichern der derzeit aktiven Instrumente
 */
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
		SETBIT(UCSRA, U2X);
	#else
		CLEARBIT(UCSRA, U2X);
	#endif

	// Asynchron 8N1 (8 Datenbits, keine Parität, 1 Stop-Bit)
	SETBITS(UCSRC, BIT(URSEL) | BIT(UCSZ0) | BIT(UCSZ1));

	// Das TransmitEnable-Bit und das ReceiveEnable-Bit im UartControlAndStatusRegisterB setzen
	SETBITS(UCSRB, BIT(TXEN) | BIT(RXEN));

	// Variablen nullen
	clock_callback = NULL;
	clock_callback_prescale = 1;
	clock_callback_cnt = 0;
}

/*
 * Doku wird vom Header-File übernommen
 */
void midi_set_clock_interrupt(midi_clock_handler cb, uint8_t prescale, uint8_t beats)
{
	// Das ReceiveCompleteInterruptEnable im UartControlAndStatusRegisterB setzen
	SETBIT(UCSRB, RXCIE);

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
	while(BITCLEAR(UCSRA, UDRE));

	// Daten senden
	UDR = data;
}

/*
 * Ein Instrument triggern
 * siehe Header-Datie für mehr Informationen
 */
void midi_trigger_instrument(uint8_t instrument, uint8_t velocity)
{
	// NoteOn-Nachricht senden
	midi_noteon(midi_instruments[instrument], velocity);

	// das entsprechende Bit im Bitfeld setzen
	SETBIT(midi_triggered_instruments, instrument);
}


/*
 * Alle zuvor aktiven Instrumente deaktivieren
 * siehe Header-Datie für mehr Informationen
 */
void midi_detrigger_instruments(void)
{
	// für alle Instrumente
	for(uint8_t instrument = 0; instrument < N_INSTRUMENTS; instrument++)
	{
		// Testen, ob das entsprechende Bit gesetzt ist
		if(BITSET(midi_triggered_instruments, instrument))
		{
			// und sende ggf. eine NoteOff-Nachricht
			midi_noteoff(midi_instruments[instrument]);
		}
	}

	// Das Bitfeld leeren
	midi_triggered_instruments = 0;
}

/*
 * Ein NoteOn-Kommando senden
 * siehe Header-Datie für mehr Informationen
 */
void midi_noteon(uint8_t note, uint8_t velocity)
{
	// Midi-Kanal senden
	midi_send((midi_channel & 0x0F) | MIDI_NOTEON);

	// Noten-Wert senden
	midi_send(note & 0x7F);

	// Anschlagstärke senden
	midi_send(velocity & 0x7F);
}

/*
 * Ein NoteOff-Kommando senden
 */
void midi_noteoff(uint8_t note)
{
	// Midi-Kanal senden
	midi_send((midi_channel & 0x0F) | MIDI_NOTEOFF);

	// Noten-Wert senden
	midi_send(note & 0x7F);

	// Anschlagstärke 0 senden
	midi_send(0);
}

/*
 * Eine Midi-Controll-Change-Nachricht senden
 */
void midi_cc(uint8_t controller, uint8_t value)
{
	// Midi-Kanal senden
	midi_send((midi_channel & 0x0F) | MIDI_CC);

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
 *              ...
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
	// anliegende Nachricht aus dem Puffer lesen
	uint8_t input = UDR;

	// Nachricht auswerten
	switch(input)
	{
		// Eine Clock-Nachricht
		case MIDI_CLOCK: {
			// Lokale kopien der volatile-Variablen
			uint8_t clk = clock_callback_cnt, prescale = clock_callback_prescale, reset = clock_callback_reset;

			// Wenn der Prescaler erreicht wurde
			if(clk % prescale == 0)
			{
				// den Event-Handler auslösen, dabei den passenden Beat ausrechnen
				if(clock_callback) clock_callback(clk / prescale);
			}

			// Den Clock-Zähler erhöhen, dabei prüfen ob die max. Beat-Zahl erreicht wurde
			if(++clk == reset)
			{
				// Den Clock-Zähler zurück setzen
				clk = 0;
			}

			// Den Clock-Zähler zurück in die volatile-Variable schreiben
			clock_callback_cnt = clk;
			break;
		}

		// Eine Midi-Start-Nachricht
		case MIDI_START: {
			// Den Clock-Zähler auf 0 zurück fahren
			clock_callback_cnt = 0;
			break;
		}
	}
}
