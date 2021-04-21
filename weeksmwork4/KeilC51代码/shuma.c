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

sbit key1 = P1^0;     //��������+1
sbit key2 = P1^1;    //�򿪼��������رռ����������ü���������
sbit key3 = P1^2;       //�ü�������1

uint num,bai,shi,ge;


void main()
{
	num=OriNum;
	while(key2 == 1);  //�ȴ������ť����
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
	if(key2 == 0)          //���°���
	{
		P2=0;

		//���ó���3����ֵ���㣬ͨ��ѭ�жϳ���ʱ��
		for(i=2000;i>0;i--)
		{
			for(j=110;j>0;j--)
			{
				if(key2 == 1)      //�ɿ�����������ѭ��
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
	if(key1 == 0)    //�жϿ���1
	{
		delayms(10);
		if(key1 == 0)
		{
			num++;
			if(num == 1000)  //������0-999��������ʾ
				num=0;
			while(!key1);
		}
	}
	if(key3 == 0)    //�жϿ���3
	{
		delayms(10);
		if(key3 == 0)
		{
			num--;
			if(num == -1)  //������0-999��������ʾ
				num=999;
			while(!key3);
		}
	}
}

void delayms(uint num)
{
	uint i,j;
	for(i=num;i>0;i--)
		for(j=110;j>0;j--);   //��ʱnum����
}

void display(uint numb)
{
	bai = numb /100;          //ȡ��λ����ֵ
	shi = numb%100/10;
	ge = numb % 10;
	P2=1;                   //ѡ��򿪵�һ�������
	P0=Table[bai];       //��ʾ��λ
	delayms(5);
	
	P2=2;
	P0=Table[shi];
	delayms(5); 

	P2=4;
	P0=Table[ge];
	delayms(5);
	P2=0;
}

