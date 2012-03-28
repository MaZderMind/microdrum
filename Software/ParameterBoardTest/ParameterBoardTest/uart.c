#include <avr/io.h>
#include <stdlib.h>
#include <avr/pgmspace.h>
#include "uart.h"

void uart_init()
{
	// UART TX einschalten
	UCSRB |= (1<<TXEN);
	
	// Asynchron 8N1
	UCSRC = (1<<URSEL)|(1 << UCSZ1)|(1 << UCSZ0);
	
	// BAUD-Rate einstellen
	#define BAUD 9600
	
	// auf die CPU-Geschwindigkeit anpassen
	#include <util/setbaud.h>
	
	// in Register schreiben
	UBRRH = UBRRH_VALUE;
	UBRRL = UBRRL_VALUE;
	
	// ggf. 2X-Modus aktivieren
	#if USE_2X
		UCSRA |= (1 << U2X);
	#else
		UCSRA &= ~(1 << U2X);
	#endif
}

void uart_putc(unsigned char c)
{
    // warten bis Senden moeglich
	while (!(UCSRA & (1<<UDRE)));
    
    // sende Zeichen
	UDR = c;
}
 
void uart_puts(char *s)
{
	// bis zum 0-Byte über den String iterieren
    while (*s)
    {
		// Zeichen schreiben
        uart_putc(*s);
        s++;
    }
}

	
void uart_puts_p( const char *prg_s )
{
	char c;

	while ( ( c = pgm_read_byte( prg_s++ ) ) ) {
		uart_putc(c);
	}
}



void uart_put_int8(int8_t n)
{
	uart_putc(n);
}

void uart_put_uint8(uint8_t n)
{
	uart_putc(n);
}

void uart_put_int16(int16_t n)
{
	uart_putc(n);
	uart_putc(n >> 8);
}

void uart_put_uint16(uint16_t n)
{
	uart_putc(n);
	uart_putc(n >> 8);
}

void uart_put_int32(int32_t n)
{
	uart_putc(n);
	uart_putc(n >> 8);
	uart_putc(n >> 16);
	uart_putc(n >> 24);
}

void uart_put_uint13(uint32_t n)
{
	uart_putc(n);
	uart_putc(n >> 8);
	uart_putc(n >> 16);
	uart_putc(n >> 24);
}



void uart_puts_int8(int8_t n)
{
	// from -127 up to 128
	char s[5];
	itoa(n, s, 10);
	uart_puts(s);
}

void uart_puts_uint8(uint8_t n)
{
	// from 0 up to 255
	char s[4];
	utoa(n, s, 10);
	uart_puts(s);
}

void uart_puts_int16(int16_t n)
{
	// from -32768 up to 32767
	char s[7];
	itoa(n, s, 10);
	uart_puts(s);
}

void uart_puts_uint16(uint16_t n)
{
	// from 0 up to 65535
	char s[6];
	utoa(n, s, 10);
	uart_puts(s);
}

void uart_puts_int32(int32_t n)
{
	// from -2147483648 up to 2147483647
	char s[12];
	ltoa(n, s, 10);
	uart_puts(s);
}

void uart_puts_uint32(uint32_t n)
{
	// from 0 up to 4294967295
	char s[11];
	ultoa(n, s, 10);
	uart_puts(s);
}
