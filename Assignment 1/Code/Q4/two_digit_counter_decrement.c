#include<lpc21xx.h>

void delay(unsigned int a)   
{
    for(a=1;a<=60000;a++);
}

int main()
{
	
    IO0DIR|=0xFFFFFFFF;    

	while(1)
 { 
	 unsigned  long int j; 
   int i;               
   int a[]={0x3F,0x06,0x5B,0x4F,0x66,0x6D,0x7D,0x07,0x7F,0x6F};   
   
   for(j=9;j>=0;j--)       
    { 
	    IO0SET|=a[j];        
        for(i=9;i>=0;i--) 
         {
             IO0SET|=(a[i]<<8); 
             delay(10000);      
             IO0CLR|=(a[i]<<8); 
          }
        IO0CLR|=a[j];    
	  }
 } return 0;
}
