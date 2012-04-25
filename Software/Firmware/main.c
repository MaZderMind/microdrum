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

int main(void)
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
	//lcd_setcursor(0, 1);
	//lcd_pstring(PSTR("pressed     "));
	lcd_data('.');
}

void io_selector_released(void)
{
	//lcd_setcursor(0, 1);
	//lcd_pstring(PSTR("released    "));
	lcd_data('#');
}


uint8_t selected = 0;
void io_selector_left(void)
{
	selected++;

	lcd_setcursor(0, 1);
	lcd_pstring(PSTR("selected: "));
	lcd_uint8(selected);
	lcd_pstring(PSTR("   "));
}

void io_selector_right(void)
{
	selected++;

	lcd_setcursor(0, 1);
	lcd_pstring(PSTR("selected: "));
	lcd_uint8(selected);
	lcd_pstring(PSTR("    "));
}
