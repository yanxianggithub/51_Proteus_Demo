#include <STC89C5xRC.H>
#define RED  	 P0
#define GREEN  P2

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


void main(void)
{
    unsigned char data i,a,b,c;
    //从左到右依次点亮一个小灯；
    c = 0xfe;
    for(i = 0;i < 8; i++)
    {
        a=c<<i;        //切不可写成a=P0<<i;  不要把IO口做为中间变量运算；单片机会随时读取IO口状态；
        b=c>>(8-i);    //P0=~(0x01<<i)
        RED=a|b;
				GREEN=a|b;
        Delay200ms();
    }
    //从右到左依次点亮一个小灯;
    RED=0xff;
		GREEN=0xff;
    for(i=0;i<8;i++)
    {   
        RED=~(0x80>>i);     //1000 0000右移i(0)位1000 0000  取反0111 1111；
				GREEN=~(0x80>>i);
        Delay200ms();       //右侧第一灯亮延时；

    }
    //从左到右依次点亮小灯；
    RED=0xff;
		GREEN=0xff;
    for(i=0;i<8;i++)
    {
        RED<<=1;
				GREEN<<=1;
			//每次左移一位；
        Delay200ms();                   //每移一位进行一次延时；
    }

    //从右到左依次点亮小灯
    RED=0xff;                        //关闭所有LED灯；
    GREEN=0xff;
		for(i=0;i<8;i++)
    {
        RED>>=1;
				GREEN>>=1;
        Delay200ms();
    }

    //两个LED分别从中间像外侧流动
    RED=0xff;
		GREEN=0xff;
    for(i=0;i<3;i++)
    {
        RED=0xe7;
		  	GREEN=0xe7;
        Delay200ms();
        RED=0xdb;
	 		  GREEN=0xdb;
        Delay200ms();
        RED=0xbd;
			  GREEN=0xbd;
        Delay200ms();
        RED=0x7e;
			  GREEN=0x7e;
        Delay200ms();
    }

    //两个LED分别从两侧向中间流动
    RED=0xff;
		GREEN=0xff;
    for(i=0;i<3;i++)
    {
        RED=0x7e; GREEN=0x7e;
        Delay200ms();
        RED=0xbd; GREEN=0xbd;
        Delay200ms();
        RED=0xdb;   GREEN=0xdb;
        Delay200ms();
        RED=0xe7;GREEN=0xe7;
        Delay200ms();
    }
    //奇偶灯交替闪烁
    for(i=0;i<6;i++)
    {
        RED=0x55;GREEN=0x55;
        Delay200ms();
        RED=~RED;GREEN=~GREEN;
	  		Delay200ms();
    }
    //四个灯交替闪烁

    for(i=0;i<6;i++)
    {
        RED=0xf0;GREEN=0xf0;
        Delay200ms();
        RED=~RED; GREEN=~GREEN;
        Delay200ms();
    }   
    //整体闪烁三次
    RED=0xff;GREEN=0xff;
    for(i=0;i<6;i++)
    {

        RED=~RED; GREEN=~GREEN;
        Delay200ms();
    } 
    while(1);
}