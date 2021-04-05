#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calculate.h"
#include "zintoh.h"
#include "stack.h"
int calculate(char str[])
{
	sqstack store;
	initstack(&store);
	elemtype last,former,sum;
	char strl[Size], strll[] = "0";

	int i=0,m=0;
again:
	//通过循环，逐个读取str中接收到的字符串
	while(str[m]!='#' || str[m]== ' ')
	{
		if(str[m] == ' ')  //接收到空格，则跳过空格接收下一个字符
		{
			m++;
			goto again;
		}

		//碰到数字就推入栈中
		if (str[m] >= '0' && str[m] <= '9')
		{
			while (str[m] >= '0' && str[m] <= '9')
			{
				strl[i++] = str[m];
				strl[i] = '\0';
				m++;
				if (str[m] == ' ')
				{
					sum = atof(strl);
					push(&store, sum);
				}
			}
			i = 0;
			strcpy(strl, strll);
			goto again;
		}

		//碰到运算符就把栈中的最后进去的两个数字从栈中取出来进行运算
		switch(str[m])
		{
		case '+':
			if (store.top - store.bottom < 2)   //若用户输入正确，则每次运算之前必定有两个数在栈中，否则用户输入错误
				goto end_1;     //输入错误则退出计算窗口，提示用户重新选择并输入
			pop(&store,&last);
			pop(&store,&former);
			sum=former + last;
			push(&store,sum);
			m++;
			goto again;
		case '-':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former - last;
			push(&store,sum);
			m++;
			goto again;
		case '*':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former * last;
			push(&store,sum);
			m++;
			goto again;
		case '/':
			if (store.top - store.bottom < 2)
				goto end_1;
			pop(&store,&last);
			pop(&store,&former);
			sum=former / last;
			push(&store,sum);
			m++;
			goto again;
		}
	}
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","***************************\n");
	printf("%40s","*");
	printf("*********计算结果为:%3.2f*******\n",sum);
	printf("%70s","***************************\n");
	system("pause");
	return 1;
end_1:
	return -1;
}
