#include <REGX52.H>
#define LED P1
void delay_ms(unsigned int xms);
void main()
{
	while(1)
	{
		LED = 0xff;
		delay_ms(500);
		LED = 0xfe;
		delay_ms(500);
	}
}

void delay_ms(unsigned int xms)		//@12.000MHz
{
	unsigned char i, j;
	while(xms)
	{
		i = 2;
		j = 239;
		do
		{
			while (--j);
		} while (--i);
		xms--;
	}
}