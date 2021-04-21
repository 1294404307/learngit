#include <reg51.h>

#define uchar unsigned char
#define uint unsigned int
#define OriNum 0
	
void key13scan();
void key2scan();
void delayms(uint num);
void display(uint numb);

uchar code Table[]={
0xc0,0xf9,0xa4,0xb0,
0x99,0x92,0x82,0XD8,
0x80,0x90,0x88,0x83,
0xc6,0xa1,0x86,0x8e,
0x7f,0xbf,0x89,0xff};

sbit key1 = P1^0;     //给计数器+1
sbit key2 = P1^1;    //打开计数器，关闭计数器，重置计数器功能
sbit key3 = P1^2;       //让计数器减1

uint num,bai,shi,ge;


void main()
{
	num=OriNum;
	while(key2 == 1);  //等待点击按钮开启
	while(key2 == 0);
	while(1)
	{
		key13scan();
		key2scan();
		display(num);
	}
}





void key2scan()
{
	int i,j;
	if(key2 == 0)          //按下按键
	{
		P2=0;

		//设置长按3秒数值归零，通过循判断长按时间
		for(i=2000;i>0;i--)
		{
			for(j=110;j>0;j--)
			{
				if(key2 == 1)      //松开开关则跳出循环
				break;
			}
			if(key2 == 1)
			{	
				break;
			}
		}
		if(i == 0)
		{
			num=0;
		}
		while(key2 == 1);
		while(key2 == 0);
	}
}


void key13scan()
{
	if(key1 == 0)    //判断开关1
	{
		delayms(10);
		if(key1 == 0)
		{
			num++;
			if(num == 1000)  //限制在0-999及以内显示
				num=0;
			while(!key1);
		}
	}
	if(key3 == 0)    //判断开关3
	{
		delayms(10);
		if(key3 == 0)
		{
			num--;
			if(num == -1)  //限制在0-999及以内显示
				num=999;
			while(!key3);
		}
	}
}

void delayms(uint num)
{
	uint i,j;
	for(i=num;i>0;i--)
		for(j=110;j>0;j--);   //延时num毫秒
}

void display(uint numb)
{
	bai = numb /100;          //取百位的数值
	shi = numb%100/10;
	ge = numb % 10;
	P2=1;                   //选择打开第一个数码管
	P0=Table[bai];       //显示百位
	delayms(5);
	
	P2=2;
	P0=Table[shi];
	delayms(5); 

	P2=4;
	P0=Table[ge];
	delayms(5);
	P2=0;
}

