
#ifndef _EXAMPLE_FILE_NAME_H    /* Guard against multiple inclusion */
#define _EXAMPLE_FILE_NAME_H



/* Provide C++ Compatibility */
#ifdef __cplusplus
extern "C" {
#endif

void acqDoMeas(unsigned int pts, unsigned int timingUs);
unsigned short * getAcqDataBuf();
void initAcq();
void setParam(unsigned short timingUs, unsigned short nbpts, unsigned short triggerValue);
unsigned char hasNewMeasurement();
void acqTrig();        
void * acqCopyTo(unsigned char * buf, unsigned short start, unsigned char len);
    /* Provide C++ Compatibility */
#ifdef __cplusplus
}
#endif

#endif /* _EXAMPLE_FILE_NAME_H */

/* *****************************************************************************
 End of File
 */
