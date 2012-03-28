/*
 * uart.h
 *
 * Created: 06.02.2012 21:37:45
 *  Author: Peter
 */ 


#ifndef UART_H_
#define UART_H_

// Init the Uart
void uart_init();

// Writes a character to the serial port.
void uart_putc(unsigned char c);

// Write a NULL-terminated string from RAM to the serial port
void uart_puts(char *s);

// Write a NULL-terminated string from program-space (flash) 
// to the serial port. example: uart_puts_p(PSTR("test"))
void uart_puts_p( const char *prg_s );

// Write numbers as BCD-Text (ASCII chars) to the serial port
void uart_put_int8(int8_t n);
void uart_put_uint8(uint8_t n);
void uart_put_int16(int16_t n);
void uart_put_uint16(uint16_t n);
void uart_put_int32(int32_t n);
void uart_put_uint32(uint32_t n);

// Write numbers as BCD-Text (ASCII chars) to the serial port
void uart_puts_int8(int8_t n);
void uart_puts_uint8(uint8_t n);
void uart_puts_int16(int16_t n);
void uart_puts_uint16(uint16_t n);
void uart_puts_int32(int32_t n);
void uart_puts_uint32(uint32_t n);

#endif /* UART_H_ */