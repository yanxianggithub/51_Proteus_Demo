#include <STC89C5xRC.H>
#include <intrins.h>
#define DSW  P1
#define SMG  P0
#define SEL  P2

typedef unsigned char u8;
typedef unsigned int  u16;

u8 code smgCode[]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f,0x77,0x7c,0x39,0x5e,0x79,0x71};
								//0-F的码表

void Delayms(u16 a)		//@12.000MHz
{
	u8 data j;
	u16 data i;
	
	i = 2*a;
	j = 239;
	do
	{
		while (--j);
	} while (--i);
}


void main()
{
	u8 DSY_Buffer[3] = {0};
	u8 i,m,num;
	SMG = 0xff;
	SEL = 0xff;
	while(1)
	{
		m = 0xfe;
		num = DSW; //读取拨码开关的值
		DSY_Buffer[0] = num / 100;
		DSY_Buffer[1] = num / 10 % 10;
		DSY_Buffer[2] = num % 10;
		for(i = 0; i < 3; i++) //刷新显示在数码管上
		{
			m = _crol_(m,1);
			SEL = m;
			SMG = smgCode[DSY_Buffer[i]];
			Delayms(10);
		}

	}
}
