#include <p30F4011.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"

void initSistema()
{
  PORTB = 0x00;  
  PORTD = 0x00;
 
  LATB = 0x00;  
  LATD = 0x00;  
}