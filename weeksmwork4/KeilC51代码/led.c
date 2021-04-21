#include <reg51.h>
#include <intrins.h>
#define uchar unsigned char
#define uint unsigned int
	
sbit key1=P1^0;
sbit key2=P1^1;

void key1scan();
void key2scan();
void delay(uint ms);

uchar a=0xFE;



void main(void)
{
	
	//打开流水灯
	while(key1 == 1);
	while(key1 == 0);
	while(1)
	{	
		key1scan();
		key2scan();
	}
}




void delay(uint ms)
{
	uint i,j;
	for(i=ms;i>0;i--)
		for(j=110;j>0;j--);
}

void key1scan()   
{
	P0=a;
	delay(250);
	a=_crol_(a,1);
	
	//暂停流水灯
	if(key1 == 0)
	{
		while(key1 == 0);
		while(key1 == 1);
		while(key1 == 0);
	}
}

void key2scan()    //停止并且重置流水灯
{
	if(key2 == 0)
	{
		while(key2 == 0);
		P0=0xff;
		a=0xfe;
		while(key2 == 1);
		while(key2 ==0);
	}
}