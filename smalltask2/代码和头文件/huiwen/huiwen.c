#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huiwen.h"
void huiwen()
{
	char str[size];
	int i,len,Max,j,k,x,y,maxlen_1=1,maxlen_2=1,last_1=0,last_2=0,former_1=0,former_2=0;
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%65s","������һ���ַ���(�˳�������#):");
	scanf("%s", str);
	system("cls");
	while(str[0]!='#')   //����#ʱ�˳�����
	{
		Max=1,maxlen_1=1,maxlen_2=1,last_1=0,last_2=0,former_1=0,former_2=0;   //ÿ���������ַ����ͽ���Ҫ�õ����������³�ʼ��
		len=strlen(str);      //�õ��ַ�������
		for(i=0;i<len;i++)      //�����������ַ���
		{
			j=i-1;    //�����ַ����ǻ��ĵĻ����ٳ���Ϊ��
			k=i+1;
			while(j>=0 && k<len && str[j]==str[k])  //���ҵ���С���ǻ��ĵ��ַ��������жϸ����
			{

				//��������������ַ�����λ�úͳ���
				if (k - j + 1 > maxlen_1)
				{
					maxlen_1 = k - j + 1;
					last_1 = k;
					former_1 = j;
				}
				j--;     //�жϸ�����ַ�
				k++;
			}
		}
		for(i=0;i<len;i++)   //ż�������ַ����ҷ�
		{
			x=i;  //�ж��������ַ��Ƿ����
			y=i+1;

			//���жϸ��������ַ��Ƿ����
			while(x>=0 && y<len && str[x]==str[y])
			{
				if (y - x + 1 > maxlen_2)
				{
					maxlen_2 = y - x + 1;
					last_2 = y;
					former_2 = x;
				}
				x--;
				y++;
			}
		}
		Max = Max > maxlen_1 ? Max : maxlen_1;     //ȡ�����ַ�����󳤶�
		Max = Max > maxlen_2 ? Max : maxlen_2;
		if (Max == 1)     //�����ַ�����һ�������ַ����������ַ�������û���ҵ������ַ���
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%60s","û���ҵ������ַ���");
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%60s","������ַ���Ϊ:");
			if (Max == maxlen_1)    //���������ַ����������ʱ
			{
				while (former_1 <= last_1)
				{
					printf("%c", str[former_1++]);
				}
			}
			else     //ż�������ַ����������ʱ
			{
				while (former_2 <= last_2)
				{
					printf("%c", str[former_2++]);
				}
			}
		}
		printf("\n");
		system("pause");
		goto again;
    }
}
