#include<lpc213x.h>
int main()
{
    IO0DIR |=0x0F;                  //Port 0 is configured as output
    
    while(1)
    {
        if((IO0PIN & (1<<4)) == 0)        //Checking 4th pin of Port 0
            IO0SET|=0x00000002;           //LED is ON
        else
            IO0CLR|=0x0000000F;           //LED is OFF
    }
		return 0;
}       
