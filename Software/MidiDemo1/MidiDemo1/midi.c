/**
 * Ansteuerung eines MIDI-Ger�tes �ber den UART-Controller
 *
 * http://arduino.cc/en/Tutorial/Midi
 * http://www.mikrocontroller.net/articles/UART
 */

#include <stdlib.h>
#include <string.h>
#include <avr/io.h>
#include "midi.h"

/**
 * Die Midi-Kommunikation initialisieren
 */
void midi_init()
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
	
	// wenn n�tig, aktivierung des 2X Modus
	#if USE_2X
		UCSRA |= (1 << U2X);
	#else
		UCSRA &= ~(1 << U2X);
	#endif
	
	// Asynchron 8N1 (8 Datenbits, keine Parit�t, 1 Stop-Bit)
	UCSRC = (1<<URSEL) | (1<<UCSZ1) | (1<<UCSZ0);
	
	// Das TransmitEnable-Bit im UartControlAndStatusRegisterB setzen
	UCSRB |= (1<<TXEN);
}

/**
 * Midi-Daten �ber den UART �bermitteln
 */
void midi_send(uint8_t data)
{
	//  warten bis Senden m�glich ist
	while(!(UCSRA & (1<<UDRE)));
	
	// Daten senden
	UDR = data;
}

/**
 * Ein NoteOn-Kommando senden
 *  channel gibt dabei im Bereich von 0-15 den Midi-Kanal an
 *  note kann von 0-127 eine Note zwischen C -1 und G 9 angeben
 *  velocity gibt die Anschlagsst�rke im Bereich von 1-127 an (0 = NoteOff)
 */
void midi_noteon(uint8_t channel, uint8_t note, uint8_t velocity)
{
	// Midi-Kanal senden
	midi_send((channel & 0x0F) | 0x90);
	
	// Noten-Wert senden
	midi_send(note & 0x7F);
	
	// Anschlagst�rke senden
	midi_send(velocity & 0x7F);
}

/**
 * Ein NoteOff-Kommando senden
 */
void midi_noteoff(uint8_t channel, uint8_t note)
{
	// Midi-Kanal senden
	midi_send((channel & 0x0F) | 0x90);
	
	// Noten-Wert senden
	midi_send(note & 0x7F);
	
	// Anschlagst�rke 0 (NoteOff) senden 
	midi_send(0);
}

/**
 * Den Namen einer Note zusammenbauen
 * Gibt einen Pointer auf einen statischen Speicherbereich zur�ck, der
 * g�ltig bleibt, bis die Methode erneut aufgerufen wird.
 *
 *  Midi-Note 0  ?  C -1
 *            1  ?  C#-1
 *            2  ?  D -1
 *               �
 *          125  ?  F 9
 *          126  ?  F#9
 *          127  ?  G 9
 */
const char* midi_notename(uint8_t note)
{
	// statischer String-Puffer von 6 Bytes
	//  3 Bytes f�r den Notennamen (siehe midi.h)
	//  2 Bytes f�r die Oktave (-1 bis 9)
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
	
	// an den Notennamen anh�ngen
	strcat(notename, postfix_str);
	
	// Pointer auf statisches Array zur�ckgeben
	return notename;
}
