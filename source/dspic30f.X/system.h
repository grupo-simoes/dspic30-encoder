/* 
 * File:   system.h
 * Author: eduardo
 *
 * Created on December 2, 2016, 11:36 AM
 */

#ifndef SYSTEM_H
#define	SYSTEM_H

#ifdef	__cplusplus
extern "C" {
#endif
 
#define     FCY     20000000
#define     BORDA_SUBIDA        1
#define     BORDA_DESCIDA       0
    
#define     _LENTO_TRAS         PORTBbits.RB0
#define     _LENTO_FRENTE       PORTBbits.RB1
#define     _BALACIM_FACA       PORTBbits.RB2
#define     _ENC_Z              PORTBbits.RB3
#define     _ENC_A              PORTBbits.RB4
#define     _ENC_B              PORTBbits.RB5
#define     _FIM_DE_CURSO       PORTBbits.RB6
#define     _FREIO              PORTBbits.RB7
#define     _SENTIDO            PORTBbits.RB8
#define     _RAPIDO             PORTCbits.RC13  
#define     _LENTO              PORTCbits.RC14
#define     _BOTOEIRA_1         PORTDbits.RD0
#define     _BOTOERIA_2         PORTDbits.RD3
#define     _FOTO_CELULA        PORTEbits.RE8 
#define     _MOTOR_DO_AR        PORTDbits.RD3
#define     _AR                 PORTDbits.RD2
    
    void initSistema();
    void initIOS();
    void initINT0(char edge);
    void initINT1(char edge);
    void initINT2(char edge);

#ifdef	__cplusplus
}
#endif

#endif	/* SYSTEM_H */

