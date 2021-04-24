#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));//创建初始内存空间
	if(!s->top)  //创造失败时
	{
		return false;
	}
	s->top->next=NULL;
	s->count=0;            //栈的长度为0，表示空栈
	return true;
}

void push(LinkStack *s,Node p)
{
	LinkStackPtr new = (LinkStackPtr)malloc(sizeof(StackNode));

	if(s->count == 0)
	{
		s->top->next = new;
		new->temp = p;
		new->next = NULL;
		s->count++;
		return;
	}
	new->next = s->top->next;
	s->top->next = new;
	new->temp = p;
	s->count++;
}

NodePtr pop(LinkStack *s)
{
	NodePtr p = (NodePtr)malloc(sizeof(Node));
	*p = s->top->next->temp;
	s->top->next = s->top->next->next;
	s->count--;
	return p;
}


int get_input()
{
	char inputt, str[Putsize],str3[]="-1073741510";
	int i = 0, Input = 0;
	fflush(stdin);     // 清空输入缓存区，防止下次输入操作被影响
	scanf("%c", &inputt);
	if(inputt=='\n')   //若直接点击回车
	{
		strcpy(str, str3);
		goto end;
	}

	//通过循环逐个读取字符，直到读取到回车
	while (inputt != '\n')
	{
		if (i > Putsize)   //当输入的字符串位数过多，超过ElemType类型值的最大范围时
		{
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
			strcpy(str, str3);
			i = 0;
			goto end;
		}
		scanf("%c", &inputt);
	}
end:
	system("cls");
	fflush(stdin);
	Input = atoi(str);   //将字符串str转化为整型数字
	return Input;
}


void initqueue(Queuehead *que)
{
	que->count = 0;
	que->head = (QueuePtr)malloc(sizeof(Queue));
	que->head->next = NULL;
}


void inqueue(Queuehead *que,Node s)
{
	QueuePtr p = que->head;
	QueuePtr tempNode = (QueuePtr)malloc(sizeof(Queue));
	tempNode->Temp = s;
	tempNode->next = NULL;
	while(p->next)
	{
		p=p->next;
	}
	p->next = tempNode;
	que->count++;
}

NodePtr outqueue(Queuehead *que)
{
	NodePtr Out = (NodePtr)malloc(sizeof(Node));
	*Out = que->head->next->Temp;
	que->head->next = que->head->next->next;
	que->count--;
	return Out;
}

