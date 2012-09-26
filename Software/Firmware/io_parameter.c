/**
 * @file
 * Ansteuerung des Potentiometer-Arrays zur Einstellugn von Parametern
 */

#include <stdint.h>
#include <avr/io.h>

#include "bits.h"
#include "io_config.h"
#include "io_parameter.h"

/**
 * Extern zugänglicher Status der Parameter
 */
uint8_t parameter[N_PARAMETERS];

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
 * ein maximaler Ausschlag 0 und ein minimaler 512 bedeutet. Der invert-Parameter
 * steuert, dass bei diesen der gemessene Wert invertiert wird.
 */
struct {
	/// Zuordnung zwischen Multiplexer-Ansteuerung zur logischen Parameterkennung
	uint8_t mapping:7;

	/// Invertieren des Wertes
	uint8_t invert:1;
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

	// Messwert auf 8 Bit reduzieren
	return (temp >> 2);
}

/**
 * Einen Chip auslesen
 */
void io_parameter_readchip(uint8_t cycle, uint8_t chip, uint8_t mapping, uint8_t offset)
{
	uint8_t n = parameter_map[cycle+mapping].mapping + offset;
	uint8_t v = io_parameter_read(chip);

	// ggf. invertieren
	if(parameter_map[cycle+mapping].invert)
	{
		v = 255 - v;
	}

	parameter[n] = v;
}

/**
 * Die aktuelle Einstellung der Parameter mit dem internen Zustand synchronisieren
 */
void io_parameter_sync(uint8_t cycle)
{
	io_parameter_readchip(cycle, 0, 0,  0);
	io_parameter_readchip(cycle, 1, 8,  0);
	io_parameter_readchip(cycle, 2, 0, 16);
	io_parameter_readchip(cycle, 3, 8, 16);
}
