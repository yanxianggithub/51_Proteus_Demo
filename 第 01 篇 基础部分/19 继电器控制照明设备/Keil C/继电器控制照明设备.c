#include <STC89C5xRC.H>

#define Key 		P10
#define Switch  P24 

void delay_ms(unsigned int t)	 //ms??
{
	unsigned int i,j;
	for(i=0; i<t; i++)
		for(j=0; j<120; j++);
}

void main(){
	bit flag = 0;
	Switch = 1;
	while(1){
	
	if(Key == 0){
		delay_ms(10);
		if(Key == 0)
			flag = ~flag;
		while(Key == 0);
	}
	if(flag)Switch = 0;
		else Switch = 1;
	}
}
