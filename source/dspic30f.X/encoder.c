#include <p30F4011.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"
#include "encoder.h"

void initEncoder()
{
  QEICONbits.QEIM = 0; // Disable QEI Module
  QEICONbits.CNTERR = 0; // Clear any count errors
  QEICONbits.QEISIDL = 0; // Continue operation during sleep
  QEICONbits.SWPAB = 0; // QEA and QEB not swapped
  QEICONbits.PCDOUT = 0; // Normal I/O pin operation
  QEICONbits.POSRES = 1; // Index pulse resets position counter
  DFLTCONbits.CEID = 1; // Count error interrupts disabled
  DFLTCONbits.QEOUT = 1; // Digital filters output enabled for QEn pins
  DFLTCONbits.QECK = 5; // 1:64 clock divide for digital filter for QEn
  //DFLTCONbits.INDOUT = 1; // Digital filter output enabled for Index pin
  //DFLTCONbits.INDCK = 5; // 1:64 clock divide for digital filter for Index
  POSCNT = 0; // Reset position counter
  QEICONbits.QEIM = 5; // X2 mode with position counter reset by MAXCNT
  
}

void stopEncoder()
{
  QEICONbits.QEIM = 0; // Disable QEI Module
}

unsigned int readEncoder()
{
  return POSCNT;
}
