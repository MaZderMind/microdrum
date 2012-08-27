/**
 * @file
 * Ansteuerung der Peripherie, externes Interface
 */

#ifndef IO_H_
#define IO_H_

/**
 * Port, an dem die Multiplexer angeschlossen werden
 */
#define MUX_PORT      PORTC

/**
 * Data-Direction-Register der Multiplexer
 */
#define MUX_DDR       DDRC

/**
 * Erster Pin des Multiplexers
 *
 * Der zweite und dritte Pin müssen an den beiden darauffolgenden Pins
 * des Controllers angeschlossen werden
 */
#define MUX_PIN       PC0

/**
 * Erster Pin des Multiplexers (automatisch abgeleitet)
 */
#define MUX_PIN0      (MUX_PIN+0)

/**
 * Zweiter Pin des Multiplexers (automatisch abgeleitet)
 */
#define MUX_PIN1      (MUX_PIN+1)

/**
 * Dritter Pin des Multiplexers (automatisch abgeleitet)
 */
#define MUX_PIN2      (MUX_PIN+2)

/**
 * Die Peripherie initialisieren
 */
void io_init(void);

/**
 * Die Peripherie mit dem internen Zustand synchronisieren
 */
void io_sync(void);

#endif /* IO_H_ */
