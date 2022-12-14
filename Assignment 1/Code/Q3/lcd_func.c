#include<lpc21xx.h>
#include "header.h"
#define bit(x) (1<<x)

void lcd_cmd(unsigned char a)  
{
    IO0PIN&=0x00;                  
    IO0PIN|=(a<<0);
    IO0CLR|=bit(8);           //To send the COMMANDS into the LCD, Register Select has to be 0 ; rs=0
    IO0CLR|=bit(9);           //For writing into the LCD rw=0
    IO0SET|=bit(10);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call a delay
    IO0CLR|=bit(10);          //en=0
}

void lcd_init()              
{
    lcd_cmd(0x30);           
	  lcd_cmd(0x38);           //activate two rows of LCD crystal
    lcd_cmd(0x0c);           //turn on display , turn off cusor
    lcd_cmd(0x06);           //increment cursor
    lcd_cmd(0x01);           //clear the screen
    lcd_cmd(0x80);           //set the cursor to the beginning of the first line
}

void lcd_data(unsigned char b)  
{
    IO0PIN&=0x00;            
    IO0PIN|=(b<<0);
    IO0SET|=bit(8);           //To send the DATA into the LCD, Register Select has to be 1 ; rs=1
    IO0CLR|=bit(9);           //For writing into the LCD rw=0
    IO0SET|=bit(10);          //To latch the command/data sent into the LCD a high to low pulse is given; en=1
    delay();                  //Call delay
    IO0CLR|=bit(10);          //en=0
}

void lcd_dis(unsigned char *p)  
{
    while(*p!='\0')             
			{
        lcd_data(*p++);       
      }
}

void delay()                  
{   
    unsigned int i;	
    for(i=0;i<10000;i++);
}