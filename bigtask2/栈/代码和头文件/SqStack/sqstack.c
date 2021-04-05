#include <stdio.h>
#include <stdlib.h>
#include "SqStack.h"

Status initStack(SqStack *s,int sizes)
{
	s->elem=(ElemType *)malloc(sizes*sizeof(ElemType));    //给s->elem创造初始内存空间
	if(! s->elem)   //创造失败时
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*********初始化失败*********\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
		return ERROR;
	}
	s->top=-1;      //表示空栈
	s->size=sizes;     //初始化栈的最大长度
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","*********初始化成功*********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	//*(s->elem)=NULL；
	return SUCCESS;
}

Status isEmptyStack(SqStack *s)
{
	if(s->top == -1)   //表示空栈时
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

Status getTopStack(SqStack *s,ElemType *e)
{
	if(s->top==-1)
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","******空栈，无栈顶元素******\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		(*e)=*((s->elem)+(s->top));     //将栈顶元素的赋值
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("******栈顶元素为:%-d  *******\n",*e);
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}

Status clearStack(SqStack *s)
{
	//通过循环逐步清除栈
	while(s->top!=-1)
	{
		free((s->elem)+(s->top));
		s->top--;      //清除一次栈顶向下指一次
	}
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********栈已清空**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status destroyStack(SqStack *s)
{
	while(s->top!=-1)
	{
		free((s->elem)+(s->top));
		s->top--;
	}
	s->top=-2;          //表示栈已销毁，需要重新生成
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%70s","**********栈已销毁**********\n");
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status stackLength(SqStack *s,int *length)
{
	(*length)=(s->top) + 1;    //s->top表示下标，长度等于下标加1
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s","****************************\n");
	printf("%42s","*");
	printf("******栈的长度为:%d ********\n",*length);
	printf("%70s","****************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status pushStack(SqStack *s,ElemType data)
{
	(s->top)++;
	if(s->top==0)
	{
		s->elem=(ElemType *)malloc(initsize*sizeof(ElemType));    //若生成栈后栈被不小心销毁，则再次分配内存空间
	}

	//若栈满，给栈分配更多空间
	if(s->top>= s->size)
	{
		s->elem=(ElemType *)realloc(s->elem,(s->size + addsize)*sizeof(ElemType));
		s->size+=addsize;
	}
	(*((s->elem)+(s->top)))=data;
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%70s", "***************************\n");
	printf("%70s", "**********已进栈***********\n");
	printf("%70s", "***************************\n");
	system("pause");
	system("cls");
	return SUCCESS;
}

Status popStack(SqStack *s,ElemType *data)
{
	if(s->top==-1)    //因为出栈导致的栈被清空的情况
	{
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%70s","*****栈已清空，无法出栈*****\n");
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	else
	{
		(*data)=*((s->elem)+(s->top));
		(s->top)--;
		free((s->elem)+((s->top)+1));
		printf("\n\n\n\n\n\n\n\n\n\n\n\n");
		printf("%70s","****************************\n");
		printf("%42s","*");
		printf("*******出栈元素为:%d *******\n",*data);
		printf("%70s","****************************\n");
		system("pause");
		system("cls");
	}
	return SUCCESS;
}
