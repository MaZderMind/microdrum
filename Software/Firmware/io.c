#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "io.h"
//#include "io_parameter.h"
#include "io_selector.h"

void io_init(void)
{
	// Mux-Lines auf Ausgang
	MUX_DDR |= (1<<MUX_PIN0) | (1<<MUX_PIN1) | (1<<MUX_PIN2);

	// Initialisieren der Parameter-Boards
	//io_parameter_init();


	// Initialisieren des Selektorrades
	io_selector_init();
}

void io_select(uint8_t channel)
{
	channel  &= 0b111;
	MUX_PORT &= ~(0b111 << MUX_PIN);
	MUX_PORT |= (channel << MUX_PIN);

	// den Multiplexern Zeit zum Umschalten geben
	_delay_us(1);
}

void io_sync(void)
{
	// Tastendrücke und Rad-drehung detektieren
	io_selector_detect();

	for(uint8_t cycle = 0; cycle < 8; cycle++)
	{
		// Alle Multiplexer umschalten
		io_select(cycle);

		// Werte der Parameter-Boards auslesen
		//io_parameter_sync(cycle);
	}
}
