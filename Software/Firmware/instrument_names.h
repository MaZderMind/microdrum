/**
 * @file
 * Namen der Instrumente
 *
 * Diese Namen werden auf dem LCD-Diplay angezeigt. Weil Strings viel
 * Platz brauchen, werden diese im Flash abgelegt.
 *
 * @see midi_instruments
 * @todo Möglicherweise mit midi_instruments zusammen legen
 */
#ifndef INSTRUMENT_NAMES_H_
#define INSTRUMENT_NAMES_H_

#include <avr/pgmspace.h>

// Instrumentennamen
const char PROGMEM name0[] = "Alpha";
const char PROGMEM name1[] = "Beta";
const char PROGMEM name2[] = "Gamma";
const char PROGMEM name3[] = "Delta";
const char PROGMEM name4[] = "Epsilon";
const char PROGMEM name5[] = "Zeta";
const char PROGMEM name6[] = "Iota";
const char PROGMEM name7[] = "Kappa";

/// Array mit Pointern auf die Namen
const char *names[] = {name0, name1, name2, name3, name4, name5, name6, name7};

#endif // INSTRUMENT_NAMES_H_
