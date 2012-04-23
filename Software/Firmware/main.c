#include <avr/io.h>
#include <avr/pgmspace.h>

#include "lcd.h"

void main (void) {
	DDRB  |= (1<<PB0);
	PORTB |= (1<<PB0);
	
	lcd_init();
	lcd_pstring(PSTR("1/16: Basedrum"));
	lcd_setcursor(0, 1);
	lcd_pstring(PSTR("mew mew"));
	
	while(1);
	return 0;
}
