#include <STC89C5xRC.H>

unsigned char number[] = { 0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f }; // 0, 1, 2, 3, 4, 5, 6, 7, 8, 9

void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, k;
	i = 252;
	k = 254;
	do
	{
			while (--k);
	} while (--i);
}


void main()	
{
	int i = 0;
	while(1){
		for(i = 0; i < 10 ; i++){
		P0 = number[i];
		Delay500ms();
		}
	}		
}