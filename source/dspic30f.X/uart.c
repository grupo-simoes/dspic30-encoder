#include <p30F4011.h>
#include <libpic30.h>
#include <stdio.h>
#include <stdlib.h>

#include "system.h"
#include "uart.h"

void initUART1()
{
    U1BRG = UBRGVALUE1; 
    U1STA &= 0xfffc;
    IEC0bits.U1RXIE = 1;
    U1MODEbits.UARTEN = 1;
    U1STAbits.UTXEN = 1;
}

void sendStringUART1(const char * string) 
{
    while (*string)
        sendByteUART1(*string++);
}

void sendByteUART1(unsigned int byte)
{
    U1TXREG = byte;
    
    while (!U1STAbits.TRMT);
}

unsigned char getByteUART1()
{
    return U1RXREG;
}