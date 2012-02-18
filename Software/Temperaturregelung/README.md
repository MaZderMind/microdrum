# Temperaturregelung für Laminator
Dies ist die Software des ATtiny13, welcher für die Temperaturregelung des Laminators verwendet wurde, mit welchem die Platinen des Drumcomputers hergestellt wurden.
Wichtig ist, dass der ATtiny13 auf 4.8 MHz internen Resonator gestellt wird, da sonst die timings für den Software-UART zu ungenau sind. Gegebenenfalls muss ein externer Quarzoszialtor verwendet werden.
Mehr Infos über den Aufbau des Gerätes können im [Blog](http://microdrum.wordpress.com/2012/02/17/platinen-herstellen/) gefunden werden, die ursprüngliche Idee und Umsetzung stammt von [Thomas Pfeifer](http://thomaspfeifer.net/laminator_temperatur_regelung.htm).
