#ifndef IO_CONFIG_H_
#define IO_CONFIG_H_

/**
 * Anzahl der Instrumente
 */
#define N_INSTRUMENTS 8

/**
 * Anzahl der Parameter per Instrument
 */
#define N_PARAMETERS_PER_INSTRUMENT 4

/**
 * Anzahl der Parameter
 */
#define N_PARAMETERS (N_PARAMETERS_PER_INSTRUMENT * N_INSTRUMENTS)

/**
 * Anzahl der Schritte des Sequencers
 */
#define N_STEPS 8
//#define N_STEPS 16

#endif

