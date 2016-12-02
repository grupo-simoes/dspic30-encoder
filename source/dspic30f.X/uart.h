/* 
 * File:   uart.h
 * Author: eduardo
 *
 * Created on December 2, 2016, 11:49 AM
 */

#ifndef UART_H
#define	UART_H

#ifdef	__cplusplus
extern "C" {
#endif

#define UARTBAUD1 19200
#define UARTBAUD2 38400

#define UBRGVALUE1 (FCY/UARTBAUD1)/16 - 1
#define UBRGVALUE2 (FCY/UARTBAUD2)/16 - 1   
    
    void initUART1();
    void sendStringUART1(const char * string) ;
    void sendByteUART1(unsigned int byte);
    unsigned char getByteUART1();

#ifdef	__cplusplus
}
#endif

#endif	/* UART_H */

