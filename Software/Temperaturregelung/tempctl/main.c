#include <util/delay.h>
#include <avr/pgmspace.h>
#include "softuart.h"
#include "io.h"

// destination adc value
#define Vshould 78

// main routine
int main(void)
{
	// initiate software-uart for serial communication
	softuart_init();
	
	// initialize input and output ports
	io_init();
	
	struct {
		unsigned heating:1;
		unsigned ready:1;
	} state;
	
	// pwm-counter
	uint8_t pwm_ctr = 0;
	
	// while .. forever
    while(1)
    {
		// read temp
		uint16_t val = io_get_temp_adc();
		
		// detect sensor shortage or breakage
		if(val < 24 || val > 1000)
		{
			// write message to serial
			softuart_puts_p(PSTR("ACD-Value out of range: "));
			softuart_puts_uint16(val);
			softuart_putc('\n');
			
			// turn heater off
			io_set_heating(0);
			
			// make ready-led blink
			io_set_ready(0);
			_delay_ms(250);
			io_set_ready(1);
			_delay_ms(250);
			
			// try again
			continue;
		}
		
		// pwm switching difference
		uint8_t pwm = 0;
		if(val > Vshould)
		{
			pwm = val - Vshould;
		}
		
		// pwm switch
		if (pwm < pwm_ctr)
		{
			state.heating = 0;
		}
		else
		{
			state.heating = 1;
		}
		
		// pwm increases with the temperature rising
		// 11+ = heating is always-on
		// 5 = heating is 1/2 the time on
		// 0 = heating is always-off
		if(pwm < 5)
		{
			state.ready = 1;
		}
		else if(pwm > 8)
		{
			state.ready = 0;
		}			
				
		// pwm counter increment
		if(++pwm_ctr >= 10)
			pwm_ctr = 0;
		
		// set heater status
		io_set_heating(state.heating);
		
		// set ready status
		io_set_ready(state.ready);
		
		// write status to serial
		softuart_puts_p(PSTR("ADC-Value: "));
		softuart_puts_uint16(val);
		softuart_puts_p(PSTR(", ADC-Goal: "));
		softuart_puts_uint16(Vshould);
		softuart_puts_p(PSTR(", Ready: "));
		softuart_puts_uint16(state.ready);
		softuart_puts_p(PSTR(", Heating: "));
		softuart_puts_uint16(state.heating);
		softuart_putc('\n');
		
		// wait 1/4 second
		_delay_ms(250);
    }
	
	// end of program
	return 0;
}
