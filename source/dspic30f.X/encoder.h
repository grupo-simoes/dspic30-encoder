/* 
 * File:   encoder.h
 * Author: eduardo
 *
 * Created on December 2, 2016, 12:05 PM
 */

#ifndef ENCODER_H
#define	ENCODER_H

#ifdef	__cplusplus
extern "C" {
#endif

    void initEncoder();
    void stopEncoder();
    unsigned int readEncoder();

#ifdef	__cplusplus
}
#endif

#endif	/* ENCODER_H */

