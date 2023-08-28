#include <STC89C5xRC.H>

#define GPIO_DIG P0
#define GPIO_KEY P1

typedef unsigned char u8;
typedef unsigned int u16;
  
 u8 code smg[]= {
		0x3F,  //"0"
    0x06,  //"1"
    0x5B,  //"2"
    0x4F,  //"3"
    0x66,  //"4"
    0x6D,  //"5"
    0x7D,  //"6"
    0x07,  //"7"
    0x7F,  //"8"
    0x6F,  //"9"
    0x77,  //"A"
    0x7C,  //"B"
    0x39,  //"C"
    0x5E,  //"D"
    0x79,  //"E"
    0x71,  //"F"
    0x76,  //"H"
    0x38,  //"L"
    0x37,  //"n"
    0x3E,  //"u"
    0x73,  //"P"
    0x5C,  //"o"
    0x40,  //"-"
    0x00  //熄灭
		};//静态数码管码值
 
u8 KeyColValue;
u8 KeyLineValue;
 
void delay(u16 i) //延时函数
  {
   while(i--);
  }
 
void KeyDown() //键盘按键扫描函数
 {
 
  char a;
 
  GPIO_KEY = 0xf0;
  if(GPIO_KEY != 0xf0)//检测4行中哪一行按键是否按下
  {
   delay(1000); //延时消抖
   if(GPIO_KEY != 0xf0) //再次检测4行中哪一行按键是否按下
   {
		 switch(GPIO_KEY) //根据IO的值来确定哪一行按键按下
		 {
			 case(0xe0): KeyColValue = 0; break;
			 case(0xd0): KeyColValue = 1; break;
			 case(0xb0): KeyColValue = 2; break;
			 case(0x70): KeyColValue = 3; break;
		 }
   }
  }
 
  GPIO_KEY = 0x0f;
	
  if(GPIO_KEY != 0x0f) //检测4行中哪一列按键是否按下
  {
   delay(1000);  //延时消抖
   if(GPIO_KEY != 0x0f) //再次检测4行中哪一列按键是否按下
   {
		 switch(GPIO_KEY) //根据IO的值来确定哪一列按键按下
		 {
			 case(0x0e): KeyLineValue = 0; break;
			 case(0x0d): KeyLineValue = 1; break;
			 case(0x0b): KeyLineValue = 2; break;
			 case(0x07): KeyLineValue = 3; break;
		 }
   }
 
   while((a < 50) && (GPIO_KEY != 0x0f))  //延时，确保没有按键再按下
  {
   delay(1000);
   a ++;
  }
 
  }
 
}
 
void main()
   {
   while(1)
   {
   KeyDown();//检测按键是否按下
   GPIO_DIG = smg[KeyLineValue + KeyColValue*4];//根据按键的行列值，静态数码管显示相应的值
   }
 }