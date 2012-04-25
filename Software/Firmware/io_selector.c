#include <stdlib.h>
#include "io_selector.h"
#include "lcd.h"

io_selector_pressed_handler pressed_callback;
io_selector_released_handler released_callback;
io_selector_left_handler left_callback;
io_selector_right_handler right_callback;

struct {
	unsigned pressed:1;
	unsigned left:1;
	unsigned right:1;
} io_selector_state;

void io_selector_init(void)
{
	// Selektorrad-Pins auf Eingang
	SELECTOR_DDR &= ~((1<<SELECTOR_PD_LEFT) | (1<<SELECTOR_PD_RIGHT) | (1<<SELECTOR_PD_PRESS));
	
	// PullUps aktivieren
	SELECTOR_PORT |= (1<<SELECTOR_PD_LEFT) | (1<<SELECTOR_PD_RIGHT) | (1<<SELECTOR_PD_PRESS);
	
	pressed_callback = NULL;
	released_callback = NULL;
	left_callback = NULL;
	right_callback = NULL;
	
	io_selector_state.pressed = 0;
}

void io_selector_detect(void)
{
	uint8_t pinvalue = !(SELECTOR_PIN & (1<<SELECTOR_PIN_PRESS));
	
	if(!io_selector_state.pressed && pinvalue)
	{
		io_selector_state.pressed = 1;
		if(pressed_callback) pressed_callback();
	}
	
	else if(io_selector_state.pressed && !pinvalue)
	{
		io_selector_state.pressed = 0;
		if(released_callback) released_callback();
	}
}

void io_selector_set_pressed_handler(io_selector_pressed_handler callback)
{
	pressed_callback = callback;
}

void io_selector_set_released_handler(io_selector_released_handler callback)
{
	released_callback = callback;
}

void io_selector_set_left_handler(io_selector_left_handler callback)
{
	left_callback = callback;
}

void io_selector_set_right_handler(io_selector_right_handler callback)
{
	right_callback = callback;
}
