#include <reg51.h>  

//������������ʱ�䣬ͨ������ʱ��ת��ΪƵ��
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
	TMOD = 0x00;                       //���ö�ʱ��ģʽ
	TH0 = (65536 - 45872) / 256;       //���⸳��ֵ
	TL0 = (65536 - 45872) % 256;
	EA = 1;                    //�����ж�
	ET0 = 1;                   //�򿪼�ʱ��0�ж�
	sound = 0;
	while(1)
	{
		while(key2 == 1);
		while(key2 == 0);
		for(musicNum = 1;musicNum < 15;musicNum++)
		{
			TR0 = 1;
			delayms(400);           //ͨ����ʱʹ��ʱ�������ִ���жϣ�ͬʱ���Ʒ���ʱ��
			TR0 = 0;
			key2scan();
			delayms(50);
		}
	}
}




//��ʱ�������ִ���ж�
void Timer0(void) interrupt 1
{
  sound = ~sound;   //��Դ����������Ҫ����������
 
	TH0 = high[musicNum];    //����Ӧ����ֵ����TH0
	TL0 = low[musicNum];  
}



//��ʱ����
void delayms(unsigned int x)
{
  unsigned char i;
	while(x--)
	{
		for(i = 108;i >0 ;i--)
		{
		 
			//������������Ĺ���������ͣ������ť
			if(key == 0)
			{
				while(key == 0);
				while(key == 1)
					TR0=0;              //������ֹͣ�죬��ʱ����ͣ
				while(key == 0);
				if(key == 1)
					TR0=1;        //�������ٴδ򿪣���ʱ���ٴδ�
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