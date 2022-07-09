/*
	@File 		max7221.h
	@Author		JOSIMAR PEREIRA LEITE
	@country	Brazil
	@Date		07/06/2021
	

    Copyright (C) 2021  JOSIMAR PEREIRA LEITE

    This program is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.
*/


#ifndef MAX7221_H_
#define MAX7221_H_

#include <xc.h>

#define MAX7221_CS_HIGH			RB2=1
#define MAX7221_CS_LOW			RB2=0

#define MAX7221_DIN_HIGH		RB1=1
#define MAX7221_DIN_LOW			RB1=0

#define MAX7221_CLK_HIGH		RB3=1
#define MAX7221_CLK_LOW			RB3=0

#define MAX7221_DECODEMODE		0x09
#define MAX7221_INTENSITY		0x0A
#define MAX7221_SCANLIMIT		0x0B
#define MAX7221_SHUTDOWN		0x0C
#define MAX7221_DISPLAYTEST		0x0F

// SEGMENTS
#define MAX7221_SEG_1			0x01
#define MAX7221_SEG_2			0x02
#define MAX7221_SEG_3			0x03
#define MAX7221_SEG_4			0x04
#define MAX7221_SEG_5			0x05
#define MAX7221_SEG_6			0x06
#define MAX7221_SEG_7			0x07

// DP
#define MAX7221_DP_LOW			0x00
#define MAX7221_DP_HIGH			0x01

void MAX7221_Write(unsigned char data);
void MAX7221_Init();
void MAX7221_Print(unsigned char digit, unsigned char num, unsigned char DP);
void MAX7221_Command(char address, char digit);
void MAX7221_Shutdown(char BOOL);	
void MAX7221_Init();

#endif /* MAX7221_H_ */
