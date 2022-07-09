// CONFIG
#pragma config FOSC = HS        // Oscillator Selection bits (HS oscillator)
#pragma config WDTE = OFF       // Watchdog Timer (WDT disabled)
#pragma config PWRTE = OFF      // Power-up Timer Enable bit (Power-up Timer is disabled)
#pragma config CP = OFF         // Code Protection bit (Code protection disabled)

#define _XTAL_FREQ   16000000

#include <xc.h>

#include "max7221.h"
//#include "rda5807m.h"
#include "wire.h"
#include "ds1621.h"

unsigned char temp = 0;

void Print_Temperature()
{
    if(temp > 128)
    {
        temp = (256 - temp);
        
        if(temp < 100)
        {
            MAX7221_Command(1, 0);
            MAX7221_Command(2, 0x01);
            MAX7221_Print(3, temp/10%10, 0);
            MAX7221_Print(4, temp/1%10, 0);
        }
    
        if(temp >= 100)
        {
            MAX7221_Command(1, 0x01);
            MAX7221_Print(2, temp/100%10, 0);
            MAX7221_Print(3, temp/10%10, 0);
            MAX7221_Print(4, temp/1%10, 0);
        }
    }   
    
    else
    {
        if(temp < 100)
        {
            MAX7221_Command(1, 0);
            MAX7221_Command(2, 0);
            
            MAX7221_Print(3, temp/10%10, 0);
            MAX7221_Print(4, temp/1%10, 0);
        }
    
        if(temp >= 100)
        {
            MAX7221_Command(1, 0);
            MAX7221_Print(2, temp/100%10, 0);
            MAX7221_Print(3, temp/10%10, 0);
            MAX7221_Print(4, temp/1%10, 0);
        }
    }
}

int main() 
{
    __delay_ms(1000);
    
    Wire_Init();
    
    MAX7221_Init();

    while(1)
    {
        temp = DS1621_Read(DS1621_READ_TEMP);
                
        Print_Temperature();
        
        DS1621_Start_Convert();
        __delay_ms(1000);
        DS1621_Stop_Convert();
        __delay_ms(50);
    }
}
