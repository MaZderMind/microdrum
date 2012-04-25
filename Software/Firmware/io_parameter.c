#include<stdint.h>
#include<avr/io.h>

#include"io_parameter.h"

uint8_tparameter[N_PARAMETERS];

struct{
uint8_tmapping;
uint8_tinvert;
}parameter_map[N_PARAMETERS]={
{7,0},
{6,0},
{5,0},
{3,1},
{0,1},
{2,1},
{4,0},
{1,1},

{14,0},
{13,0},
{12,0},
{15,0},
{8,1},
{11,1},
{9,1},
{10,1},
};


voidio_parameter_init()
{
//ADCaktivieren,Prescalerauf64
ADCSRA|=(1<<ADEN)|(1<<ADPS2)|(1<<ADPS1);

//interne2,56ValsReferenz
ADMUX|=(1<<REFS0)|(1<<REFS1);
}

uint8_tio_parameter_read(uint8_tchain)
{
//MUX-Registeraufnullen
ADMUX&=~((1<<MUX0)|(1<<MUX1)|(1<<MUX2)|(1<<MUX3));

//4BitsvonchainnehmenundnachMUX0schieben,sodasssieaufMUX0-MUX3abgebildetwerden
ADMUX|=(chain&0b1111)<<MUX0;

//Wandlungstarten
ADCSRA|=(1<<ADSC);

//aufAbschlussderKonvertierungwarten
while(ADCSRA&(1<<ADSC));

//Wertlesenundwegwerfen
uint16_ttemp=ADCW;

temp=0;
uint8_tn=4;
for(uint8_ti=0;i<n;i++)
{
//Wandlungstarten
ADCSRA|=(1<<ADSC);

//aufAbschlussderKonvertierungwarten
while(ADCSRA&(1<<ADSC));

//Wertlesenundaddieren
temp+=ADCW;
}

return(temp/n)>>2;
}

voidio_parameter_sync(uint8_tcycle)
{
uint8_tn,v;

//firstchipoffirstparameterboard
n=parameter_map[cycle].mapping;
v=io_parameter_read(0);

if(parameter_map[cycle].invert)
v=255-v;

parameter[n]=v;

//firstchipoffirstparameterboard
n=parameter_map[cycle+8].mapping;
v=io_parameter_read(1);

if(parameter_map[cycle+8].invert)
v=255-v;

parameter[n]=v;
}
