/**
 * Ansteuerung eines HD44780 kompatiblen LCD im 4-Bit-Interfacemodus
 *
 * http://www.mikrocontroller.net/articles/HD44780
 * http://www.mikrocontroller.net/articles/AVR-GCC-Tutorial/LCD-Ansteuerung
 * http://www.reichelt.de/?ARTICLE=31652
 *
 * Die Pinbelegung ist über defines in lcd.h einstellbar
 */

#include <stdlib.h>
#include <avr/io.h>
#include <util/delay.h>
#include <avr/pgmspace.h>
#include "lcd.h"

/**
 * Erzeugt einen Enable-Puls
 */
static void lcd_enable(void)
{
	// Enable auf 1 setzen
	LCD_PORT |= (1<<LCD_EN);
	
	// kurze Pause
	_delay_us(LCD_ENABLE_US);
	
	// Enable auf 0 setzen
	LCD_PORT &= ~(1<<LCD_EN);
}

/**
 * Sendet eine 4-bit Ausgabeoperation an das LCD
 */
static void lcd_out(uint8_t data)
{
	// obere 4 Bit maskieren
	data &= 0xF0;
	
	// Maske löschen
	LCD_PORT &= ~(0xF0>>(4-LCD_DB));
	
	// Bits setzen
	LCD_PORT |= (data>>(4-LCD_DB));
	
	// Enable-Puls senden
	lcd_enable();
}

/**
 * Initialisierungs-Sequenz des LCD-Displays
 */
void lcd_init()
{
	// verwendete Pins auf Ausgang schalten
	uint8_t pins = 
		// 4 Datenleitungen
		(0x0F << LCD_DB) |
		
		// R/S Leitung
		(1<<LCD_RS) |
		
		// Enable Leitung
		(1<<LCD_EN);
	
	LCD_DDR |= pins;
	
	// initial alle Ausgänge auf Null
	LCD_PORT &= ~pins;
	
	// warten auf die Bereitschaft des LCD
	_delay_ms(LCD_BOOTUP_MS);
	
	// Soft-Reset muss 3mal hintereinander gesendet werden zur Initialisierung
	lcd_out(LCD_SOFT_RESET);
	_delay_ms(LCD_SOFT_RESET_MS1);
	
	lcd_enable();
	_delay_ms(LCD_SOFT_RESET_MS2);
	
	lcd_enable();
	_delay_ms(LCD_SOFT_RESET_MS3);
	
	// 4-bit Modus aktivieren 
	lcd_out(
		LCD_SET_FUNCTION |
		LCD_FUNCTION_4BIT
	);
	_delay_ms(LCD_SET_4BITMODE_MS);
	
	// 4-bit Modus / 2 Zeilen / 5x7
	lcd_command(
		LCD_SET_FUNCTION |
		LCD_FUNCTION_4BIT |
		LCD_FUNCTION_2LINE |
		LCD_FUNCTION_5X7
	);
	
	// Display ein / Cursor aus / Blinken aus
	lcd_command(
		LCD_SET_DISPLAY |
		LCD_DISPLAY_ON |
		LCD_CURSOR_OFF |
		LCD_BLINKING_OFF
	);
	
	// Cursor inkrement / kein Scrollen
	lcd_command(
		LCD_SET_ENTRY |
		LCD_ENTRY_INCREASE |
		LCD_ENTRY_NOSHIFT
	);
	
	// Display leeren
	lcd_clear();
}

/**
 * Sendet ein Datenbyte an das LCD
 */
void lcd_data(uint8_t data)
{
	// RS auf 1 setzen
	LCD_PORT |= (1<<LCD_RS);
	
	// zuerst die oberen 4 Bit senden
	lcd_out(data);
	
	// dann die unteren 4 Bit
	lcd_out(data<<4);
	
	// Dem Display Zeit zum Verarbeiten geben
	_delay_us(LCD_WRITEDATA_US);
}

/**
 * Sendet einen Befehl an das LCD
 */
