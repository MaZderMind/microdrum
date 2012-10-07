/**
 * @file
 * Ansteuerung eines MIDI-Gerätes über den UART-Controller, externes Interface
 */

#ifndef MIDI_H_
#define MIDI_H_

/**
 * Baudrate der MIDI-Kommunikation
 */
#define MIDI_BAUD 31250UL

/**
 * Die Midi-Start-Nachricht
 *
 * wenn diese Nachricht empfangen wird, muss der Midi-Clock-Rounter auf 0 zurück gefahren werden
 */
#define MIDI_START 0xFA

/**
 * Midi-Stop-Nachricht
 *
 * Wird verwendet um einen ggf. laufenden, internen Timer zu stoppen
 */
#define MIDI_STOP 0xFC

/**
 * Midi-Clock-Nachricht zum synchronisieren von Host und Slave-Geräten
 */
#define MIDI_CLOCK 0xF8

/**
 * Midi-Continue-Nachricht
 *
 * wird versendet um einen ggf. laufenden, internen Timer nach einer Midi-Stop-Nachricht
 * wieder zu starten, ohne ihn auf 0 zurück zu fahren.
 */
#define MIDI_CONTINUE 0xFB

/**
 * Midi-Song-Position-Pointer-Nachricht
 *
 * wird versendet um den internen Song-Pointer auf einen definierten Wert zu setzen
 */
#define MIDI_SONG_POSITION_POINTER 0xF2

/**
 * Eine Midi-NoteOn-Nachricht
 *
 * Schaltet eine Note im Synthesizer an. Bei einem Drum-Synthesizer ist die
 * Midi-NoteOn-Nachricht der Trigger, der das Instrument auslöst. Trotzdem muss das
 * Instrument wieder mit einer Midi-NoteOff-Nachricht beendet werden. Der zeitliche
 * Abstand zwischen NoteOn und NoteOff darf nicht zu klein sein, damit der Synthesizer
 * genug Zeit hat, den Klang zu produzieren.
 *
 * Das Instrument-Trigger-System sorgt dafür, dass jede Note genau 1/16 aktiv ist und
 * vor dem senden des nächsten NoteOn wieder ausgeschaltet wird.
 *
 * @see midi_trigger_instrument
 * @see midi_detrigger_instruments
 */
#define MIDI_NOTEON 0x90


/**
 * Eine Midi-NoteOff-Nachricht
 *
 * Schaltet die Note wieder aus
 */
#define MIDI_NOTEOFF 0x80

/**
 * Eine Midi-ControlChange-Nachricht
 */
#define MIDI_CC 0xB0

/**
 * Benennung der 12 Noten der 12-Ton-Musik
 */
static const char* const midi_notenames[] = {"C ", "C#", "D ", "D#", "E ", "F ", "F#", "G ", "G#", "A ", "A#", "B "};

/**
 * Konfiguration des Midi-Kanals
 * @todo Über's Menü Konfigurierbar machen
 */
static const uint8_t midi_channel = 0;

/**
 * Konfiguration der Instrumente
 * @todo Über's Menü Konfigurierbar machen
 */
static const uint8_t midi_instruments[8] = {
	36, // 0 -> Bass Drum
	38, // 1 -> Snare Drum
	45, // 2 -> Mid Tom
	37, // 3 -> Rimshot
	39, // 4 -> Hand Clap
	42, // 5 -> Closed  Hi Hat
	46, // 6 -> Open  Hi Hat
	49  // 7 -> Crash Cymbal
};

/**
 * Die Midi-Kommunikation initialisieren
 */
void midi_init(void);

/**
 * Definition eines Clock-Event-Handlers
 */
typedef void (*midi_clock_handler)(uint8_t beat);

/**
 * Den Clock-Event-Handler setzen
 *
 * Der Midi-Clock Event-Handler wird aufgerufen, wenn eine gewisse Anzahl von
 * Midi-Clock-Nachrichten registriert wurden.
 *
 * Wie viele Midi-Clocks übersprungen werden bestimmt, welche Notenlänge
 * ausgegeben wird. Dies wird mit dem prescale-Parameter definiert.
 *
 * Vom Midi-Host werden 96 Midi-Clocks per Takt gesendet. Wenn also ein
 * Clock-Vorteiler von 6 angegeben ist, wird der midi_clock Event-Handler
 * 16 mal pro Takt aufgerufen, also zu jeder 16tel Note.
 *
 * Was zu einem jeweiligen Aufruf des Event-Handlers geschehen soll, muss
 * ebenfalls mit den Midi-Clocks synchronisiert sein, da der Midi-Host zu jedem
 * Zeitpunkt die Midi-Clock anhalten und mit einer Midi-Start-Nachricht zurück
 * zum Anfang des Taktes spulen kann.
 *
 * Dazu wird dem Clock-Event-Handler eine beat-Nummer mitgegeben. Wie viele Beats
 * in einem Takt gezählt werden, wird über den beats-Parameter angegeben.
 *
 * Normalerweise würden hier 16 angegeben werden, um zu jeder 16tel eine andere
 * Note spielen zu können. Zum testen und wenn der Rythmus jedoch einfacher ist
 * kann hier aber auch eine kleinere Zahl angegeben werden, z.B. 8. Der
 * beat-Parameter des Callbacks zählt dann z.B. nur von 0-7, bevor er wieder mit
 * 0 beginnt.
 */
void midi_set_clock_interrupt(midi_clock_handler, uint8_t prescale, uint8_t beats);

/**
 * Ein Instrument triggern
 *
 * Versendet eine Midi-NoteOn-Nachricht für das gegebene Instrument (0-7)
 * eine Midi-NoteOn-Nachricht versenden und speichert im midi_triggered_instruments-Bitfeld,
 * dass das Instrument grade aktiv ist.
 *
 * Welche Midi-Note hinter dem Instrument steht, wird aus dem midi_instruments-Array abgeleitet.
 *
 * Im Zusammenhang mit midi_detrigger_instruments wird sichergestellt, dass eine Note für einen
 * geeignet langen Zeitraum aktiv bleibt, ohne das Hauptprogramm mit delay-Schleifen zu bremsen.
 *
 * @see midi_noteon
 * @see midi_triggered_instruments
 * @see midi_instruments
 * @see midi_detrigger_instruments
 */
void midi_trigger_instrument(uint8_t instrument, uint8_t velocity);

/**
 * Alle zuvor aktiven Instrumente deaktivieren
 *
 * Für die Instrumente, für die im midi_triggered_instruments-Bitfeld ein Bit gesetzt ist
 * wird eine NoteOff-Nachricht gesendet.
 *
 * @see midi_noteoff
 * @see midi_triggered_instruments
 */
void midi_detrigger_instruments(void);

/**
 * Ein NoteOn-Kommando senden
 *
 * channel gibt dabei im Bereich von 0-15 den Midi-Kanal an
 * note kann von 0-127 eine Note zwischen C -1 und G 9 angeben
 * velocity gibt die Anschlagsstärke im Bereich von 1-127 an (0 entspricht NoteOff).
 */
void midi_noteon(uint8_t note, uint8_t velocity);

/**
 * Ein NoteOff-Kommando senden
 */
void midi_noteoff(uint8_t note);

/**
 * Eine Midi-Controll-Change-Nachricht senden
 */
void midi_cc(uint8_t controller, uint8_t value);

/**
 * Den Namen einer Note zusammenbauen
 */
const char* midi_notename(uint8_t note);

#endif /* MIDI_H_ */
