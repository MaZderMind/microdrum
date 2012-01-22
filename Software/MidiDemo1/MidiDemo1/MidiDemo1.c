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

// Einstiegspunkt
int main(void)
{
	// mit der niedrigsten Note starten
	uint8_t note = MIDI_NOTE_MIN;
    
	// LCD-Display initialisieren
	lcd_init();
	
	// erste Zeile beschreiben
	lcd_string("init midi & wait");
	
	// Midi-Kommunikation initialisieren
	midi_init();
	
	// Mainloop
	while(1)
	{
		// LCD-Cursor an den Anfang der zweiten Zeile setzen
		lcd_setcursor(0, 1);
		
		// Nachricht ausgeben
		lcd_string("sending ");
		lcd_string(midi_notename(note));
		
		// Etwas Whitespace hinterher schreiben, damit kürze
		// Nachrichten nicht mit längeren vermischt werden
		lcd_string("   ");
		
		// NoteOn mit einer mittleren Anschlagsstärker von 70 senden
		midi_noteon(0, note, 70);
		
		// NoteOff direkt hinterher senden
		//  Perkussionsinstrumente werden üblicherweise nicht gehalten
		midi_noteoff(0, note);
		
		// Notenzähler inkrementieren und ggf. zurück setzen
		if(++note > MIDI_NOTE_MAX)
			note = MIDI_NOTE_MIN;
		
		// 1/4 Sekunde warten
		_delay_ms(250);
	}
}
