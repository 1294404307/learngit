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
	
	//����ˮ��
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
	
	//��ͣ��ˮ��
	if(key1 == 0)
	{
		while(key1 == 0);
		while(key1 == 1);
		while(key1 == 0);
	}
}

void key2scan()    //ֹͣ����������ˮ��
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