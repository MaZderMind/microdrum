#ifndef IO_H_
#define IO_H_

#include <avr/pgmspace.h>

#define N_PARAMETERS 16

extern uint8_t parameter[N_PARAMETERS];

void io_init();
uint8_t io_read_parameter(uint8_t chain);
void io_cycle();

#endif /* IO_H_ */
