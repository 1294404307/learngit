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
	int num,choice;    //记录变换为多少行
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%75s","1、进入程序    2、退出程序\n\n");
	printf("%65s","请选择：");
	choice=get_input();     //筛选出正确的输入
	if(choice == 1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%65s","输入一串字符串:");
		scanf("%s",strr);
		printf("%67s","输入你想转换的行数:");
		num = get_input();
		if(num == 1 )
		{
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%65s","一行无需转换\n");
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
			printf("%70s","输入错误，请重新输入\n");
			system("pause");
			system("cls");
			goto again;
		}
	}
	else if (choice == 2)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%65s","退出程序\n");
	}
	else     //选择错误时
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","输入错误，请重新输入\n");
		system("pause");
		goto again;
	}
	return 0;
}
