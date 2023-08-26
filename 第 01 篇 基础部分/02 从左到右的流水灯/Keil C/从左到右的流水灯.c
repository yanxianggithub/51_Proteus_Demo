#include <STC89C5xRC.H>
#define LED P0

void Delay1000ms()		//@11.0592MHz
{
	unsigned char data i, j, k;
	i = 8;
	j = 1;
	k = 243;
	do
	{
		do
		{
			while (--k);
		} while (--j);
	} while (--i);
}


void main()
{
	unsigned char i;
	while(1){
		for(i = 0;i < 8;i++){
			LED = ~(0x01 << i);
			Delay1000ms();
		}
	}
}