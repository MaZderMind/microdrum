#include <avr/pgmspace.h>
#include <util/delay.h>

#include "lcd.h"
#include "io.h"
#include "io_selector.h"
#include "midi.h"
#include "instrument_names.h"

// Forwärts-Deklaration der Event-Handler
void io_selector_pressed(void);
void io_selector_released(void);
void io_selector_left(void);
void io_selector_right(void);

void print_instrument(void);
void midi_clock(uint8_t);

int __attribute__((OS_main))
main(void)
{
	lcd_init();
	lcd_pstring(PSTR("The Microdrum"));
	lcd_setcursor(0, 1);
	print_instrument();

	io_init();

	io_selector_set_pressed_handler(io_selector_pressed);
	io_selector_set_released_handler(io_selector_released);
	io_selector_set_left_handler(io_selector_left);
	io_selector_set_right_handler(io_selector_right);

	midi_init();

	// den Midi-Clock Callback definieren, alle 6 Midi-Clocks aufrufen,
	//   dabei 8 Beats (von 0 bis 7 durchzählen)
	//   Würde das Beats-Zählen mit einer lokalen Variable gemacht, gäbe es Probleme
	//   beim Clock-Reset (neu Aufsetzen nach Pause oder Spulen)
	midi_set_clock_interrupt(midi_clock, 6 , 8);

	for(;;)
	{
		io_sync();
	}

	return 0;
}



volatile uint8_t instrument_counter = 0, instrument_accent = 0;

void print_instrument(void)
{
	uint8_t instrument = instrument_counter % 8;

	lcd_setcursor(0, 1);
	lcd_uint8(instrument + 1);
	lcd_pstring(PSTR("/8 "));
	lcd_pstring((char*)pgm_read_word(&(names[instrument])));
	lcd_space(5);
}

void io_selector_pressed(void)
{
	instrument_accent = 1;
	lcd_setcursor(0, 2);
	lcd_pstring(PSTR("pressed"));
}

void io_selector_released(void)
{
	instrument_accent = 0;
	lcd_setcursor(0, 2);
	lcd_space(7);
}

void io_selector_left(void)
{
	instrument_counter--;
	print_instrument();
}

void io_selector_right(void)
{
	instrument_counter++;
	print_instrument();
}



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
	}
}
