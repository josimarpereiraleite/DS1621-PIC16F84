/* 
 * File:   
 * Author: 
 * Comments:
 * Revision history: 
 */

// This is a guard condition so that contents of this file are not included
// more than once.  
#ifndef XC_HEADER_TEMPLATE_H
#define	XC_HEADER_TEMPLATE_H

#include <xc.h>  

#define SCL_HIGH            RA0=1
#define SCL_LOW             RA0=0

#define SDA_HIGH            RA1=1
#define SDA_LOW             RA1=0

unsigned char Wire_Test(unsigned char Slave);
unsigned char Wire_Nack();
unsigned char Wire_Ack();
void Wire_Stop();
void Wire_Start();
void Wire_Write(unsigned char data);
void Wire_Init();

#endif	/* XC_HEADER_TEMPLATE_H */

