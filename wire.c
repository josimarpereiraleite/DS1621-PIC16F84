/*
 * File:   wire.c
 * Author: User
 *
 * Created on 13 de Maio de 2022, 06:34
 */

#include "wire.h"
#include <xc.h>

#define _NOP() __asm__ __volatile__("nop")

void Wire_Start(void)
{
    SCL_HIGH;
    _NOP();
    SDA_HIGH;
    _NOP();
    SDA_LOW;
    _NOP(); 
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    SCL_LOW;
}

void Wire_Stop(void)
{
    SDA_LOW;
    _NOP();
    SCL_HIGH;
    _NOP(); 
    _NOP();
    _NOP();
    _NOP();
    _NOP();
    SDA_HIGH;
    
}

unsigned char Wire_Ack()
{
    unsigned char byte = 0;

    TRISA1 = 1;
    
    SDA_HIGH;
    
    for (unsigned char bit=0; bit<8; bit++)
    {
        SCL_HIGH;
	_NOP();
	byte <<= 1;
	if(PORTAbits.RA1 == 1) byte |= 1; 
	
	SCL_LOW;
	_NOP();
	_NOP();
    }
	
    TRISA1 = 0;

    SDA_LOW;
    _NOP();
    SCL_HIGH;
    _NOP();
    SCL_LOW;
    _NOP();
    
    return byte;
}

unsigned char Wire_Nack()
{
    unsigned char byte = 0;
    
    TRISA1 = 1;
    
    SDA_HIGH;
    
    for (unsigned char bit=0; bit<8; bit++)
    {
        SCL_HIGH;
	_NOP();
        
        
	byte <<= 1;
	if(PORTAbits.RA1 == 1) byte |= 1; 
	
	SCL_LOW;
        _NOP();
	_NOP();
    }
    
     TRISA1 = 0;

    SDA_HIGH;
    _NOP();
    SCL_HIGH;
    _NOP();
    SCL_LOW;
    _NOP();
	
    return byte;
}

void Wire_Write(unsigned char data)
{
    for(unsigned char bit = 0x80; bit; bit>>=1)
    {
        if(data & bit) SDA_HIGH; else SDA_LOW;
        
        SCL_HIGH;
	_NOP();
	SCL_LOW;
	_NOP();
    }
  
    SDA_HIGH;
    _NOP();
    SCL_HIGH;
    _NOP();
    SCL_LOW;
    _NOP();
}

unsigned char Wire_Test(unsigned char Slave)
{
    unsigned char ack = 0;
	
    Wire_Start();
    
    for(unsigned char bit=0; bit<8; ++bit)
    {
	if(Slave & 0x80) SDA_HIGH; else SDA_LOW;
	Slave <<= 1;
	
	SCL_HIGH;
	_NOP();
	SCL_LOW;
	_NOP();
    }
        
    // Read ACK
    TRISA1 = 1;
    
    SDA_HIGH;
    SCL_HIGH;
    _NOP();
    if(PORTAbits.RA1 == 1) ack = 1; 
    SCL_LOW;
    _NOP();
    
    TRISA1 = 0;
    
    Wire_Stop();
    
    return ack;
}

void Wire_Init(void)
{
    TRISA0 = 0;
    TRISA1 = 0;
}

