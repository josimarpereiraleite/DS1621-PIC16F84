/*
	@File 		nax7221.cpp
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/

#include "max7221.h"

static const unsigned char digits[] =
{
	0x7e, // 0
	0x30, // 1
	0x6d, // 2
	0x79, // 3
	0x33, // 4
	0x5b, // 5
	0x5f, // 6
	0x70, // 7
	0x7f, // 8
	0x7b, // 9
	0x80, // DP
};

void MAX7221_Write(unsigned char data)
{
    for(unsigned char bit = 0x80; bit; bit>>=1)
    {
        MAX7221_CLK_LOW;
                
        if(data & bit) MAX7221_DIN_HIGH; else MAX7221_DIN_LOW;
        
        MAX7221_CLK_HIGH;
    }
}

void MAX7221_Command(char cmd, char value)
{
	MAX7221_CS_LOW;
	
	MAX7221_Write(cmd);
	MAX7221_Write(value);
	
	MAX7221_CS_HIGH;
}

void MAX7221_Print(unsigned char digit, unsigned char num, unsigned char DP)
{
	MAX7221_Command(digit, digits[ num ] | (DP << 7));
}

unsigned char t;

void MAX7221_Init()
{
	TRISB1 = 0;
	TRISB2 = 0;
	TRISB3 = 0;
	
	MAX7221_CS_HIGH;
	
	// 0x00	:	SHUTDOWN MODE
	// 0x01	:	NORMAL OPERATION
	MAX7221_Command(MAX7221_SHUTDOWN, 0x01); 
	
	// From 0x00 to 0x0F
	MAX7221_Command(MAX7221_INTENSITY, 0x07);
	
	// 0x01	:	DISPLAY TEST
	// 0x00	:	NORMAL OPERATION
	MAX7221_Command(MAX7221_DISPLAYTEST, 0x00);
	
	// From 0x00 to 0x07
	MAX7221_Command(MAX7221_SCANLIMIT, 0x07);
}
