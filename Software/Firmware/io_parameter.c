/**
 * @file
 * Ansteuerung des Potentiometer-Arrays zur Einstellung von Parametern
 */

#include <stdint.h>
#include <string.h>
#include <avr/io.h>

#include "bits.h"
#include "io_config.h"
#include "io_parameter.h"

/**
 * Event-Handler, der aufgerufen wird, wenn sich ein Parameter geändert hat
 */
io_parameter_changed_handler changed_callback;

/**
 * Maintainence-Werte der Parameter
 */
struct parameter_state_struct
{
	/// Vorzeichen der letzten Wert-Änderung
	unsigned positive:1;

	/// Zuletzt gelesener Wert
	unsigned last:7;
} parameter_state[N_PARAMETERS];

/**
 * Ermitteln des Vorzeichens
 *
 * gibt 1 für positiv und 0 für negativ oder null zurück
 */
uint8_t is_positive(int8_t n)
{
	if (n > 0) return 1;
	else return 0;
}

/**
 * Mapping zum zuordnen der Multiplexer-Ausgänge
 *
 * Die Multiplexer-Ausgänge auf den Parameter-Platinen sind, um das Platinenlayout
 * einseitig und ohen zu viele Brücken ausführen zu können, so angelegt, wie es
 * platz-mäßig am besten passt.
 *
 * Dieses Array ordnet der jeweiligen Multiplexer-Ansteuerung die Entsprechende,
 * logische Parameterkennung zu.
 *
 * Aus ähnlichen Gründen sind einige Potentiometer anders herum eingebaut, so dass
 * ein maximaler Ausschlag 0 und ein minimaler 127 bedeutet. Der invert-Parameter
 * steuert, dass bei diesen der gemessene Wert invertiert wird.
 */
struct {
	/// Zuordnung zwischen Multiplexer-Ansteuerung zur logischen Parameterkennung
	unsigned mapping:7;

	/// Invertieren des Wertes
	unsigned invert:1;
} parameter_map[N_PARAMETERS] = {
	{7,  0},
	{6,  0},
	{5,  0},
	{3,  1},
	{0,  1},
	{2,  1},
	{4,  0},
	{1,  1},

	{14, 0},
	{13, 0},
	{12, 0},
	{15, 0},
	{8,  1},
	{11, 1},
	{9,  1},
	{10, 1}
};

/**
 * Die Parameter-Boards initialisieren
 */
void io_parameter_init()
{
	// ADC aktivieren, Prescaler auf 64
	SETBITS(ADCSRA, BIT(ADEN) | BIT(ADPS2) | BIT(ADPS1));

	// VCC als Referenz
	SETBITS(ADMUX, BIT(REFS0));

	// Maintainence-Werte der Parameter nullen
	memset(parameter_state, 0, sizeof(parameter_state));
}

/**
 * Einen Parameter auslesen
 */
uint8_t io_parameter_read(uint8_t chain)
{
	// MUX-Register auf null
	CLEARBITS(ADMUX, BIT(MUX0) | BIT(MUX1) | BIT(MUX2) | BIT(MUX3));

	// 4 Bits von chain nehmen und nach MUX0 schieben, sodass sie auf MUX0-MUX3 abgebildet werden
	ADMUX |= ((chain & 0x0F) << MUX0);

	// Wandlung starten
	SETBIT(ADCSRA, ADSC);

	// auf Abschluss der Wandlung warten
	while(BITSET(ADCSRA, ADSC));

	// Wert messen
	uint16_t temp = ADCW;

	// Messwert auf 7 Bit reduzieren
	return (temp >> 3);
}

/**
 * Einen Chip auslesen
 */
void io_parameter_readchip(uint8_t cycle, uint8_t chip)
{
	uint8_t offset =  (chip & 0x02) * 8;
	cycle += ((chip & 0x01) * 8);

	// Parameternummer-Mapping auslesen
	uint8_t n = parameter_map[cycle].mapping + offset;

	// Wert auslesen
	uint8_t value = io_parameter_read(chip);

	// ggf. invertieren
	if(parameter_map[cycle].invert)
		value = 127 - value;

	struct parameter_state_struct *state = &parameter_state[n];

	// Differenz zw. dem aktuellen und dem letzten Wert bilden
	int8_t diff = ((int8_t)value - (int8_t)state->last);

	// Anhand der Differenz entscheiden, was getan werden soll
	if(diff == 0)
	{
		// Wenn sich nix geändert hat, muss auch nix getan werden
	}
	else if(is_positive(diff) == state->positive)
	{
		// Wenn die Richtung sich nicht geändert hat, den callback auslösen
		if(changed_callback) changed_callback(n, value);
	}
	else
	{
		// Richtung hat sich geändert, einen Moment innehalten
		state->positive = is_positive(diff);

		// ggf. hier einen Counter unterbringen und mehr als einen Zyklus abwarten
	}

	// Letzten Wert merken
	state->last = value;
}

/**
 * Die aktuelle Einstellung der Parameter mit dem internen Zustand synchronisieren
 */
void io_parameter_sync(uint8_t cycle)
{
	io_parameter_readchip(cycle, 0);
	io_parameter_readchip(cycle, 1);
	io_parameter_readchip(cycle, 2);
	io_parameter_readchip(cycle, 3);
}

/*
 * Den Event-Handler für das Ändern eines Parameters setzen
 */
void io_parameter_set_changed_handler(io_parameter_changed_handler callback)
{
	changed_callback = callback;
}
