#ifndef IO_H_
#define IO_H_

#define MUX_PORT      PORTA
#define MUX_DDR       DDRA

// Mux-Pins PD0-PD3
#define MUX_PIN       PA0

// die Mux-Pins müssen hintereinander liegen
#define MUX_PIN0      (MUX_PIN+0)
#define MUX_PIN1      (MUX_PIN+1)
#define MUX_PIN2      (MUX_PIN+2)

void io_init(void);
void io_sync(void);

#endif /* IO_H_ */
