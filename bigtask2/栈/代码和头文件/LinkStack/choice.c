#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
#include "LinkStack.h"
#include "menu.h"
#include "get_input.h"
void choice()
{
	LinkStack stack;
	stack.count=-1;    //通过判断count是否为-1来判断栈是否存在
	int input, Length;
	ElemType Data, E;
again:
	menu();    //打印菜单界面
	printf("\n\n");
	printf("%60s","请选择选项:");
	input=get_input();     //get_input函数用来筛选，过滤掉不合法的输入，最后将合法输入返回给input
	system("cls");
	if(input==-1073741510)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********请重新输入*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		goto again;
	}

	//在此规定count为-1的时候没有生成栈，并且使还没生成栈的时候不能进入其他选项
	if(stack.count == -1)
	{
		if(input!= 1 && input!=9)
		{
//			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%70s","****************************\n");
			printf("%70s","***栈还没生成，请先生成栈***\n");
			printf("%70s","****************************\n");
			system("pause");
			system("cls");
			goto again;
		}
	}

	switch(input)
	{
	case 1:
		initLStack(&stack);  //生成栈
		goto again;
	case 2:
		isEmptyLStack(&stack);  //判断是否为空栈
		goto again;
	case 3:
		getTopLStack(&stack,&E);   //得到栈顶元素
		goto again;
	case 4:
		clearLStack(&stack);   //清空栈
		goto again;
	case 5:
		destroyLStack(&stack);  //销毁栈
		goto again;
	case 6:
		LStackLength(&stack,&Length);    //计算栈的长度
		goto again;
	case 7:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","****请输入你想推入栈的值:***\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		printf("\n\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%60s","请输入:");
		Data=get_input();      //使用Data接收合法返回值
		if(Data==-1073741510)     //若返回此值，则输入不正确，使用户重新输入
		{
			goto again;
		}
		pushLStack(&stack,Data);
		goto again;
	case 8:
		popLStack(&stack,&Data);     //出栈
		goto again;
	case 9:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","***********已退出:**********\n");
		printf("%70s","****************************\n");
		break;
	default:
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","****输入错误，请重新输入:***\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		goto again;
	}
}
