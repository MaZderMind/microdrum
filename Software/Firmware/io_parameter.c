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
 *
 * mit dem chain-Parameter wird der linke oder der rechte Chip gewählt
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

	// Temp-Variable mit Messwert füllen (und weg werfen)
	uint16_t temp = ADCW;

	// Anzahl der Messungen
	uint8_t n = 2;
	for(uint8_t i = 0; i < n; i++)
	{
		// Wandlung starten
		SETBIT(ADCSRA, ADSC);

		// auf Abschluss der Wandlung warten
		while(BITSET(ADCSRA, ADSC));

		// Wert lesen und addieren
		temp += ADCW;
	}

	// die Summe durch die Anzahl teilen und auf 8 Bit reduzieren
	return (temp / n) >> 2;
}

/**
 * Die aktuelle Einstellung der Parameter mit dem internen Zustand synchronisieren
 */
void io_parameter_sync(uint8_t cycle)
{
	uint8_t n, v;

	// erster Chip auf den Parameter-Boards
	n = parameter_map[cycle].mapping;
	v = io_parameter_read(0);

	// ggf. invertieren
	if(parameter_map[cycle].invert)
	{
		v = 255 - v;
	}
	
	parameter[n] = v;

	// zweiter Chip auf den Parameter-Boards
	n = parameter_map[cycle + 8].mapping;
	v = io_parameter_read(1);

	// ggf. invertieren
	if(parameter_map[cycle + 8].invert)
	{
		v = 255 - v;
	}
	
	parameter[n] = v;
}
