#include <xc.h>
#include <stdio.h>
#include "app.h"
#include "usb.h"

#include "hardwareProfile.h"
#include "i2cbb.h"


#include "Acq.h"







void APP_Initialize ( void )
{
    IO_ADC_CNV = 1;
    CS_1 = 1;
    CS_2 = 1;
    CS_3 = 1;
    CS_4 = 1;
    CS_5 = 1;
    CS_6 = 1;
    CS_7 = 1;
    CS_8 = 1;
    CS_9 = 1;
    CS_10= 1;
    CS_11= 1;
    CS_12= 1;
    CS_13= 1;
    CS_14= 1;
    CS_15= 1;
    IO_ADC_CNV_T=0;
    CS1_T = 0;
    CS2_T = 0;
    CS3_T = 0;
    CS4_T = 0;
    CS5_T = 0;
    CS6_T = 0;
    CS7_T = 0;
    CS8_T = 0;
    CS9_T = 0;
    CS10_T= 0;
    CS11_T= 0;
    CS12_T= 0;
    CS13_T= 0;
    CS14_T= 0;
    CS15_T= 0;



    USB_Initialize ();

    initAcq();
    
}



void APP_Tasks ( void )
{


    USB_Tasks();
    
   
    static int cnt = 0;
    cnt++;
    if (cnt > 10000)
    {
        cnt=0;
        IO_LED = IO_LED ? 0 : 1;

        static int v=0;
        v++;
        if (v>10)
        {
            volatile unsigned char bla[5];
          //  acqDoMeas(1000, 5);
            v=0;
        }
    }
            
}

 

/*******************************************************************************
 End of File
 */
