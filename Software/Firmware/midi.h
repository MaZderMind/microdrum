/**
 * Ansteuerung eines MIDI-Ger�tes �ber den UART-Controller
 *
 * http://arduino.cc/en/Tutorial/Midi
 * http://www.mikrocontroller.net/articles/UART
 */

#ifndef MIDI_H_
#define MIDI_H_

/**
 * Baudrate der MIDI-Kommunikation
 */
#define MIDI_BAUD 31250UL

/**
 * Midi Clock-Commands
 */
#define MIDI_CMD_START 0xFA
#define MIDI_CMD_STOP 0xFC
#define MIDI_CMD_CLOCK 0xF8
#define MIDI_CMD_CONTINUE 0xFB

/**
 * Benennung der 12 Noten
 */
static const char* const midi_notenames[] = {"C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};

/**
 * Die Midi-Kommunikation initialisieren
 */
void midi_init();

/**
 * Definition einer Clock-Interrupt-Callback-Routine
 */
typedef void (*midi_clock_interrupt)(void);

/**
 * Die Clock-Interrupt-Callback-Routine setzen
 */
void midi_set_clock_interrupt(midi_clock_interrupt cb, uint8_t prescale);

/**
 * Ein NoteOn-Kommando senden
 */
void midi_noteon(uint8_t channel, uint8_t note, uint8_t velocity);

/**
 * Ein NoteOff-Kommando senden
 */
void midi_noteoff(uint8_t channel, uint8_t note);

/**
 * Den Namen einer Note zusammenbauen
 */
const char* midi_notename(uint8_t note);

#endif /* MIDI_H_ */
