/*
 * ParameterBoardTest.c
 *
 * Created: 05.03.2012 18:49:09
 *  Author: Peter
 */ 

#include <avr/io.h>
#include <avr/pgmspace.h>
#include <util/delay.h>

#include "uart.h"
#include "io.h"

int main(void)
{
	uart_init();
	io_init();
	
    while(1)
    {
        io_cycle();
		
		for(uint8_t p = 0; p < N_PARAMETERS; p++)
		{
			uart_puts_uint8(parameter[p]);
			uart_putc(' ');
		}
		
		uart_putc('\n');
		
		// print parameter values
		//_delay_ms(1000);
		
    }
}