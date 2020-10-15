
#include "acqi2c.h"
#include "i2cbb.h"

unsigned char acqRead(unsigned char addr, unsigned char cmd, unsigned char * buf, unsigned int len) 
{
    /* Generates start condition to initiate communication */
    I2C__P_StartCondition();

    /* Sends I/O expander address, shifting 1 bit into position */
    I2C__P_SendByte(addr << 1);

    /* Checks if ACK is received */
    if (!I2C__P_GetACK()) {
        /* If not, stops communication and returns 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }


    /* Sends the pointer to TX_BUFFER_I2C3[5] */
    I2C__P_SendByte(cmd);

    /* Checks if ACK is received */
    if (!I2C__P_GetACK()) {
        /* If not, stops communication and returns 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }
    
    __delay_us(5);
    
    /* Restarts I2C to begin the reading */
    I2C__P_ReStartCondition();
    
    
    /* Sends expander addres, shifting 1 bit into position and does an OR with 1 bit to enable reading */
    I2C__P_SendByte((addr << 1) | (0x01));

    __delay_us(10);
    /* Checks if ACK is received */
    if (I2C__P_GetACK() == 0) {
        /* If not, stops communication and return 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }

    /* Generates a reverse counting loop to send lBytesNumber bytes*/
    unsigned int i;
    for (i = 0; i < len; i++) {
        /* Equals the RX_BUFFER_I2C2[5] to the bytes received in I2C__P_GetByte(); function */
        __delay_us(5);
        buf[i] = I2C__P_GetByte();
        
        /* While the lIndex countig is below lBytesNumber - 1 sends ACK for each byte received */
        if (i < (len - 1)) {
            /* Forces and ACK if the condition is fulfilled */
            I2C__P_SendACK();
        }            /* Else sends NACK */
        else {
            /* Forces NACK if else */
            I2C__P_NACK();
        }
    }
    
    /* Stops communication after the writting is complete */
    I2C__P_StopCondition();

    return (1);


} /* uint8_t I2C__P_WriteIOExpander(uint8_t lAddressI2C,uint8_t lMemAdd, uint8_t lBytesNumber, uint8_t * pStartBytes) */


unsigned char acqSend(unsigned char addr, unsigned char cmd, unsigned char * data, unsigned int len) 
{
    unsigned int i;

    /* Generates start condition to initiate communication */
    I2C__P_StartCondition();

    /* Sends I/O expander address, shifting 1 bit into position */
    I2C__P_SendByte(addr << 1);

    __delay_us(10);
    
    /* Checks if ACK is received */
    if (!I2C__P_GetACK()) {
        /* If not, stops communication and returns 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }

    
    I2C__P_SendByte(cmd);
    __delay_us(10);
        /* Checks if ACK is received */
    if (I2C__P_GetACK() == 0) {
        /* If not, stops communication and return 0 for NACK */
        I2C__P_StopCondition();
        return (0);
    }
    
    
    /* Initiates reverse counting to send lBytesNumber bytes */
    for (i = 0; i < len; i++) {
        /* Sends the pointer to TX_BUFFER_I2C3[5] */
        I2C__P_SendByte(data[i]);
        __delay_us(5);
        /* Checks if ACK is received */
        if (!I2C__P_GetACK()) {
            /* If not, stops communication and returns 0 for NACK */
            I2C__P_StopCondition();
            return (0);
        }
    }
    /* Stops communication after the writting is complete */
    I2C__P_StopCondition();

    return (1);


} /* uint8_t I2C__P_WriteIOExpander(uint8_t lAddressI2C,uint8_t lMemAdd, uint8_t lBytesNumber, uint8_t * pStartBytes) */
