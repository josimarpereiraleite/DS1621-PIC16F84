/*
 * ds1621.cpp
 *
 * Created: 05/03/2022 13:02:30
 *  Author: User
 */ 
#include "ds1621.h"
#include "wire.h"

void DS1621_Start_Convert()
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(DS1621_START_CONVET);
	Wire_Stop();
}

void DS1621_Stop_Convert()
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(DS1621_STOP_CONVET);
	Wire_Stop();
}


void DS1621_Command(unsigned char reg, unsigned char data)
{
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(reg);
	Wire_Write(data);
	Wire_Stop();
}


unsigned char DS1621_Read(unsigned char reg)
{
	unsigned char data = 0;
	
	Wire_Start();
	Wire_Write(DS1621_SLA_W);
	Wire_Write(reg);
	Wire_Start();
	Wire_Write(DS1621_SLA_R);
	data = Wire_Nack();
	Wire_Stop();
	
	return data;
}
