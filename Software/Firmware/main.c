/**
 * @file
 * Hauptdatei der Microdrum-Firmware
 *
 * diese Datei kombiniert alle einzelnen Komponenten der Firmware zu einem sinnvollen Programm.
 */

#include <avr/pgmspace.h>
#include <string.h>

#include "lcd.h"
#include "io_config.h"
#include "io.h"
#include "io_selector.h"
#include "io_parameter.h"
#include "midi.h"
#include "instrument_names.h"

// Forwärts-Deklaration der Event-Handler
void io_selector_pressed(void);
void io_selector_released(void);
void io_selector_left(void);
void io_selector_right(void);
void midi_clock(uint8_t);

// Forwärts-Deklaration der Instrumenten-Anzeige-Routine
void print_selected_instrument(void);

/**
 * Mit dem Selektorrad ausgewähltes Instrument
 */
uint8_t selected_instrument = 0;

/**
 * Zuletzt übermittelte CC-Parameter
 */
uint8_t last_sent_parameter[N_PARAMETERS];

/**
 * Einstiegspunkt des Hauptprogramms
 */
int __attribute__((OS_main))
main(void)
{
	// Das LCD-Display aktivieren
	lcd_init();

	// Programmnamen ausgeben
	lcd_pstring(PSTR("The Microdrum"));

	// aktuellen Instrumentennamen ausgeben
	print_selected_instrument();

	// Ein- & Ausgabe aktivieren
	io_init();

	// Event-Handler für Ein- & Ausgabe setzen
	io_selector_set_pressed_handler(io_selector_pressed);
	io_selector_set_released_handler(io_selector_released);
	io_selector_set_left_handler(io_selector_left);
	io_selector_set_right_handler(io_selector_right);

	// Midi aktivieren
	midi_init();

	// den Midi-Clock Callback definieren
	//   er soll alle 6 Midi-Clocks aufgerufen werden (das entspricht 16tel Noten),
	//   dabei sollen 8 Steps durchgezählt werden (von 0 bis 7)
	//     Würde das Steps-Zählen mit einer lokalen Variable gemacht, gäbe es Probleme
	//     beim Clock-Reset (neu Aufsetzen nach Pause oder Spulen)
	midi_set_clock_interrupt(midi_clock, 6, N_STEPS);

	// Die Kopie der zuletzt versendeten Midi-CC-Parameter auf 0 setzen
	memset(last_sent_parameter, 0, sizeof(last_sent_parameter));

	// Das Hauptprogramm versinkt in einer Endlosschleife, welche die Eingaben der
	// Buttons abnimmt, die LEDs ansteuert und Änderungen an den Drehknöpfen
	// abliest. Die Änderungen an den Drehknöpfen werden als Midi-CC-Nachrichten
	// direkt versendet.
	// Unterbrochen wird es durch Midi-Eingaben (siehe midi.c), wozu auch
	// Midi-Clock-Nachrichten gehören. Diese unterbrechen den normalen Programmablauf
	// und senden entsprechend dem aktuellen Zustand Midi-Noten zurück.
	for(;;)
	{
		io_sync();

		// Für alle Parameter prüfen, ob sich was geändert hat
		for(uint8_t n = 0; n < N_PARAMETERS; n++)
		{
			// Für Midi-CC-Nachrichten sind nur die unterten 7 Bits relevant
			// @TODO: ggf. anzahl der shift-aufrufe optimieren
			uint8_t last = last_sent_parameter[n] >> 1;
			uint8_t next = parameter[n] >> 1;

			if(last != next)
			{
				// und ggf. eine Midi-CC-Nachricht absetzen
				midi_cc(n, next);
			}
		}

		// Kopie der Parameter aktualisieren
		memcpy(last_sent_parameter, parameter, sizeof(last_sent_parameter));
	}

	// Programmende
	return 0;
}

/**
 * Das aktuell ausgewählte Instrument auf dem LCD ausgeben
 */
void print_selected_instrument(void)
{
	lcd_setcursor(0, 1);
	lcd_uint8(selected_instrument + 1);
	lcd_pstring(PSTR("/8 "));
	lcd_pstring(names[selected_instrument]);
	lcd_space(5);
}

/**
 * Event-Handler für das Niederdrücken des Selektorrads
 *
 * @see io_selector_set_released_handler
 */
void io_selector_pressed(void)
{
	lcd_setcursor(0, 2);
	lcd_pstring(PSTR("pressed"));
}

/**
 * Event-Handler für das Loslassen des Selektorrads nach dem Niederdrücken
 *
 * @see io_selector_set_pressed_handler
 */
void io_selector_released(void)
{
	lcd_setcursor(0, 2);
	lcd_space(7);
}

/**
 * Event-Handler, der aufgerufen wird, wenn das Selektorrad einen Schritt
 * nach links gedreht wurde
 *
 * @see io_selector_set_left_handler
 */
void io_selector_left(void)
{
	if(selected_instrument == 0)
		selected_instrument = N_INSTRUMENTS-1;
	else
		selected_instrument--;

	print_selected_instrument();
}

/**
 * Event-Handler, der aufgerufen wird, wenn das Selektorrad einen Schritt
 * nach rechts gedreht wurde
 *
 * @see io_selector_set_right_handler
 */
void io_selector_right(void)
{
	if(selected_instrument == N_INSTRUMENTS-1)
		selected_instrument = 0;
	else
		selected_instrument++;

	print_selected_instrument();
}


/**
 * Event-Handler, der aufgerufen wird, wenn eine gewisse Anzahl von
 * Midi-Clock-Nachrichten registriert wurden.
 *
 * @see midi_set_clock_interrupt
 */
void midi_clock(uint8_t beat)
{
	midi_detrigger_instruments();

	switch(beat)
	{
		case 0: {
			midi_trigger_instrument(0, 70); // Bass Drum
			break;
		}

		case 1: {
			break;
		}

		case 2: {
			midi_trigger_instrument(5, 70); // Closed Hi Hat
			break;
		}

		case 3: {
			break;
		}

		case 4: {
			midi_trigger_instrument(1, 70); // Snare Drum
			midi_trigger_instrument(2, 70); // Mid-Tom
			break;
		}

		case 5: {
			break;
		}

		case 6: {
			midi_trigger_instrument(5, 70); // Closed Hi Hat
			break;
		}

		case 7: {
			break;
		}

		case 8: {
			midi_trigger_instrument(0, 70); // Bass Drum
			break;
		}

		case 9: {
			break;
		}

		case 10: {
			midi_trigger_instrument(6, 70); // Open Hi Hat
			break;
		}

		case 11: {
			break;
		}

		case 12: {
			midi_trigger_instrument(1, 70); // Snare Drum
			midi_trigger_instrument(2, 70); // Mid-Tom
			break;
		}

		case 13: {
			break;
		}

		case 14: {
			midi_trigger_instrument(5, 70); // Closed Hi Hat
			break;
		}

		case 15: {
			break;
		}
	}
}
