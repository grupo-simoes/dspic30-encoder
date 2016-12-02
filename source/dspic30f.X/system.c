#include <p30F4011.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"

void initSistema()
{
  initIOS ();
 
  // ALL PINS ARE DIGITAL
  ADPCFG = 0xFF;
  
  TRISBbits.TRISB0 = 1; /* LENTO/TRAS */
  TRISBbits.TRISB1 = 1; /* LENTO/FRENTE */
  TRISBbits.TRISB2 = 0; /* BALANCIM/FACA */
  TRISBbits.TRISB6 = 1; /* FIM DE CURSO */
  TRISBbits.TRISB7 = 0; /* FREIO */
  TRISBbits.TRISB8 = 0; /* SENTIDO */
  
  TRISCbits.TRISC13 =  0; /* RAPIDO */
  TRISCbits.TRISC14 =  0; /* LENTO */
  TRISEbits.TRISE8  =  1; /* FOTO CELULA */
  TRISDbits.TRISD1  =  1; /* BOTOERIA 2 */  
  TRISDbits.TRISD3  =  0; /* MOTO DO AR */
  TRISDbits.TRISD2  =  0; /* AR */
  TRISDbits.TRISD1  =  1; /* BOTOERIA 1 */
    
  initINT0 (BORDA_SUBIDA);
  initINT1 (BORDA_SUBIDA);
  initINT2 (BORDA_SUBIDA);
}

void initIOS()
{
  PORTB = 0x00;  
  PORTC = 0x00;
  PORTD = 0x00;
  PORTE = 0x00;
  PORTF = 0x00;
 
  LATB = 0x00;  
  LATC = 0x00;
  LATD = 0x00; 
  LATE = 0x00;
  LATF = 0x00; 
}

void initINT0(char edge)
{
  IEC0bits.INT0IE = 1;
  INTCON2bits.INT0EP = edge;
}

void initINT1(char edge)
{
  IEC1bits.INT1IE = 1;
  INTCON2bits.INT1EP = edge;  
}

void initINT2(char edge)
{
  IEC1bits.INT1IE = 1;
  INTCON2bits.INT2EP = edge;
}
