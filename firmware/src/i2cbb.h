/* 
 * File:   i2cbb.h
 * Author: Damien
 *
 * Created on July 2, 2018, 2:41 PM
 */

#ifndef I2CBB_H
#define	I2CBB_H

#ifdef	__cplusplus
extern "C" {
#endif

#include "hardwareProfile.h"

/* Definitions for 0 and 1 in 12C routines */

#define I2CLOW 0 /* Puts pin into output/low mode */
#define I2CHIGH 1 /* Puts pin into Input/high mode */


/* SDA and SCL TRIS directions */
#define SDADir TRISCbits.TRISC8
 
/* SDA and SCL LAT pins */
#define SDAOut LATCbits.LATC8
 
/* SDA and SCL PORT pins */
#define SDA_INPUT PORTCbits.RC8
    
void setI2CSCLPin(volatile int * reg, int pin);

#ifdef	__cplusplus
}
#endif

#endif	/* I2CBB_H */

