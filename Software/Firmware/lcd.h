/**
 * @file
 * Ansteuerung eines HD44780 kompatiblen LCD im 4-Bit-Interfacemodus, externes Interface
 *
 * - http://www.mikrocontroller.net/articles/HD44780
 * - http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 * - http://www.reichelt.de/?ARTICLE=31652
 */

#ifndef LCD_H_
#define LCD_H_

/*
 * Pinbelegung für des LCDs am Atmel
 * Alle LCD Pins müssen an einem Port angeschlossen sein und die 4
 * Datenleitungen müssen auf aufeinanderfolgenden Pins liegen
 */

/**
 * Port, an dem das LCD-Display angeschlossen ist
 */
#define LCD_PORT      PORTB

/**
 * Daten-Richtungs-Register, an dem das LCD-Display angeschlossen ist
 */
#define LCD_DDR       DDRB

/**
 * Erster Pin der Datenletungen des LCD-Displays
 *
 * Die anderen 3 Pins müssen an den beiden darauffolgenden Pins
 * des Controllers angeschlossen werden
 */
#define LCD_DB        PB0

/**
 * Register-Select-Pin des LCD-Displays
 */
#define LCD_RS        PB4

/**
 * Enable-Pin des LCD-Displays
 */
#define LCD_EN        PB5

/*
 * LCD Ausführungszeiten (MS=Millisekunden, US=Mikrosekunden)
 */

#define LCD_BOOTUP_MS           15
#define LCD_ENABLE_US           20
#define LCD_WRITEDATA_US        46
#define LCD_COMMAND_US          42

#define LCD_SOFT_RESET_MS1      5
#define LCD_SOFT_RESET_MS2      1
#define LCD_SOFT_RESET_MS3      1
#define LCD_SET_4BITMODE_MS     5

#define LCD_CLEAR_DISPLAY_MS    2
#define LCD_CURSOR_HOME_MS      2

/*
 * Zeilendefinitionen des verwendeten LCD
 * Die Einträge hier sollten für LCDs mit Zeilenlängen von 16-20 Zeichen passen
 * Bei anderen Zeilenlängen müssen diese Einträge angepasst werden
 */

#define LCD_DDADR_LINE1         0x00
#define LCD_DDADR_LINE2         0x40
#define LCD_DDADR_LINE3         0x14
#define LCD_DDADR_LINE4         0x54

/**
 * Initialisierungs-Sequenz des LCD-Displays
 */
void lcd_init(void);

/**
 * Sendet den Befehl zur Löschung des Displays
 */
void lcd_clear(void);

/**
 * Sendet den Befehl: Cursor Home
 */
void lcd_home(void);

/**
 * Setzt den Cursor in Spalte x (0..15) Zeile y (0..3)
 */
void lcd_setcursor(uint8_t spalte, uint8_t zeile);

/**
 * Ausgabe eines einzelnen Zeichens an der aktuellen Cursorposition
 */
void lcd_data(uint8_t data);

/**
 * Ausgabe eines Strings an der aktuellen Cursorposition
 */
void lcd_string(const char *data);

/**
 * Ausgabe eines Strings aus dem Flash an der aktuellen Cursorposition
 */
void lcd_pstring(const char *data);

/**
 * Ausgabe von einer Anzahl Leerzeichen
 */
void lcd_space(uint8_t n);

/**
 * Ausgabe einer Zahl vom Typ int8_t als Text
 */
void lcd_int8(int8_t n);

/**
 * Ausgabe einer Zahl vom Typ uint8_t als Text
 */
void lcd_uint8(uint8_t n);

/**
 * Ausgabe einer Zahl vom Typ uint8_t als Hex-Text
 */
void lcd_uint8_hex(uint8_t n);

/**
 * Ausgabe einer Zahl vom Typ int16_t als Text
 */
void lcd_int16(int16_t n);

/**
 * Ausgabe einer Zahl vom Typ uint16_t als Text
 */
void lcd_uint16(uint16_t n);

/**
 * Ausgabe einer Zahl vom Typ int32_t als Text
 */
void lcd_int32(int32_t n);

/**
 * Ausgabe einer Zahl vom Typ uint32_t als Text
 */
void lcd_uint32(uint32_t n);

/**
 * Definition eines benutzerdefinierten Sonderzeichens.
 *
 * data muss auf ein Array[5] mit den Spaltencodes des zu definierenden Zeichens
 * zeigen
 */
void lcd_generatechar(uint8_t code, const uint8_t *data);

/**
 * Ausgabe eines Kommandos an das LCD
 */
void lcd_command(uint8_t data);


/*
 * LCD Befehle und Argumente
 *
 * Zur Verwendung mit lcd_command
 */

/*
 * Clear Display -------------- 0b00000001
 */
#define LCD_CLEAR_DISPLAY       0x01

/*
 * Cursor Home ---------------- 0b0000001x
 */
#define LCD_CURSOR_HOME         0x02

/*
 * Set Entry Mode ------------- 0b000001xx
 */
#define LCD_SET_ENTRY           0x04

#define LCD_ENTRY_DECREASE      0x00
#define LCD_ENTRY_INCREASE      0x02
#define LCD_ENTRY_NOSHIFT       0x00
#define LCD_ENTRY_SHIFT         0x01

/*
 * Set Display ---------------- 0b00001xxx
 */
#define LCD_SET_DISPLAY         0x08

#define LCD_DISPLAY_OFF         0x00
#define LCD_DISPLAY_ON          0x04
#define LCD_CURSOR_OFF          0x00
#define LCD_CURSOR_ON           0x02
#define LCD_BLINKING_OFF        0x00
#define LCD_BLINKING_ON         0x01

/*
 * Set Shift ------------------ 0b0001xxxx
 */
#define LCD_SET_SHIFT           0x10

#define LCD_CURSOR_MOVE         0x00
#define LCD_DISPLAY_SHIFT       0x08
#define LCD_SHIFT_LEFT          0x00
#define LCD_SHIFT_RIGHT         0x04

/*
 * Set Function --------------- 0b001xxxxx
 */
#define LCD_SET_FUNCTION        0x20

#define LCD_FUNCTION_4BIT       0x00
#define LCD_FUNCTION_8BIT       0x10
#define LCD_FUNCTION_1LINE      0x00
#define LCD_FUNCTION_2LINE      0x08
#define LCD_FUNCTION_5X7        0x00
#define LCD_FUNCTION_5X10       0x04

#define LCD_SOFT_RESET          0x30

/*
 * Set CG RAM Address --------- 0b01xxxxxx  (Character Generator RAM)
 */
#define LCD_SET_CGADR           0x40

#define LCD_GC_CHAR0            0
#define LCD_GC_CHAR1            1
#define LCD_GC_CHAR2            2
#define LCD_GC_CHAR3            3
#define LCD_GC_CHAR4            4
#define LCD_GC_CHAR5            5
#define LCD_GC_CHAR6            6
#define LCD_GC_CHAR7            7

/*
 * Set DD RAM Address --------- 0b1xxxxxxx  (Display Data RAM)
 */
#define LCD_SET_DDADR           0x80

#endif // LCD_H_
