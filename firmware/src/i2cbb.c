

#include "i2cbb.h"
#include "hardwareProfile.h"


#include <xc.h>
#include <p32xxxx.h>
#include <sys/attribs.h>
#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>





/* Buffer for I2C reception */
uint8_t RX_BUFFER_I2C2[6];

/* Buffer for I2C transmission */
uint8_t TX_BUFFER_I2C3[5];



/*Local functions at module*/
/********************************************************************************/
/********************************************************************************/
void I2C__P_StartCondition(void);
void I2C__P_ReStartCondition(void);
uint8_t I2C__P_SendByte(uint8_t Byte);
uint8_t I2C__P_GetACK(void);
void I2C__P_StopCondition(void);
void I2C__P_Clock(void);
uint8_t I2C__P_GetByte(void);
void I2C__P_SendACK(void);
void I2C__P_NACK(void);

void __delay_us(uint32_t delay_us) ;

volatile int * SCLReg =  &LATB;
int SCLMask = 1 << 11;

void setI2CSCLPin(volatile int * reg, int pin)
{
    SCLReg = reg;
    SCLMask = 1 << pin;
}
inline void setSCLHigh()
{
    *SCLReg |= SCLMask;
}
inline void setSCLLow()
{
    *SCLReg &= ~SCLMask;
}


void I2C__P_StartCondition(void) {
    SDA_INPUT = 0;
    /*Pull down de data signal*/
    SDADir = I2CLOW;
    
    /*Delay to give it time to settle*/
    __delay_us(1);

    /*Pull down the clock signal*/
    setSCLLow();
}/* void I2C__P_StartCondition(void) */

void I2C__P_ReStartCondition(void) {

    /* Pull up data line */
    SDADir = I2CHIGH;

    /* Give it time to settle */
    __delay_us(1);

    /* Pull up clock line */
    setSCLHigh();

    /* Give it time to settle */
    __delay_us(1);

    /* Pull down data line */
    SDADir = I2CLOW;

    /* Give it time to settle */
    __delay_us(1);

    /* Pull up clock line */
    setSCLLow();

} /* void I2C__p_ReStartCondition(void) */

uint8_t I2C__P_SendByte(uint8_t Byte) {
    uint8_t count;



    /* Loop used for sending eight bits, one at a time */
    for (count = 0; count < 8; count++) {
        /* If the byte received is 0 holds the SDA signal down */
        if ((Byte & 0x80) == 0) {
            SDADir = I2CLOW;
        }/* Else release the line so data can be received */
        else {
            SDADir = I2CHIGH;
        }
        /* Saves the data in the variable and shifts next bit into position */
        Byte = Byte << 1;
        /* Delay and clock pulse to ensure the data reception */
        __delay_us(1);
        I2C__P_Clock();
    }
    /* Release data line for ACK */
    SDADir = I2CHIGH;
    return (1);
}


uint8_t I2C__P_GetACK(void) {

    /* Samples SDA LAT */
    if (SDAOut == 1) {
        /*If 1, return NACK*/
        return (0);
    } else {
        /* Else, pulses de clock and returns ACK */
        I2C__P_Clock();
        __delay_us(1); //-- Minimum Clock Low Time
    }

    return (1);

} /* uint8_t I2C__P_GetACK(void) */


void I2C__P_StopCondition(void) {


    /* Pull down SDA line */
    SDADir = I2CLOW;
    /* Pull down SCL line */
    setSCLLow();
    /* Give it time to settle */
    __delay_us(1);
    /* Releases SCL line */
    setSCLHigh();
    /* Give it time to settle */
    __delay_us(1);
    /* Releases SDA line */
    SDADir = I2CHIGH;

} /* void I2C__P_StopRoutine(void) */


void I2C__P_Clock(void) {
    /* Delay to avoid signals to bed mixed*/
    __delay_us(1);
    /* Pulls up SCL line */
    setSCLHigh();
    /* Give it time to settle */
    __delay_us(2);
    /* Pulls down SCL line */
    setSCLLow();
    /* Give it time to settle */
    __delay_us(1);

} /* void I2C__P_Clock(void)*/


