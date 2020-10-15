
#include "AdcAcq.h"
#include <xc.h>
#include "hardwareProfile.h"


void selectCS(char id, char state);

void initSPI3AdcAcq(void)
{
    IEC6bits.SPI3EIE = 0;       // SPI interrupts disabled
    IEC6bits.SPI3RXIE = 0;
    IEC6bits.SPI3TXIE = 0;
     
    SPI3CONbits.ON = 0;         // Turn off SPI module
     
 
    SPI3BRG = 30;                // FSCK 
     
    SPI3STATbits.SPIROV = 0;    // Clear overflow flag
     
    /* SPI1CON settings */
    SPI3CONbits.FRMEN = 0;      // Framed SPI support is disabled
    SPI3CONbits.SIDL = 0;       // Continue operation in IDLE mode
    SPI3CONbits.DISSDO = 0;     // SDO1 pin is controlled by the module
    SPI3CONbits.MODE16 = 1;     // 16 bit mode
    SPI3CONbits.MODE32 = 0;
    SPI3CONbits.CKP = 0;        // Idle state for clock is low, active state is high
    SPI3CONbits.CKE = 0;        // Output data changes on transition from active to idle
    SPI3CONbits.SSEN = 0;       // Not in slave mode
    SPI3CONbits.MSTEN = 1;      // Master mode
    SPI3CONbits.SMP = 1;        // Input data sampled at the end of data output time
     
    SPI3CONbits.ON = 1;         // Turn module on
}


void initSPI4AdcAcq(void)
{
    IEC6bits.SPI4EIE = 0;       // SPI interrupts disabled
    IEC6bits.SPI4RXIE = 0;
    IEC6bits.SPI4TXIE = 0;
     
    SPI4CONbits.ON = 0;         // Turn off SPI module
     

    SPI4BRG = 30;                // FSCK 
     
    SPI4STATbits.SPIROV = 0;    // Clear overflow flag
     
    /* SPI1CON settings */
    SPI4CONbits.FRMEN = 0;      // Framed SPI support is disabled
    SPI4CONbits.SIDL = 0;       // Continue operation in IDLE mode
    SPI4CONbits.DISSDO = 0;     // SDO1 pin is controlled by the module
    SPI4CONbits.MODE16 = 1;     // 16 bit mode
    SPI4CONbits.MODE32 = 0;
    SPI4CONbits.CKP = 0;        // Idle state for clock is low, active state is high
    SPI4CONbits.CKE = 0;        // Output data changes on transition from active to idle
    SPI4CONbits.SSEN = 0;       // Not in slave mode
    SPI4CONbits.MSTEN = 1;      // Master mode
    SPI4CONbits.SMP = 1;        // Input data sampled at the end of data output time
     
    SPI4CONbits.ON = 1;         // Turn module on
}

void initSpi()
{
    initSPI3AdcAcq();
    initSPI4AdcAcq();
}
unsigned short SPI4WR(unsigned short val)
{
    SPI4BUF = val;                    // Write to buffer for transmission
    while (!SPI4STATbits.SPIRBF);    // Wait for transfer to be completed
    val = SPI4BUF;
    return val;
}
unsigned short SPI3WR(unsigned short val)
{
    SPI3BUF = val;                    // Write to buffer for transmission
    while (!SPI3STATbits.SPIRBF);    // Wait for transfer to be completed
    val = SPI3BUF;
    return val;
}


unsigned short readAdcAcq(char id)
{
    volatile unsigned short temp =0 ;

    
    selectCS(id, 0);
    if ((id >=8) && (id <= 14))
        temp = SPI3WR(0x0000);
    else
        temp = SPI4WR(0x0000);
    
    selectCS(id, 1);
    return temp; 
}

void selectCS(char id, char state)
{
    if (state)
    {
        switch (id)
        {
            case 3: CS_1 = 1; break;
            case 2: CS_2 = 1; break;
            case 1: CS_3 = 1; break;
            case 4: CS_4 = 1; break;
            case 5: CS_5 = 1; break;
            case 6: CS_6 = 1; break;
            case 7: CS_7 = 1; break;
            case 8: CS_8 = 1; break;
            case 9: CS_9 = 1; break;
            case 10: CS_10= 1; break;
            case 11: CS_11= 1; break;
            case 12: CS_12= 1; break;
            case 13: CS_13= 1; break;
            case 14: CS_14= 1; break;
            case 15: CS_15= 1; break;
        }
    } else {
        switch (id)
        {
            case 3: CS_1 = 0; break;
            case 2: CS_2 = 0; break;
            case 1: CS_3 = 0; break;
            case 4: CS_4 = 0; break;
            case 5: CS_5 = 0; break;
            case 6: CS_6 = 0; break;
            case 7: CS_7 = 0; break;
            case 8: CS_8 = 0; break;
            case 9: CS_9 = 0; break;
            case 10: CS_10= 0; break;
            case 11: CS_11= 0; break;
            case 12: CS_12= 0; break;
            case 13: CS_13= 0; break;
            case 14: CS_14= 0; break;
            case 15: CS_15= 0; break;
        }
    }
}


