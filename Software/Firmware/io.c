/**
 * @file
 * Ansteuerung der Peripherie
 */

#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "lcd.h"
#include "io.h"
//#include "io_parameter.h"
#include "io_selector.h"

/*
 * Die Peripherie initialisieren
 */
void io_init(void)
{
	// Mux-Lines auf Ausgang
	MUX_DDR |= (1<<MUX_PIN0) | (1<<MUX_PIN1) | (1<<MUX_PIN2);

	// Initialisieren der Parameter-Boards
	//io_parameter_init();


	// Initialisieren des Selektorrades
	io_selector_init();
}

/**
 * Die Multiplexer auf einen anderen Kanal umschalten
 */
void io_select(uint8_t channel)
{
	// Die drei Multiplexer-Pins auf 1 schalten
	MUX_PORT &= ~(0x07 << MUX_PIN);

	// Die Kanalwahl auf 3 Bits beschränken und auf die Multiplexer-Pins legen
	MUX_PORT |= ((channel & 0x07) << MUX_PIN);

	// den Multiplexern Zeit zum Umschalten geben
	_delay_us(1);
}

/*
 * Die Peripherie mit dem internen Zustand synchronisieren
 */
void io_sync(void)
{
	// Tastendrücke und Rad-drehung detektieren
	io_selector_detect();

	// Alle 8 Multiplexer-Zustände ablaufen
	for(uint8_t cycle = 0; cycle < 8; cycle++)
	{
		// Multiplexer umschalten
		io_select(cycle);

		// Werte der Parameter-Boards auslesen
		//io_parameter_sync(cycle);
	}
}
