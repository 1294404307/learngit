#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
//#include "get_input.h"
#include <string.h>
#include "change.h"

int main()
{
	char strr[Size];
	int num,choice;    //��¼�任Ϊ������
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%75s","1���������    2���˳�����\n\n");
	printf("%65s","��ѡ��");
	choice=get_input();     //ɸѡ����ȷ������
	if(choice == 1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%65s","����һ���ַ���:");
		scanf("%s",strr);
		printf("%67s","��������ת��������:");
		num = get_input();
		if(num == 1 )
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%65s","һ������ת��\n");
			system("pause");
			system("cls");
			goto again;
		}
		else if(num>1)
		{
			convert(strr, num);
			goto again;
		}
		else
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","�����������������\n");
			system("pause");
			system("cls");
			goto again;
		}
	}
	else if (choice == 2)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%65s","�˳�����\n");
	}
	else     //ѡ�����ʱ
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","�����������������\n");
		system("pause");
		goto again;
	}
	return 0;
}
