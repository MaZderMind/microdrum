#ifndef IO_H_
#define IO_H_

void io_init();
uint16_t io_get_temp_adc();
void io_set_ready(uint8_t on);
void io_set_heating(uint8_t on);

#endif /* IO_H_ */