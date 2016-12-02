#include <p30F1010.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"

void initSistema()
{
  PORTA = 0x00;
  PORTB = 0x00;  
  PORTD = 0x00;
  
  LATA = 0x00;
  LATB = 0x00;  
  LATD = 0x00;  
}