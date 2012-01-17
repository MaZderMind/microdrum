# MicroDrum - Parameter-Board
Dieser Ordner enthält Schemazeichnung und Platinenlayouts für die Parameter-Boards. Ein solches Board ist mit je 16 Drehpotentiometern bestückt und bietet dem Nutzer die Möglichkeit, die Klang-Parameter der einzelnen Instrumente zu konfigurieren. Es liegt auch eine ältere Boardversion mit nur 8 Potis vor.

## Aufbau
Damit der Atmel so viele analoge Signale (8×4 = 32) überhaupt verarbeiten kann, kommen [74HC4051](http://www.datasheetcatalog.org/datasheet/philips/74HC4051.pdf) 8-Kanal Analog Multiplexer/Demultiplexer zum Einsatz. Bei diesen Bauteilen wird mit 3 digitalen Leitungen einer der 8 Eingangspins gewählt, welcher dann mit dem Ausgangsport verbunden wird.

Wir verwenden 4 solcher ICs, deren Auswahlports jeweils verbunden sind, um mit 3 digitalen und 4 analogen Eingängen an der MCU alle 32 Potis messen zu können.
