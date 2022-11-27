#include "timer0.h"
#include<LPC214x.h>

void delay_milliseconds(unsigned int milliseconds)
	{
		T0CTCR =0x0;									
		T0TCR=0x00;               
    T0PR=59999;                 
    T0TCR=0x02;                 
    T0TCR=0x01;                
		while(T0TC < milliseconds);  
		T0TCR=0x00;                 
    T0TC=0; 									
		
	}