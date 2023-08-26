#include <STC89C5xRC.H>
#include <intrins.h>
	
void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, k;
	_nop_();
	_nop_();
	i = 43;
	k = 203;
	do
	{
			while (--k);
	} while (--i);
}

void main()
{
	while(1){
		P10 = 0;
		Delay500ms();
		P10 = 1;
		Delay500ms();
	}
}
