#include <stdint.h>
#include <avr/io.h>
#include <util/delay.h>
#include "io.h"

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
	{10, 1},
};

void io_init()
{
	// Select-Lines auf Ausgang
	DDRD |= (1<<DDD2) | (1<<DDD3) | (1<<DDD4);
	
	// ADC aktivieren, Prescaler auf 64
	ADCSRA |= (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
	
	// interne 2,56V als Referenz
	ADMUX |= (1<<REFS0) | (1<<REFS1);
}

void io_select(uint8_t channel)
{
	// Select-Lines auf High
	PORTD |= (1<<PD2) | (1<<PD3) | (1<<PD4);
		
	// drei bits von cycle auf die Port-Bits 2-4 setzen
	PORTD &= (channel & 0b111) << PD2;
	
	// den Multiplexern Zeit zum Umschalten geben
	_delay_us(1);
}

uint8_t io_read_parameter(uint8_t chain)
{
	// MUX-Register auf nullen
	ADMUX &= ~((1<<MUX0) | (1<<MUX1) | (1<<MUX2) | (1<<MUX3));
	
	// 4 Bits von chain nehmen und nach MUX0 schieben, so dass sie auf MUX0-MUX3 abgebildet werden
	ADMUX |= (chain & 0b1111) << MUX0;
	
	// Wandlung starten
	ADCSRA |= (1<<ADSC);
	
	// auf Abschluss der Konvertierung warten
	while (ADCSRA & (1<<ADSC));
	
	// Wert lesen und wegwerfen
	uint16_t temp = ADCW;
	
	temp = 0;
	uint8_t n = 4;
	for(uint8_t i = 0; i < n; i++)
	{
		// Wandlung starten
		ADCSRA |= (1<<ADSC);
	
		// auf Abschluss der Konvertierung warten
		while (ADCSRA & (1<<ADSC));
	
		// Wert lesen und addieren
		temp += ADCW;
	}
	
	return (temp/n)>>2;
}

void io_cycle()
{
	for(uint8_t cycle = 0; cycle < 8; cycle++)
	{
		io_select(cycle);
		
		uint8_t n, v;
		
		// first chip of first parameter board
		n = parameter_map[cycle].mapping;
		v = io_read_parameter(0);
		
		if(parameter_map[cycle].invert)
			v = 255 - v;
		
		parameter[n] = v;
		
		// first chip of first parameter board
		n = parameter_map[cycle+8].mapping;
		v = io_read_parameter(1);
		
		if(parameter_map[cycle+8].invert)
			v = 255 - v;
		
		parameter[n] = v;
	}
}