#ifndef IO_H_
#define IO_H_

#define MUX_PORT      PORTD
#define MUX_DDR       DDRD

// Mux-Pins PD0-PD3
#define MUX_PIN      PD0

// die Mux-Pins müssen hintereinander liegen
#define MUX_PIN0      PD0
#define MUX_PIN1      PD1
#define MUX_PIN2      PD2

void io_init(void);
void io_loop(void);

#endif /* IO_H_ */
