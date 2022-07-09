/*
 * ds1621.h
 *
 * Created: 05/03/2022 13:02:41
 *  Author: User
 */ 


#ifndef DS1621_H_
#define DS1621_H_

#define DS1621_SLA_W					0x90
#define DS1621_SLA_R					0x91

#define DS1621_READ_TEMP				0xAA
#define DS1621_ACCESS_TH				0xA1
#define DS1621_ACCESS_TL				0xA2
#define DS1621_ACCESS_CONFIG                            0xAC
#define DS1621_READ_COUNTER				0xA8
#define DS1621_READ_SLOPE				0xA9
#define DS1621_START_CONVET				0xEE
#define DS1621_STOP_CONVET				0x22

void DS1621_Start_Convert();
void DS1621_Stop_Convert();
void DS1621_Command(unsigned char reg, unsigned char data);
unsigned char DS1621_Read(unsigned char reg);

#endif /* DS1621_H_ */
