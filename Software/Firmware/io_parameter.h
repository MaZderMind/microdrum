#ifndef IO_PARAMETER_H_
#define IO_PARAMETER_H_

#define N_PARAMETERS 16

extern uint8_t parameter[N_PARAMETERS];

void io_parameter_init(void);
void io_parameter_sync(uint8_t cycle);

#endif /*IO_PARAMETER_H_*/
