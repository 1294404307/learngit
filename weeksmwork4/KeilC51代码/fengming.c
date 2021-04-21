#include <reg51.h>  

//储存音符发声时间，通过发声时间转换为频率
unsigned char code high[] = {
0,226,229,232,233,
236,238,240,241,242
,244,245,246,247,248};

unsigned char code low[] = {
0,4,13,10,20,3,8
,6,2,23,5,26,4,4,3};  

sbit key = P1^7;
sbit key2 = P1^6;
sbit sound = P3^0;

void delayms(unsigned int x);
void key2scan();

unsigned char musicNum;






void main(void)
{
	TMOD = 0x00;                       //设置定时器模式
	TH0 = (65536 - 45872) / 256;       //任意赋初值
	TL0 = (65536 - 45872) % 256;
	EA = 1;                    //打开总中断
	ET0 = 1;                   //打开计时器0中断
	sound = 0;
	while(1)
	{
		while(key2 == 1);
		while(key2 == 0);
		for(musicNum = 1;musicNum < 15;musicNum++)
		{
			TR0 = 1;
			delayms(400);           //通过延时使计时器溢出而执行中断，同时控制发声时间
			TR0 = 0;
			key2scan();
			delayms(50);
		}
	}
}




//定时器溢出，执行中断
void Timer0(void) interrupt 1
{
  sound = ~sound;   //无源蜂鸣器，需要波动才能响
 
	TH0 = high[musicNum];    //将对应音符值传给TH0
	TL0 = low[musicNum];  
}



//延时函数
void delayms(unsigned int x)
{
  unsigned char i;
	while(x--)
	{
		for(i = 108;i >0 ;i--)
		{
		 
			//如果凤蜂鸣器响的过程中想暂停则点击按钮
			if(key == 0)
			{
				while(key == 0);
				while(key == 1)
					TR0=0;              //蜂鸣器停止响，定时器暂停
				while(key == 0);
				if(key == 1)
					TR0=1;        //蜂鸣器再次打开，定时器再次打开
			}
	 }
 }
}

void key2scan()
{
	if(key2 == 0)
	{
		while(key2 == 0);
		while(key2 == 1);
		musicNum=0;
		while(key2 == 0);
	}
}