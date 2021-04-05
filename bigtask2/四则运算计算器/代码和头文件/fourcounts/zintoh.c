#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "stack.h"
#include "zintoh.h"
#include "charstack.h"
char zintoh(char str[],int *z)
{
	charstack store;
	charinitstack(&store);   //初始化一个接收字符的结构体
	char c, e,str1[]="0";
	int i,j=0;
again_1:
	i = 0;
	strcpy(str,str1);
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%95s","输入你想计算的算式(注意以#作为结束标志,括号之间用运算符连接),退出按t:\n");
	printf("%55s","请输入:");
	scanf("%c",&c);
	if(c == 't')        //输入t时退出程序
	{
		return *z=0;
	}
	while(c!='#')
	{
		while(c>= '0' && c<='9')    //输入数字时，直接用str接收
		{
			str[i++] = c;
			str[i] = '\0';
			scanf("%c",&c);
			if(c < '0' ||c > '9')
			{
				str[i++] = ' ';
				str[i] = '\0';
			}
		}
		if(c == ')')      //检测到输入右括号时，
		{
			if(store.top == store.bottom)    //若用户输入合法，栈中绝不可能出现空栈之后再出栈的情况。所以如果出现此情况，则输入必定出现错误
				goto default_1;
			charpop(&store,&e);

			//右括号到左括号内部调整完之后，运算符优先级必定是右边的大于左边的
			//所以可通过循环将栈内的运算符全部出栈
			while(e != '(')
			{
				str[i++] = e;
				str[i++] = ' ';
				str[i] = '\0';
				if(store.top == store.bottom)
					goto default_1;
				charpop(&store,&e);
			}
		}
		else if(c == '+' || c== '-')
		{

			//如果栈内长度为0，则直接入栈
			if(!charstacklen(store))
			{
				charpush(&store,c);
			}

			//栈长度不为0，则判断栈内的运算符是否为括号，如果为括号
			//则将括号重新放入栈中或者其他运算符
			//因为+-号的优先级最低，并且同级，所以碰到+-号入栈时，只要
			//不是括号，那么前一个进栈的运算符必定出栈
			else
			{
				do
				{
					if(store.top == store.bottom)
						goto default_1;
					charpop(&store,&e);
					if(e == '(')
					{
						charpush(&store,e);
					}
					else
					{
						str[i++] = e;
						str[i++] = ' ';
						str[i] = '\0';
					}
				}while(e !='(' && charstacklen(store));
				charpush(&store,c);
			}
		}
		else if(c == '*' || c == '/' || c == '(')   //此情况优先级最高，都全部入栈
		{
			charpush(&store,c);
		}
		else if(c== '#')   //碰到结束标志，字符串接收完成，跳出循环
		{
			break;
		}

		else   //出入非法字符或者没有输入#结束，则输入错误，重新输入
		{
		default_1:

			//重新输入时必须把栈清空，不然影响后续输入
			while(charstacklen(store))
			{
				charpop(&store,&e);

			}
			system("cls");
			fflush(stdin);
			printf("\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","***************************\n");
			printf("%70s","**输入格式错误,请重新输入**\n");
			printf("%70s","***************************\n");
			system("pause");
			system("cls");
			goto again_1;
		}
		scanf("%c",&c);
	}

	//将没有出栈的字符出栈让str接收
	while(charstacklen(store))
	{
		charpop(&store,&e);
		str[i++] = e;
		str[i++]=' ';
	}
	str[i++] = '#';
	str[i] = '\0';
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%50s","转化为后缀表达式为:");
	while(str[j] != '#')
	{
		printf("%c",str[j++]);
	}
	printf("\n");
	system("pause");
	return *str;
}
