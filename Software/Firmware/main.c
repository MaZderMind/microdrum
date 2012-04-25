#include <avr/io.h>
#include <avr/pgmspace.h>

#include "lcd.h"
#include "io.h"
#include "io_selector.h"

// Forwärts-Deklaration der Event-Handler
void io_selector_pressed(void);
void io_selector_released(void);
void io_selector_left(void);
void io_selector_right(void);

// Instrumentennamen
prog_char name0[] PROGMEM = "Bassdrum";
prog_char name1[] PROGMEM = "Snare Drum";
prog_char name2[] PROGMEM = "Conga";
prog_char name3[] PROGMEM = "Rimshot";
prog_char name4[] PROGMEM = "Hand Clap";
prog_char name5[] PROGMEM = "Maracas";
prog_char name6[] PROGMEM = "Cowbell";
prog_char name7[] PROGMEM = "Hi-Hat";
PROGMEM prog_char *names[] = {name0, name1, name2, name3, name4, name5, name6, name7};


int __attribute__((OS_main))
main(void)
{
	lcd_init();
	lcd_pstring(PSTR("The Microdrum"));
	lcd_setcursor(0, 1);

	io_init();

	io_selector_set_pressed_handler(io_selector_pressed);
	io_selector_set_released_handler(io_selector_released);
	io_selector_set_left_handler(io_selector_left);
	io_selector_set_right_handler(io_selector_right);

	io_loop();
	return 0;
}


void io_selector_pressed(void)
{
	lcd_setcursor(0, 2);
	lcd_pstring(PSTR("pressed     "));
	//lcd_data('.');
}

void io_selector_released(void)
{
	lcd_setcursor(0, 2);
	lcd_pstring(PSTR("released    "));
	//lcd_data('#');
}


uint8_t instrument_counter = 0;

void print_instrument(void)
{
	uint8_t instrument = (instrument_counter>>1) % 8;

	lcd_setcursor(0, 1);
	lcd_uint8(instrument + 1);
	lcd_pstring(PSTR("/8 "));
	lcd_pstring((char*)pgm_read_word(&(names[instrument])));
	lcd_space(5);
}

void io_selector_left(void)
{
	instrument_counter++;
	print_instrument();
}

void io_selector_right(void)
{
	instrument_counter--;
	print_instrument();
}
