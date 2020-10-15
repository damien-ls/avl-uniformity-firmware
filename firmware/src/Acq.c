
#include "Acq.h"
#include "AdcAcq.h"
#include <xc.h>
#include <stdint.h>
#include <stdbool.h>
#include <stddef.h>
#include <stdlib.h>
#include "system_config.h"
#include "system_definitions.h"
#include "hardwareProfile.h"

#define MAXACQSAMPLES 1000
unsigned short acqData[15][MAXACQSAMPLES];
unsigned short acqLast[15];
unsigned short triggerValue=46000;
unsigned char newMeasurement =0;
unsigned int acqBufPos=MAXACQSAMPLES;
unsigned int acqMaxPts=MAXACQSAMPLES;
unsigned short timingUs=200;
void initTimer6();

void setParam(unsigned short timUs, unsigned short nbpts, unsigned short trigValue)
{
    if (nbpts <= MAXACQSAMPLES)
        acqMaxPts = nbpts;
    timingUs = timUs;
    triggerValue= trigValue;
}
unsigned char hasNewMeasurement()
{
    char x = newMeasurement;
    newMeasurement=0;
    return x;
}
void initAcq()
{
    initSpi();
    initTimer6();
}
void initTimer6()
{
    T6CON = 0x0; // Stop the timer and clear the control register,
    // prescaler at 1:1,internal clock source
    TMR6 = 0x0; // Clear the timer register
    PR6 = 15*250; // Load the period register 1us
    T6CONbits.TCKPS = 0b011;
    
    IPC19bits.T6IP = 3;
    IPC19bits.T6IS = 1;
    
    IFS2bits.T6IF = 0;
    IEC2bits.T6IE = 1;
    
    T6CONbits.ON = 1;
}



void * acqCopyTo(unsigned char * buf, unsigned short start, unsigned char len)
{
    unsigned int i;
    for (i = 0; i<len; i++)
    {
        buf[i] = ((unsigned char*)acqData)[i+start];
    }
}

unsigned short * getAcqDataBuf()
{
    return acqData;
}


void acqTrig()
{
    acqBufPos = 0;
}

void acqDoMeas(unsigned int pts, unsigned int timingUs)
{
    if (pts <= MAXACQSAMPLES)
        acqMaxPts = pts;
    PR6 = timingUs*15;
    T6CONbits.ON = 1;
    acqBufPos = 0;
}

void __ISR(_TIMER_6_VECTOR,IPL3SOFT)Timer6Handler(void)
{
    IFS2bits.T6IF = 0;

    if (acqBufPos < acqMaxPts) 
    {
        IO_ADC_CNV =1;					// Enable chip select
        int i =0;
        for (i=0; i<15; i++)
        {
            unsigned short val =readAdcAcq(i+1);
            acqLast[i] = val;
            acqData[i][acqBufPos] = val;
        }
        acqBufPos++;
        if (acqBufPos == acqMaxPts) 
        {
            newMeasurement=1;
            PR6 = 250*15;
        }
        IO_ADC_CNV =0;					// Disable Chip Select
    } else {
        IO_ADC_CNV =1;
        unsigned short val = readAdcAcq(1);
        IO_ADC_CNV =0;
        if (triggerValue < val)
        {
            PR6 = timingUs*15;
            acqBufPos=0;
        } 
    }
}