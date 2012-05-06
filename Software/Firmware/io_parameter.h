/**
 * @file
 * Ansteuerung des Potentiometer-Arrays zur Einstellugn von Parametern, externes Interface
 */

#ifndef IO_PARAMETER_H_
#define IO_PARAMETER_H_

#include "io_config.h"

/**
 * Extern zugänglicher Status der Parameter
 */
extern uint8_t parameter[N_PARAMETERS];

/**
 * Die Parameter-Boards initialisieren
 */
void io_parameter_init(void);

/**
 * Die aktuelle Einstellung der Parameter mit dem internen Zustand synchronisieren
 */
void io_parameter_sync(uint8_t cycle);

#endif /*IO_PARAMETER_H_*/
