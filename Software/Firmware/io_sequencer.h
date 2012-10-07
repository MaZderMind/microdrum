/**
 * @file
 * Ansteuerung der Sequencer-Boards, externes Interface
 */

#ifndef IO_SEQUENCER_H_
#define IO_SEQUENCER_H_

/**
 * Port, an dem der Selektor angeschlossen ist
 */
#define SEQUENCER_PORT      PORTC

/**
 * Data-Direction-Register des Selektors
 */
#define SEQUENCER_DDR       DDRC

/**
 * Port-Bit Led-Array 1
 */
#define SEQUENCER_PD_LED1   PC3

/**
 * Port-Bit Led-Array 2
 */
#define SEQUENCER_PD_LED2   PC4


/**
 * Initialisieren der Sequencer-Boards
 */
void io_sequencer_init(void);

void io_sequencer_presync(uint8_t cycle);
void io_sequencer_sync(uint8_t cycle);
void io_sequencer_set(uint8_t sequence);

#endif /*IO_SEQUENCER_H_*/
