#ifndef IO_SELECTOR_H_
#define IO_SELECTOR_H_

#include <avr/io.h>

#define SELECTOR_PORT      PORTD
#define SELECTOR_PIN       PIND
#define SELECTOR_DDR       DDRD

// Selector-Ports PD4-PD6
#define SELECTOR_PD_LEFT      PD4
#define SELECTOR_PD_RIGHT     PD5
#define SELECTOR_PD_PRESS     PD6

// Selector-Pins PD4-PD6
#define SELECTOR_PIN_LEFT      PIND4
#define SELECTOR_PIN_RIGHT     PIND5
#define SELECTOR_PIN_PRESS     PIND6

void io_selector_init(void);
void io_selector_detect(void);

typedef void (*io_selector_pressed_handler)(void);
typedef void (*io_selector_released_handler)(void);
typedef void (*io_selector_left_handler)(void);
typedef void (*io_selector_right_handler)(void);

void io_selector_set_pressed_handler(io_selector_pressed_handler);
void io_selector_set_released_handler(io_selector_released_handler);
void io_selector_set_left_handler(io_selector_left_handler);
void io_selector_set_right_handler(io_selector_right_handler);

#endif /* IO_SELECTOR_H_ */
