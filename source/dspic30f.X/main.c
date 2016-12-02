/* 
 * File:   main.c
 * Author: eduardo
 *
 * Created on December 2, 2016, 11:32 AM
 */
#include <p30F4011.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"
#include "uart.h"
#include "encoder.h"

// FOSC
#pragma config FPR = XT_PLL8            // Primary Oscillator Mode (XT w/PLL 8x)
#pragma config FOS = PRI                // Oscillator Source (Primary Oscillator)
#pragma config FCKSMEN = CSW_FSCM_OFF   // Clock Switching and Monitor (Sw Disabled, Mon Disabled)
// FWDT
#pragma config FWPSB = WDTPSB_16        // WDT Prescaler B (1:16)
#pragma config FWPSA = WDTPSA_512       // WDT Prescaler A (1:512)
#pragma config WDT = WDT_OFF            // Watchdog Timer (Disabled)
// FBORPOR
#pragma config FPWRT = PWRT_64          // POR Timer Value (64ms)
#pragma config BODENV = BORV20          // Brown Out Voltage (Reserved)
#pragma config BOREN = PBOR_ON          // PBOR Enable (Enabled)
#pragma config LPOL = PWMxL_ACT_LO      // Low-side PWM Output Polarity (Active Low)
#pragma config HPOL = PWMxH_ACT_LO      // High-side PWM Output Polarity (Active Low)
#pragma config PWMPIN = RST_IOPIN       // PWM Output Pin Reset (Control with PORT/TRIS regs)
#pragma config MCLRE = MCLR_EN          // Master Clear Enable (Enabled)
// FGS
#pragma config GWRP = GWRP_OFF          // General Code Segment Write Protect (Disabled)
#pragma config GCP = CODE_PROT_OFF      // General Segment Code Protection (Disabled)
// FICD
#pragma config ICS = ICS_PGD3           // Comm Channel Select (Use EMUC3 and EMUD3)


void __attribute__((interrupt, auto_psv)) _U1RXInterrupt(void)
{
  if (IFS0bits.U1RXIF && IEC0bits.U1RXIE)
  {
    IFS0bits.U1RXIF=0;
  }
}

int main (){
  initSistema ();
  initUART1 ();
  initEncoder ();
    
  char buffer[10];
  while(1)
    {
      sprintf (buffer,"%d\r",readEncoder ());
      sendStringUART1 (buffer);
    }
  
  return 0;
}