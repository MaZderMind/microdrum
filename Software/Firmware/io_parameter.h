/**
 * @file
 * Ansteuerung des Potentiometer-Arrays zur Einstellung von Parametern, externes Interface
 */

#ifndef IO_PARAMETER_H_
#define IO_PARAMETER_H_

#include "io_config.h"

/**
 * Definition eines Event-Handler für das Drehen des Selektorrads
 */
typedef void (*io_parameter_changed_handler)(uint8_t parameter, uint8_t value);

/**
 * Die Parameter-Boards initialisieren
 */
void io_parameter_init(void);

/**
 * Die aktuelle Einstellung der Parameter mit dem internen Zustand synchronisieren
 */
void io_parameter_sync(uint8_t cycle);

/**
 * Den Event-Handler für das Ändern eines Parameters setzen
 */
void io_parameter_set_changed_handler(io_parameter_changed_handler);

#endif /*IO_PARAMETER_H_*/
