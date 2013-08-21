#include <stdint.h>
#include <avr/io.h>
#include "io_sequencer.h"
#include "bits.h"

volatile uint8_t io_sequence = 0;
volatile uint16_t io_selection = 0b000000000100110;

/**
 * Initialisieren der Sequencer-Boards
 */
void io_sequencer_init(void)
{
	// Led-Array-Pins auf ausgabg
	SETBITS(SEQUENCER_DDR, BIT(SEQUENCER_PD_LED1) | BIT(SEQUENCER_PD_LED2));

	// Leds aus
	CLEARBITS(SEQUENCER_PORT, BIT(SEQUENCER_PD_LED1) | BIT(SEQUENCER_PD_LED2));
}

void io_sequencer_set(uint8_t sequence)
{
	// 4 Bits übernehmen (erst mal nur 3, so lange wir nur ein Board haben)
	io_sequence = sequence & 0x07 /*0x0F*/;
}

void io_sequencer_presync(uint8_t cycle)
{
	// Leds aus
	CLEARBITS(SEQUENCER_PORT, BIT(SEQUENCER_PD_LED1) | BIT(SEQUENCER_PD_LED2));
}

void io_sequencer_sync(uint8_t cycle)
{
	// lokale Kopie der volatile-Variable
	uint8_t sequence = io_sequence;

	// Sequenz-Led
	if(cycle % 2 == 1)
	{
		cycle /= 2;

		// eine Sequencer-Led
		if(cycle+0 == sequence) SETBIT(SEQUENCER_PORT, SEQUENCER_PD_LED1);
		else CLEARBIT(SEQUENCER_PORT, SEQUENCER_PD_LED1);

		if(cycle+4 == sequence) SETBIT(SEQUENCER_PORT, SEQUENCER_PD_LED2);
		else CLEARBIT(SEQUENCER_PORT, SEQUENCER_PD_LED2);
	}

	// Button-Led
	else
	{
		cycle /= 2;

		if(BITSET(io_selection, cycle+0)) SETBIT(SEQUENCER_PORT, SEQUENCER_PD_LED1);
		else CLEARBIT(SEQUENCER_PORT, SEQUENCER_PD_LED1);

		if(BITSET(io_selection, cycle+4)) SETBIT(SEQUENCER_PORT, SEQUENCER_PD_LED2);
		else CLEARBIT(SEQUENCER_PORT, SEQUENCER_PD_LED2);
	}
}
