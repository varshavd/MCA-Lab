#include<lpc21xx.h>
void delay();


int main()
{
   IO0DIR|=0xFFFFFFFF;  
	 IO1DIR|=0xFFFFFFFF;
while(1)
 { 
	 int i;     
   int a[]={0x06,0x4F,0x6D}; 
   
    IO0SET|=a[1];
	  delay(20);
  	IO0SET|=(a[2]<<8); 
    delay(20);	 
	  IO0SET|=(a[0]<<16); 
	  delay(20);
	  IO1SET|=(a[2]<<16); 

	  
  }
 return 0;
}

void delay()   
{
	  unsigned int a;
    for(a=0;a<75000;a++);
}
