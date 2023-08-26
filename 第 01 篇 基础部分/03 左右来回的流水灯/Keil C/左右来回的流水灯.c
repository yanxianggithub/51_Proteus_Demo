#include <STC89C5xRC.H>
#define LED P2

void Delay200ms()		//@11.0592MHz
{
	unsigned char data i, j, k;
	i = 2;
	j = 103;
	k = 147;
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
		 for(i = 0; i < 8; i++){
		 LED = (0x01 << i);
		 Delay200ms();
		 }
		 for(i = 0; i < 8; i++){
		 LED = (0x80 >> i);
		 Delay200ms();
		 }
	 }
}
