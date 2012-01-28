/**
 * Spielt alle con GenenralMidi definierten Perkussionsklänge via Midi ab
 * und zeigt die gesendeten Noten auf dem LCD-Display an
 */ 

#include <util/delay.h>
#include "lcd.h"
#include "midi.h"

// Bereich der von General-Midi definierten und
// von meinem Synth verstandenen Instrumente
// 
//  http://de.wikipedia.org/wiki/General_Midi
#define MIDI_NOTE_MIN 35
#define MIDI_NOTE_MAX 59

// mit der niedrigsten Note starten
volatile uint8_t note = MIDI_NOTE_MIN;

// Vorwärts-Deklaration der Callback-Funktion
void midi_clock();

// Einstiegspunkt
int main(void)
{
	// LCD-Display initialisieren
	lcd_init();
	
	// erste Zeile beschreiben
	lcd_string("init midi & wait");
	
	// Midi-Kommunikation initialisieren
	midi_init();
	
	// Clock-Interrupt-Callback setzen und alle 6 Clocks aufrufen
	//  das entspricht 16 aufrufen je Takt
	midi_set_clock_interrupt(midi_clock, 6);
	
	// Mainloop
	while(1);
}

/**
 * Clock-Interupt-Callback
 */
void midi_clock()
{
	// lokale Arbeitskopie der volatilen note-variable
	uint8_t note_locale = note;
	
	// LCD-Cursor an den Anfang der zweiten Zeile setzen
	lcd_setcursor(0, 1);
		
	// Nachricht ausgeben
	lcd_string("sending ");
	lcd_string(midi_notename(note_locale));
		
	// Etwas Whitespace hinterher schreiben, damit kürze
	// Nachrichten nicht mit längeren vermischt werden
	lcd_string("   ");
	
	// NoteOn mit einer mittleren Anschlagsstärker von 70 senden
	midi_noteon(0, note_locale, 70);
		
	// NoteOff direkt hinterher senden
	//  Perkussionsinstrumente werden üblicherweise nicht gehalten
	midi_noteoff(0, note_locale);
		
	// Notenzähler inkrementieren und ggf. zurück setzen
	if(++note_locale > MIDI_NOTE_MAX)
		note_locale = MIDI_NOTE_MIN;
	
	// lokale Arbeitskopie zurück sichern
	note = note_locale;
}
