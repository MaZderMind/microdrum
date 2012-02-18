
#ifndef F_CPU
#warning "F_CPU not defined"
#endif

#define SOFTUART_BAUD_RATE      9600

//#define SOFTUART_RX
#define SOFTUART_TX

#ifdef SOFTUART_RX
#define SOFTUART_RXPIN   PINB
#define SOFTUART_RXDDR   DDRB
#define SOFTUART_RXBIT   PB0
#endif // SOFTUART_RX

#ifdef SOFTUART_TX
#define SOFTUART_TXPORT  PORTB
#define SOFTUART_TXDDR   DDRB
#define SOFTUART_TXBIT   PB4
#endif // SOFTUART_TX

#define SOFTUART_T_COMP_LABEL      TIM0_COMPA_vect
#define SOFTUART_T_COMP_REG        OCR0A
#define SOFTUART_T_CONTR_REGA      TCCR0A
#define SOFTUART_T_CONTR_REGB      TCCR0B
#define SOFTUART_T_CNT_REG         TCNT0
#define SOFTUART_T_INTCTL_REG      TIMSK0

#define SOFTUART_CMPINT_EN_MASK    (1 << OCIE0A)

#define SOFTUART_CTC_MASKA         (1 << WGM01)
#define SOFTUART_CTC_MASKB         (0)

/* "A timer interrupt must be set to interrupt at three times 
   the required baud rate." */
//#define SOFTUART_PRESCALE (8)
#define SOFTUART_PRESCALE (1)

#if (SOFTUART_PRESCALE == 8)
  #define SOFTUART_PRESC_MASKA         (0)
  #define SOFTUART_PRESC_MASKB         (1 << CS01)
#elif (SOFTUART_PRESCALE==1)
  #define SOFTUART_PRESC_MASKA         (0)
  #define SOFTUART_PRESC_MASKB         (1 << CS00)
#else 
  #error "prescale unsupported"
#endif

#define SOFTUART_TIMERTOP ( F_CPU/SOFTUART_PRESCALE/SOFTUART_BAUD_RATE/3 - 1)

#if (SOFTUART_TIMERTOP > 0xff)
  #warning "Check SOFTUART_TIMERTOP: increase prescaler, lower F_CPU or use a 16 bit timer"
#endif

#ifdef SOFTUART_RX
  #define SOFTUART_IN_BUF_SIZE     32
#endif

// Init the Software Uart
void softuart_init(void);

#ifdef SOFTUART_RX
// Clears the contents of the input buffer.
void softuart_flush_input_buffer( void );

// Tests whether an input character has been received.
unsigned char softuart_kbhit( void );

// Reads a character from the input buffer, waiting if necessary.
char softuart_getchar( void );
#endif // SOFTUART_RX

#ifdef SOFTUART_TX
// To check if transmitter is busy
unsigned char softuart_transmit_busy( void );

// Writes a character to the serial port.
void softuart_putc( const char );

// Turns on the receive function.
void softuart_turn_rx_on( void );

// Turns off the receive function.
void softuart_turn_rx_off( void );

// Write a NULL-terminated string from RAM to the serial port
void softuart_puts( const char *s );

// Write a NULL-terminated string from program-space (flash) 
// to the serial port. example: softuart_puts_p(PSTR("test"))
void softuart_puts_p( const char *prg_s );

// Write numbers as BCD-Text (ASCII chars) to the serial port
void softuart_put_int16(int16_t n);
void softuart_put_uint16(uint16_t n);
void softuart_put_int32(int32_t n);
void softuart_put_uint32(uint32_t n);

// Write numbers as BCD-Text (ASCII chars) to the serial port
void softuart_puts_int16(int16_t n);
void softuart_puts_uint16(uint16_t n);
void softuart_puts_int32(int32_t n);
void softuart_puts_uint32(uint32_t n);

// Helper-Macro - "automatically" inserts PSTR
// when used: include avr/pgmspace.h before this include-file
#define softuart_puts_P(s___) softuart_puts_p(PSTR(s___))
#endif // SOFTUART_TX