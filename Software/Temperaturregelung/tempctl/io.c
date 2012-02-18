#include <avr/io.h>
#include "io.h"

void io_init()
{
	// set pin 0 and 1 as output, other pins as input
	DDRB |= (1<<DDB0) | (1<<DDB1);
	
	// ADC-Divisor may be 32 or 64
	//   F_CPU=4800000
	//   TFmin=F_CPU/200000=24
	//   TFmax=F_CPU/50000=96
	//   TF=32, TFmin < TF < TFmax
	
	// enable adc and set adc divisor to 32
	ADCSRA = (1<<ADEN) | (1<<ADPS2) | (1<<ADPS1);
	
	// set adc refs to vcc and select ADC3
	ADMUX  = (1<<MUX0) | (1<<MUX1);
	
	// dummy adc readout
	uint16_t dummy = io_get_temp_adc();
}

uint16_t io_get_temp_adc_raw()
{
	// activate adc conversion
	ADCSRA |= (1<<ADSC);
	
	// wait for adc completion
	while(ADCSRA & (1<<ADSC));
	
	// read value from adc
	uint16_t result = ADCW;
	return result;
}

uint16_t io_get_temp_adc()
{
	uint32_t sum = 0;
	uint8_t cnt = 10;
	for(uint8_t n = 0; n < cnt; n++)
		sum += io_get_temp_adc_raw();
	
	return (uint16_t)(sum / cnt);
}

void io_set_ready(uint8_t on)
{
	if(on)
		PORTB |= (1<<DDB0);
	else
		PORTB &= ~(1<<DDB0);
}

void io_set_heating(uint8_t on)
{
	if(on)
		PORTB |= (1<<DDB1);
	else
		PORTB &= ~(1<<DDB1);
}
