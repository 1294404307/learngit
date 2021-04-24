#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_sort_tree.h"

Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));//������ʼ�ڴ�ռ�
	if(!s->top)  //����ʧ��ʱ
	{
		return false;
	}
	s->top->next=NULL;
	s->count=0;            //ջ�ĳ���Ϊ0����ʾ��ջ
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
	fflush(stdin);     // ������뻺��������ֹ�´����������Ӱ��
	scanf("%c", &inputt);
	if(inputt=='\n')   //��ֱ�ӵ���س�
	{
		strcpy(str, str3);
		goto end;
	}

	//ͨ��ѭ�������ȡ�ַ���ֱ����ȡ���س�
	while (inputt != '\n')
	{
		if (i > Putsize)   //��������ַ���λ�����࣬����ElemType����ֵ�����Χʱ
		{
			strcpy(str, str3);  //��str3��Ĵ��󷵻�ֵ��str������һ������ֵ���Ա�ʾ�������
			i = 0;
			goto end;  //�������ʱ��ֱ���˳�����
		}

		//���û���Ҫ���븺���������űض�ֻ�ܳ������ַ������±�Ϊ0��λ�ã����������ж�
		if (i==0)
		{
			if(inputt == '-')
			{
				str[i++]='-';
				str[i]='\0';
				scanf("%c", &inputt);
			}
		}

		//ͨ��ASCII��ֵɸѡ���������ִ������ַ����У��������֣���Ϊ�Ƿ�����
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
	Input = atoi(str);   //���ַ���strת��Ϊ��������
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

