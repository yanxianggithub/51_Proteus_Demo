#include <STC89C5xRC.H>

#define Lup    P14
#define Ldwon  P15
#define Rup 	 P16
#define Rdwon  P17
#define LLED   P0
#define RLED   P2

unsigned char data led[] = {0x01, 0x02, 0x04, 0x08, 0x10, 0x20, 0x40, 0x80};
void Delay10ms();

void main()
{
	char l = 0, r = 0;

	do{
		if(Lup == 0 || Ldwon == 0 || Rup == 0 || Rdwon == 0){
			Delay10ms();  //按键消抖
			if(Lup == 0)
				l--;
			else if(Ldwon == 0)
				l++;
			else if(Rup == 0)
				r--;
			else if(Rdwon == 0)
				r++;
			while(Lup == 0 || Ldwon == 0 || Rup == 0 || Rdwon == 0);
		}
		if(l < 0)l = 7;l%=8;
		if(r < 0)r = 7;r%=8;
		LLED = ~led[l];
		RLED = ~led[r];
	}while(1);
	
}

void Delay10ms()		//@11.0592MHz
{
	unsigned char data i, j;

	i = 18;
	j = 235;
	do
	{
		while (--j);
	} while (--i);
}
