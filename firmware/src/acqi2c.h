/* 
 * File:   acqi2c.h
 * Author: Damien
 *
 * Created on January 7, 2019, 12:03 PM
 */

#ifndef ACQI2C_H
#define	ACQI2C_H

#ifdef	__cplusplus
extern "C" {
#endif

unsigned char acqRead(unsigned char addr, unsigned char cmd, unsigned char * buf, unsigned int len) ;
unsigned char acqSend(unsigned char addr, unsigned char cmd, unsigned char * data, unsigned int len) ;



#ifdef	__cplusplus
}
#endif

#endif	/* ACQI2C_H */