extern uint8_t DRIVERI2C3__F_readMemI2C3(uint8_t lAddressI2C, uint8_t lMemAdd, uint8_t lBytesNumber, uint8_t * pStartBytes) {

    uint8_t lIndex;

    /* Generates start condition */
    I2C__P_StartCondition();

    /* Sends expander address, shifting 1 bit into position */
    I2C__P_SendByte(lAddressI2C << 1);
    
    /* Checks if ACK is received */
    if (I2C__P_GetACK() == 0) {
        /* If not, stops communication and return 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }

    /* Sends lMemAdd to access the data bank to be read */
    I2C__P_SendByte(lMemAdd);

    /* Checks if ACK is received */
    if (I2C__P_GetACK() == 0) {
        /* If not, stops communication and return 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }

    /*Begins reading*/


    /* Restarts I2C to begin the reading */
    I2C__P_ReStartCondition();

    /* Sends expander addres, shifting 1 bit into position and does an OR with 1 bit to enable reading */
    I2C__P_SendByte((lAddressI2C << 1) | (0x01));

    /* Checks if ACK is received */
    if (I2C__P_GetACK() == 0) {
        /* If not, stops communication and return 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }

    /* Generates a reverse counting loop to send lBytesNumber bytes*/
    for (lIndex = 0; lIndex < lBytesNumber; lIndex++) {
        /* Equals the RX_BUFFER_I2C2[5] to the bytes received in I2C__P_GetByte(); function */
        pStartBytes[lIndex] = I2C__P_GetByte();

        /* While the lIndex countig is below lBytesNumber - 1 sends ACK for each byte received */
        if (lIndex < (lBytesNumber - 1)) {
            /* Forces and ACK if the condition is fulfilled */
            I2C__P_SendACK();
        }            /* Else sends NACK */
        else {
            /* Forces NACK if else */
            I2C__P_NACK();
        }
    }

    /* Stops communitacion after the reading is completed */
    I2C__P_StopCondition();

    return (1);

} /* uint8_t I2C__P_ReadIOExpander(uint8_t lAddressI2C,uint8_t lMemAdd, uint8_t lBytesNumber, uint8_t * pStartBytes) */


uint8_t I2C__P_GetByte(void) {

    int8_t count;

    uint8_t Byte = 0;

    /* Releases SDA line to allow the bytes to be read */
    SDADir = I2CHIGH;

    /* Initiares a loop to read 8 bits */
    for (count = 0; count < 8; count++) {
        /* Equals the Byte variable to Byte OR data held in SDA port. ****fs the the next bits into position as the counting goes on */
        Byte = Byte | (SDA_INPUT << (7 - count)); //-- Shift next bit into position

        /* Delay and clock pulse to ensure the data reception */
        __delay_us(1);
        I2C__P_Clock(); //-- Pulse the clock 
    }
    /* Returns the data held in Byte variable to be used in I2C__P_ReadIOExpander function */
    return (Byte);

} /* I2C__P_GetByte */


void I2C__P_SendACK(void) {

    /* Pulls down SDA, generating ACK */
    SDADir = I2CLOW;

    /* Give it time to settle */
    __delay_us(1);

    /* Pulse the clock */
    I2C__P_Clock();

    /* Release SDA */
    SDADir = I2CHIGH;

    /* Give it time to settle */
    __delay_us(1);

} /* void I2C__P_SendACK(void) */


void I2C__P_NACK(void) {


    /* Release SDA*/
    SDADir = I2CHIGH;

    /* Give it time to settle */
    __delay_us(1);

    /* Pulse the clock */
    I2C__P_Clock();

    /* Pulls down SDA, genrating ACK */
    SDADir = I2CLOW;

    /* Give it time to settle */
    __delay_us(1);

} /* void I2C__P_NACK(void) */


void __delay_us(uint32_t delay_us) 
{
    /* Variable to calculate the delay in microseconds */

    int i=0; 
    for (i=0; i<delay_us*400; i++) Nop();
    
    return;
//    delayUs(delay_us);
    /*
    uint32_t DelayStartTime;

    DelayStartTime = ReadCoreTimer();
    while ((ReadCoreTimer() - DelayStartTime) < (delay_us * CORE_TIMER_MICROSECONDS)); */
}
