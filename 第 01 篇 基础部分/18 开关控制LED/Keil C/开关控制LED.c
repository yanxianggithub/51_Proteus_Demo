#include "reg51.h"
sbit P00 = P0^0;
sbit P01 = P0^1;

sbit P10 = P1^0;
sbit P11 = P1^1;

void main()
{
	P10 = 1;
  P11 = 1;
	P00 = 0;
  P01 = 0;
    while (1)
    {
		if(P10 == 0)P00 = 0;
			else P00 = 1;
		if(P11 == 0)P01 = 0;
			else P01 = 1;
    }
}

