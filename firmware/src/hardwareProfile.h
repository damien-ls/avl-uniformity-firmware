/* 
 * File:   hardwareProfile.h
 * Author: Damien
 *
 * Created on October 30, 2018, 7:03 PM
 */

#ifndef HARDWAREPROFILE_H
#define	HARDWAREPROFILE_H

#ifdef	__cplusplus
extern "C" {
#endif
    
#define CS_1 PORTAbits.RA10
#define CS_2 PORTBbits.RB13
#define CS_3 PORTBbits.RB12
#define CS_4 PORTGbits.RG13
#define CS_5 PORTGbits.RG12
#define CS_6 PORTGbits.RG14
#define CS_7 PORTBbits.RB11
#define CS_8 PORTBbits.RB10
#define CS_9 PORTFbits.RF7
#define CS_10 PORTFbits.RF6
#define CS_11 PORTGbits.RG0
#define CS_12 PORTGbits.RG1
#define CS_13 PORTFbits.RF1
#define CS_14 PORTFbits.RF0
#define CS_15 PORTGbits.RG10
    
#define CS1_T TRISAbits.TRISA10
#define CS2_T TRISBbits.TRISB13
#define CS3_T TRISBbits.TRISB12
#define CS4_T TRISGbits.TRISG13
#define CS5_T TRISGbits.TRISG12
#define CS6_T TRISGbits.TRISG14
#define CS7_T TRISBbits.TRISB11
#define CS8_T TRISBbits.TRISB10
#define CS9_T TRISFbits.TRISF7
#define CS10_T TRISFbits.TRISF6
#define CS11_T TRISGbits.TRISG0
#define CS12_T TRISGbits.TRISG1
#define CS13_T TRISFbits.TRISF1
#define CS14_T TRISFbits.TRISF0
#define CS15_T TRISGbits.TRISG10
    

#define IO_LED PORTDbits.RD13

#define IO_ADC_CNV PORTFbits.RF12
#define IO_ADC_CNV_T TRISFbits.TRISF12
    
#define WDTClr() WDTCONbits.WDTCLRKEY = 0x5743
#define WDTEn() WDTCONSET = 0x8000
#define WDTDis() WDTCONCLR = 0x8000
    
#ifdef	__cplusplus
}
#endif

#endif	/* HARDWAREPROFILE_H */

