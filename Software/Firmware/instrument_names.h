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
prog_char name0[] PROGMEM = "Alpha";
prog_char name1[] PROGMEM = "Beta";
prog_char name2[] PROGMEM = "Gamma";
prog_char name3[] PROGMEM = "Delta";
prog_char name4[] PROGMEM = "Epsilon";
prog_char name5[] PROGMEM = "Zeta";
prog_char name6[] PROGMEM = "Eta";
prog_char name7[] PROGMEM = "Theta";

/// Array mit Pointern auf die Namen
PROGMEM prog_char *names[] = {name0, name1, name2, name3, name4, name5, name6, name7};

#endif // INSTRUMENT_NAMES_H_
