#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include "LinkStack.h"
#include <stdio.h>
#include <stdlib.h>
Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));   //创建初始内存空间
	if(!s->top)  //创造失败时
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********初始化失败*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return ERROR;
	}
	s->top->next=NULL;
	s->count=0;            //栈的长度为0，表示空栈
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","*********初始化成功*********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status isEmptyLStack(LinkStack *s)
{
	if(s->count==0)     //栈长度为0时
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","**********栈为空栈**********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********栈不为空栈*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}

Status getTopLStack(LinkStack *s,ElemType *e)
{
	if(s->count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******空栈，无栈顶元素******\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return SUCCESS;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******栈顶元素为:%d ********\n",s->top->data);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status clearLStack(LinkStack *s)
{
	StackNode *temp;   //用来临时储存栈顶的下一个

	//循环逐步清除栈中的元素，ount=0时表示清除完毕
	while(s->count!=0)
	{
	temp=s->top->next;
	free(s->top);
	s->top=temp;
	s->count--;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********栈已清空**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status destroyLStack(LinkStack *s)
{
	StackNode *temp;

	//循环逐步释放栈中的元素
	while(s->count!=0)
	{
	temp=s->top->next;
	free(s->top);
	s->top=temp;
	s->count--;
	}
	s->count=-1;  //将count等于-1表示已经销毁
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********栈已销毁**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}
Status LStackLength(LinkStack *s,int *length)
{
	(*length)=s->count;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******栈的长度为:%d  *******\n",*length);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->count==0)   ////若生成栈后栈被不小心销毁，则再次分配内存空间
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
	}
	else
	{
		LinkStack temp;
		temp.top=(LinkStackPtr)malloc(sizeof(StackNode));     //进一次栈，需要多分配一个内存空间
		temp.top->data = data;
		temp.top->next=s->top;
		s->top=temp.top;
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s", "***************************\n");
	printf("%70s", "**********已进栈***********\n");
	printf("%70s", "***************************\n");
	system("pause");
	system("cls");
	s->count++;
	return SUCCESS;
}

Status popLStack(LinkStack *s,ElemType *data)
{
	if(s->count == 0)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*****栈已清空，无法出栈*****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		printf("栈已清空，无法出栈\n");
	}
	else
	{
		(*data)=s->top->data;
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("*******出栈元素为:%d *******\n",*data);
		printf("%70s","****************************\n");
		//free(s->top);
		s->top=s->top->next;   //出栈后栈顶往下移
		s->count--;
		system("pause");
		system("cls");
	}
	return SUCCESS;
}
