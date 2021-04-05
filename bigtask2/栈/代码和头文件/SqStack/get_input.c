#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
#include "get_input.h"
#include <string.h>
int get_input()
{
	char inputt, str[Putsize],str3[]="-1073741510";
	int i = 0, Input = 0;
	fflush(stdin);     // 清空输入缓存区，防止下次输入操作被影响
	scanf("%c", &inputt);
	if(inputt=='\n')   //若直接点击回车
	{
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******您没有输入任何东西****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
//		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//		printf("%60s","请输入:");
		strcpy(str, str3);
		goto end;
	}

	//通过循环逐个读取字符，直到读取到回车
	while (inputt != '\n')
	{
		if (i > Putsize)   //当输入的字符串位数过多，超过ElemType类型值的最大范围时
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***输入错误，输入数值过大**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//			printf("%60s","请输入:");
			strcpy(str, str3);  //将str3里的错误返回值给str，返回一个错误值，以表示输入错误
			i = 0;
			goto end;  //输入错误时，直接退出输入
		}

		//若用户需要输入负数，而负号必定只能出现在字符串的下标为0的位置，所以做此判断
		if (i==0)
		{
			if(inputt == '-')
			{
				str[i++]='-';
				str[i]='\0';
				scanf("%c", &inputt);
			}
		}

		//通过ASCII码值筛选出单个数字储存在字符串中，否不是数字，则为非法输入
		if (inputt >= 48 && inputt <= 57)
		{
			str[i++] = inputt;
			str[i] = '\0';
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***输入错误，输入非法字符**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
			strcpy(str, str3);
			i = 0;
//			printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
//			printf("%60s","请输入:");
			goto end;
		}
		scanf("%c", &inputt);
	}
	if(i==1 && str[1]=='-')  //判断是否只出入了负号，如果只输入了负号，那也是不合法输入
	{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","***输入错误，输入非法字符**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
	}
end:
	system("cls");
	fflush(stdin);
	Input = atoi(str);   //将字符串str转化为整型数字
	return Input;
}
