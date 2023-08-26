#include <STC89C5xRC.H>
#define SELECT  P2  
#define NUMBER  P0

unsigned char select[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80 };
unsigned char number[] = {0xc0,0xf9,0xa4,0xb0,0x99,0x92,0x82,0xf8,0x80,0x90,0x88,0x83,0xc6,0xa1,0x86,0x8e};
				       // 共阳极    0    1    2   3     4    5    6    7    8    9    A    B    C    D    E    F
void Delay500ms()		//@11.0592MHz
{
	unsigned char data i, j, k;

	i = 4;
	j = 129;
	k = 119;
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
		for(i=0;i<8;i++){
			SELECT = select[i];
			NUMBER = number[i];
			Delay500ms();
		}
		
	}

}