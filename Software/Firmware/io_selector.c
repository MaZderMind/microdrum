#include <stdlib.h>
#include "io_selector.h"
#include "lcd.h"

io_selector_pressed_handler pressed_callback;
io_selector_released_handler released_callback;
io_selector_left_handler left_callback;
io_selector_right_handler right_callback;

struct {
	// erstes byte
	unsigned left:2;
	unsigned right:2;

	// zweites byte
	unsigned pressed:3;
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

void io_selector_detect_press(void)
{
	// anliegender Wert am pin des Schalters
	uint8_t pinvalue = !(SELECTOR_PIN & (1<<SELECTOR_PIN_PRESS));

	// wenn der button noch gedrückt ist
	if(pinvalue)
	{
		// intervall-counter bis 7 hoch zählen
		if(io_selector_state.pressed < 7)
		{
			io_selector_state.pressed++;
		}

		// wenn der intervall-counter == 6 ist
		if(io_selector_state.pressed == 6)
		{
			// die callback-routine anspringen
			if(pressed_callback) pressed_callback();
		}


	}

	// wenn der button los gelassen ist
	else
	{
		// wenn der intervall-counter 6 erreicht hatte,
		// bevor der button wieder los gelassen wurde
		if(io_selector_state.pressed >= 6)
		{
				// die callback-routine rufen
			if(released_callback) released_callback();
		}

		// den button als losgelassen speichern
		io_selector_state.pressed = 0;
	}
}

void io_selector_detect_rotation(void)
{
	uint8_t
		left = (SELECTOR_PIN & (1<<SELECTOR_PIN_LEFT)),
		right = (SELECTOR_PIN & (1<<SELECTOR_PIN_RIGHT));

	if(left)
	{
		if(io_selector_state.left < 3)
		{
			io_selector_state.left++;
		}
	}
	else
	{
		io_selector_state.left = 0;
	}

	if(right)
	{
		if(io_selector_state.right < 3)
		{
			io_selector_state.right++;
		}
	}
	else
	{
		io_selector_state.right = 0;
	}

	if(io_selector_state.left == 2 && !right)
	{
		// der Like kanal ging von low auf high während der rechte noch low ist
		if(right_callback) right_callback();
	}


	else if(io_selector_state.right == 2 && !left)
	{
		if(left_callback) left_callback();
	}
}

void io_selector_detect(void)
{
	// Taster-Druck detektieren
	io_selector_detect_press();

	// Rad-Drehung detektieren
	io_selector_detect_rotation();
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
