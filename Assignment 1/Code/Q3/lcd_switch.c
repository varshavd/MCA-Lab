#include<lpc21xx.h>
#include "header.h"
int main()
{
    IO0DIR|=0XFFF;                // Port 0 (P0.0 - P0.11) is configured as OUTPUT
    lcd_init();                   // Call initialization function for LCD initialization
    lcd_cmd(0x80);                // LCD command to move the cursor to a specific position
    lcd_dis("MSIS ");           // Display the string by calling the lcd_dis function
    while(1) 
			{
				if((IO1PIN & (1<<16)) ==0)  //Check if the switch connected to P1.16 is pressed 
				{
        lcd_cmd(0x01);              // LCD command for clearing the screen
        delay(20);    
        lcd_dis("MSIS ");			
				//delay(100);
			}
		}
}