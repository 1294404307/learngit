#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"
#include "LinkStack.h"

int main()
{
	int input_1;
	while(1)
	{
		system("cls");
		menu();
		input_1=get_input();
		system("cls");
		switch(input_1)
		{
		case 1:
			testspeed();   //�����㷨��ʱ
			break;
		case 2:
			testmansmdata();   //���Զ�����С�����㷨����ʱ
			break;
		case 3:
			testcolor();     //��ɫ����
			break;
		case 4:
			testfindknum();   //�ҵ���kС��ֵ
			break;
		case 5:
			testall();     //���������㷨
			break;
		case 6:
			return 0;
		default:
			printf("--------------------------\n");
			printf("    ���������������\n");
			printf("--------------------------\n");
			system("pause");
			break;
		}
	}
	return 0;
}
