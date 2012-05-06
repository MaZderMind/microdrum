/**
 * @file
 * Auslesen des Selektorrades, externes Interface
 */

#ifndef IO_SELECTOR_H_
#define IO_SELECTOR_H_

#include <avr/io.h>

/**
 * Port, an dem der Selektor angeschlossen ist
 */
#define SELECTOR_PORT      PORTD

/**
 * Pin des Ports, an dem der Selektor angeschlossen ist
 */
#define SELECTOR_PIN       PIND

/**
 * Data-Direction-Register des Selektors
 */
#define SELECTOR_DDR       DDRD



/**
 * Port-Bit der linken Seite des Drehencoders
 */
#define SELECTOR_PD_LEFT      PD4

/**
 * Port-Bit der rechten Seite des Drehencoders
 */
#define SELECTOR_PD_RIGHT     PD5

/**
 * Port-Bit des Tasters
 */
#define SELECTOR_PD_PRESS     PD6



/**
 * Pin-Bit der linken Seite des Drehencoders
 */
#define SELECTOR_PIN_LEFT      PIND4

/**
 * Pin-Bit der rechten Seite des Drehencoders
 */
#define SELECTOR_PIN_RIGHT     PIND5

/**
 * Pin-Bit des Tasters
 */
#define SELECTOR_PIN_PRESS     PIND6



/**
 * Definition eines Event-Handlers für das Niederdrücken des Selektorrads
 */
typedef void (*io_selector_pressed_handler)(void);

/**
 * Definition eines Event-Handlers für das Loslassen des Selektorrads nach dem Niederdrücken
 */
typedef void (*io_selector_released_handler)(void);

/**
 * Definition eines Event-Handler für das Drehen des Selektorrads
 */
typedef void (*io_selector_rotated_handler)(void);



/**
 * Initialisieren des Selektorrades
 */
void io_selector_init(void);

/**
 * Tastendrücke und Rad-Drehung detektieren
 */
void io_selector_detect(void);



/**
 * Den Event-Handler für das Niederdrücken des Selektorrads setzen
 */
void io_selector_set_pressed_handler(io_selector_pressed_handler);

/**
 * Den Event-Handler für das Loslassen des Selektorrads nach dem Niederdrücken setzen
 */
void io_selector_set_released_handler(io_selector_released_handler);

/**
 * Den Event-Handler für das drehen des Selektorrads um einen Schritt nach links setzen
 */
void io_selector_set_left_handler(io_selector_rotated_handler);

/**
 * Den Event-Handler für das drehen des Selektorrads um einen Schritt nach rechts setzen
 */
void io_selector_set_right_handler(io_selector_rotated_handler);

#endif /* IO_SELECTOR_H_ */
