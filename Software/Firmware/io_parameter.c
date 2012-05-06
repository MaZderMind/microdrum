#include <stdint.h>
#include <avr/io.h>

#include "io_config.h"
#include "io_parameter.h"

uint8_t parameter[N_PARAMETERS];

struct {
	uint8_t mapping;
	uint8_t invert;
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


void io_parameter_init()
{
	//ADC aktivieren, Prescalerauf 64
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);

	// interne 2,56V als Referenz
	ADMUX |= (1<<REFS0) | (1<<REFS1);
}

uint8_t io_parameter_read(uint8_t chain)
{
	//MUX-Register auf null
	ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));

	// 4 Bits von chain nehmen und nach MUX0 schieben, sodass sie auf MUX0-MUX3 abgebildet werden
	//   FIXME!!
	ADMUX |= (chain & 0b1111) << MUX0;

	// Wandlung starten
	ADCSRA |= (1<<ADSC);

	// auf Abschluss der Konvertierung warten
	while(ADCSRA & (1<<ADSC));

	// Wert lesen und wegwerfen
	uint16_t temp = ADCW;

	temp = 0;
	uint8_t n = 4;
	for(uint8_t i = 0; i < n; i++)
	{
		// Wandlung starten
		ADCSRA |= (1<<ADSC);

		// auf Abschluss der Konvertierung warten
		while(ADCSRA & (1<<ADSC));

		// Wert lesen und addieren
		temp+=ADCW;
	}

	// die Summe durch die Anzahl teilen und auf 8 Bit reduzieren
	return (temp / n) >> 2;
}

void io_parameter_sync(uint8_t cycle)
{
	uint8_t n, v;

	// erster Chip auf den Parameter-Boards
	n = parameter_map[cycle].mapping;
	v = io_parameter_read(0);

	if(parameter_map[cycle].invert)
		v = 255 - v;

	parameter[n] = v;

	// zweiter Chip auf den Parameter-Boards
	n = parameter_map[cycle + 8].mapping;
	v = io_parameter_read(1);

	if(parameter_map[cycle + 8].invert)
		v = 255 - v;

	parameter[n] = v;
}
