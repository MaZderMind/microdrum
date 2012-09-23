/**
 * @file
 * Auslesen des Selektorrades
 */

#include <stdlib.h>
#include "bits.h"
#include "io_selector.h"

/**
 * Event-Handler für das Niederdrücken des Selektorrads
 */
io_selector_pressed_handler pressed_callback;

/**
 * Event-Handler für das Loslassen des Selektorrads nach dem Niederdrücken
 */
io_selector_released_handler released_callback;

/**
 * Event-Handler, der aufgerufen wird, wenn das Selektorrad einen Schritt
 * nach links gedreht wurde
 */
io_selector_rotated_handler left_callback;

/**
 * Event-Handler, der aufgerufen wird, wenn das Selektorrad einen Schritt
 * nach rechts gedreht wurde
 */
io_selector_rotated_handler right_callback;

/**
 * Zwischenspeicher für aktuellen Status
 */
struct {
	/// Entprell-Zähler des linken Ausgangs des Selektorrades
	unsigned left:2;

	/// Entprell-Zähler des rechten Ausgangs des Selektorrades
	unsigned right:2;

	/// Entprell-Zähler des Tasters
	unsigned pressed:3;
} io_selector_state;

/*
 * Initialisieren des Selektorrades
 */
void io_selector_init(void)
{
	// Selektorrad-Pins auf Eingang
	CLEARBITS(SELECTOR_DDR, BIT(SELECTOR_PD_LEFT) | BIT(SELECTOR_PD_RIGHT) | BIT(SELECTOR_PD_PRESS));

	// PullUps aktivieren
	SETBITS(SELECTOR_PORT, BIT(SELECTOR_PD_LEFT) | BIT(SELECTOR_PD_RIGHT) | BIT(SELECTOR_PD_PRESS));
}

/**
 * Einen Druck des Tasters entprellt erkennen
 */
void io_selector_detect_press(void)
{
	// anliegender Wert am Pin des Schalters
	uint8_t pinvalue = !(SELECTOR_PIN & (1<<SELECTOR_PIN_PRESS));

	// wenn der Taster noch gedrückt ist
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

	// wenn der Taster los gelassen ist
	else
	{
		// wenn der intervall-counter 6 erreicht hatte,
		// bevor der button wieder los gelassen wurde
		if(io_selector_state.pressed >= 6)
		{
			// die callback-routine rufen
			if(released_callback) released_callback();
		}

		// den Taster als losgelassen speichern
		io_selector_state.pressed = 0;
	}
}

/**
 * Eine Rotation des Rotationsencoders entprellt erkennen
 */
void io_selector_detect_rotation(void)
{
	// Zustand der beiden Ausgänge des Drehencoders
	uint8_t
		left = (SELECTOR_PIN & (1<<SELECTOR_PIN_LEFT)),
		right = (SELECTOR_PIN & (1<<SELECTOR_PIN_RIGHT));

	// Wenn er linke Ausgang up ist
	if(left)
	{
		// Das Statusregister bis 3 hochzählen
		if(io_selector_state.left < 3)
		{
			io_selector_state.left++;
		}
	}

	// wenn er down ist
	else
	{
		// Das Statusregister auf 0 setzen
		io_selector_state.left = 0;
	}



	// Wenn er rechte Ausgang up ist
	if(right)
	{
		// Das Statusregister bis 3 hochzählen
		if(io_selector_state.right < 3)
		{
			io_selector_state.right++;
		}
	}

	// wenn er down ist
	else
	{
		// Das Statusregister auf 0 setzen
		io_selector_state.right = 0;
	}



	// Wenn der linke Ausgang min. 3 Zyklen up war und der rechte noch down ist
	if(io_selector_state.left == 2 && !right)
	{
		// den Callback anspringen
		if(right_callback) right_callback();
	}

	// Wenn der rechte Ausgang min. 3 Zyklen up war und der linke noch down ist
	else if(io_selector_state.right == 2 && !left)
	{
		// den anderen Callback anspringen
		if(left_callback) left_callback();
	}
}

/*
 * Tastendrücke und Rad-Drehung detektieren
 */
void io_selector_detect(void)
{
	// Taster-Druck detektieren
	io_selector_detect_press();

	// Rad-Drehung detektieren
	io_selector_detect_rotation();
}


/*
 * Den Event-Handler für das Niederdrücken des Selektorrads setzen
 */
void io_selector_set_pressed_handler(io_selector_pressed_handler callback)
{
	pressed_callback = callback;
}

/*
 * Den Event-Handler für das Loslassen des Selektorrads nach dem Niederdrücken setzen
 */
void io_selector_set_released_handler(io_selector_released_handler callback)
{
	released_callback = callback;
}

/*
 * Den Event-Handler für das drehen des Selektorrads um einen Schritt nach links setzen
 */
void io_selector_set_left_handler(io_selector_rotated_handler callback)
{
	left_callback = callback;
}

/*
 * Den Event-Handler für das drehen des Selektorrads um einen Schritt nach rechts setzen
 */
void io_selector_set_right_handler(io_selector_rotated_handler callback)
{
	right_callback = callback;
}
