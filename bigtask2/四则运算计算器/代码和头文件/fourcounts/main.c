#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "stack.h"
#include "zintoh.h"
#include "calculate.h"
#include "get_input.h"
int main()
{
	char Str[Size];          //定义一个Str来接收用户在中缀表达式中输入的表达式。
	int choice, out_1, out_2;
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","***************************\n");
	printf("%70s","**1、启动计算机  2、退出***\n");
	printf("%70s","***************************\n");
	printf("\n\n");
	printf("%60s","请选择选项:");
	choice=get_input();        //get_input函数用来筛选出合法的输入
	switch(choice)
	{
	case 1:
		zintoh(Str,&out_1);    //中缀表达式变为后缀表达式
		if(out_1 == 0)       //进入计算机后若输入t，则给out_1赋值为0，随后退出程序
		{
			goto end;      //直接退出
		}
		out_2=calculate(Str);  //利用后缀表达式进行计算
		if (out_2 == -1)       //若中缀表达式输入不合要求，转化为后缀表达式时会出现错误，出现错误时返回-1表示出错，提示用户再次输入选择
			goto nonend;
		goto again;
	case 2:
	end:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","***************************\n");
		printf("%70s","********* 退出程序 ********\n");
		printf("%70s","***************************\n");
		break;
	default:
	nonend:
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","***************************\n");
		printf("%70s","****输入错误，请重新输入***\n");
		printf("%70s","***************************\n");
		system("pause");
		system("cls");
		goto again;
	}


	return 0;
}