void lcd_command(uint8_t data)
{
	// RS auf 0 setzen
	LCD_PORT &= ~(1<<LCD_RS);
	
	// zuerst die oberen 4 Bit senden
	lcd_out(data);
	
	// dann die unteren 4 Bit
	lcd_out(data<<4);
	
	// Dem Display Zeit zum Verarbeiten geben
	_delay_us(LCD_COMMAND_US);
}

/**
 * Sendet den Befehl zur Löschung des Displays
 */
void lcd_clear()
{
	// Kommandobyte senden
	lcd_command(LCD_CLEAR_DISPLAY);
	
	// Dem Display Zeit zum Verarbeiten geben
	_delay_ms( LCD_CLEAR_DISPLAY_MS );
}

/**
 * Sendet den Befehl: Cursor Home
 */
void lcd_home()
{
	// Kommandobyte senden
	lcd_command( LCD_CURSOR_HOME );
	
	// Dem Display Zeit zum Verarbeiten geben
	_delay_ms( LCD_CURSOR_HOME_MS );
}

/**
 * Setzt den Cursor in Spalte x (0..15) Zeile y (0..3)
 */

void lcd_setcursor(uint8_t x, uint8_t y)
{
	// Zeile auswählen
	switch (y)
	{
		// 1. Zeile
		case 0:
			lcd_command(LCD_SET_DDADR + LCD_DDADR_LINE1 + x);
			break;
			
		// 2. Zeile
		case 1:
			lcd_command(LCD_SET_DDADR + LCD_DDADR_LINE2 + x);
			break;
			
		// 3. Zeile
		case 2:
			lcd_command(LCD_SET_DDADR + LCD_DDADR_LINE3 + x);
			break;
			
		// 4. Zeile
		case 3:
			lcd_command(LCD_SET_DDADR + LCD_DDADR_LINE4 + x);
			break;
			
		// Ungültige Zeilenangabe
		default:
			return;
	}
}

/**
 * Schreibt einen String auf das LCD
 */
void lcd_string(const char *data)
{
	// Byteweise durch den String laufen, das Null-Byte ignorieren
	while(*data != '\0')
		lcd_data(*data++);
}

/**
 * Schreibt einen String aus dem Flash auf das LCD
 */
void lcd_pstring(const char *pdata)
{
	// Byteweise durch den String laufen, das Null-Byte ignorieren
	char c;
	while((c = pgm_read_byte(pdata++)))
	{
		lcd_data(c);
	}
}


/**
 * Ausgabe von einer Anzahl Leerzeichen
 */
void lcd_space(uint8_t n)
{
	for(; n != 0; n--)
		lcd_data(' ');
}

void lcd_int8(int8_t n)
{
	// from -127 up to 128
	char s[5];
	itoa(n, s, 10);
	lcd_string(s);
}

void lcd_uint8(uint8_t n)
{
	// from 0 up to 255
	char s[4];
	utoa(n, s, 10);
	lcd_string(s);
}

void lcd_int16(int16_t n)
{
	// from -32768 up to 32767
	char s[7];
	itoa(n, s, 10);
	lcd_string(s);
}

void lcd_uint16(uint16_t n)
{
	// from 0 up to 65535
	char s[6];
	utoa(n, s, 10);
	lcd_string(s);
}

void lcd_int32(int32_t n)
{
	// from -2147483648 up to 2147483647
	char s[12];
	ltoa(n, s, 10);
	lcd_string(s);
}

void lcd_uint32(uint32_t n)
{
	// from 0 up to 4294967295
	char s[11];
	ultoa(n, s, 10);
	lcd_string(s);
}

/**
 * Schreibt ein Zeichen in den Character Generator RAM
 */
void lcd_generatechar(uint8_t code, const uint8_t *data)
{
	// Startposition des Zeichens einstellen
	lcd_command(LCD_SET_CGADR | (code<<3));
	
	// Bitmuster übertragen
	for(uint8_t i=0; i<8; i++)
		lcd_data(data[i]);
}
