#include<lpc21xx.h>
#include "pll.h"
#include "timer0.h"

int main()
{
	IO0DIR |= 0x000000FF;
	init_pll();
	while(1)
	{
		IO0SET |= 0x00000001;
		delay_milliseconds(150);
		IO0CLR |= 0x00000001;
		delay_milliseconds(150);
		
			
		IO0SET |= 0x00000004;
		delay_milliseconds(150);
		IO0CLR |= 0x00000004;
		delay_milliseconds(150);
		
				
		IO0SET |= 0x00000010;
		delay_milliseconds(150);
		IO0CLR |= 0x00000010;
		delay_milliseconds(150);
		
			
		IO0SET |= 0x00000040;
		delay_milliseconds(150);
		IO0CLR |= 0x00000040;
		delay_milliseconds(150);
		
			
			IO0SET |= 0x00000002;
		delay_milliseconds(150);
		IO0CLR |= 0x00000002;
		delay_milliseconds(150);
		
		IO0SET |= 0x00000008;
		delay_milliseconds(150);
		IO0CLR |= 0x00000008;
		delay_milliseconds(150);
		
			IO0SET |= 0x00000020;
		delay_milliseconds(150);
		IO0CLR |= 0x00000020;
		delay_milliseconds(150);
		
			IO0SET |= 0x00000080;
		delay_milliseconds(150);
		IO0CLR |= 0x00000080;
		delay_milliseconds(150);
	}
}
