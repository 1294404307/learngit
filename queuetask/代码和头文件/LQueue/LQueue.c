#include <stdio.h>
#include <stdlib.h>
#include "self.h"
#include "LQueue.h"

void InitLQueue(LQueue *Q)
{
	Q->rear=(Node *)malloc(sizeof(Node));
	Q->front=(Node *)malloc(sizeof(Node));  //�����ڴ�ռ�
	Q->front->data=Q->rear->data=NULL;
	Q->front=Q->rear;
	Q->rear->next=NULL;   //βָ��ָ��NULL
	Q->length=0;
}
Status EnLQueue(LQueue *Q, void *data)
{
	printf("---------------------------\n");
	printf("    ������������ӵ�ֵ\n");
	printf("---------------------------\n");

	Q->rear->next=(Node *)malloc(sizeof(Node));  //����ռ�
	Q->rear=Q->rear->next;   //Ϊָ������ָ
	Q->rear->data=malloc(32);
	scanf("%s",Q->rear->data);
	Q->rear->next=NULL;
	Q->length++;     //��ӳɹ������ȼ�һ
	system("cls");
	printf("---------------------------\n");
	printf("        ��ӳɹ�\n");
	printf("---------------------------\n\n");
	system("pause");
	return TRUE;

}
Status DeLQueue(LQueue *Q)
{
	Node *p;  //���ڱ�������еĽ��ĵ�ַ���ͷ�

	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("    �����ѿգ��޷�����\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	p=Q->front->next;
	Q->front->next=Q->front->next->next;  //ͷָ������ָ�����������н��
	free(p);
	Q->length--;
	if(Q->length == 0)
	{
		Q->rear=Q->front;    //ȫ�����ӣ�ͷβ�ٴ�ָ����ͬ
		Q->rear->next=NULL;
	}
	printf("---------------------------\n");
	printf("        ���ӳɹ�\n");
	printf("---------------------------\n\n");
	system("pause");
//	printf("%s",Q->front->next->data);
	return TRUE;

}

void DestoryLQueue(LQueue *Q)
{
	while(Q->length--)
	{
		free(Q->front->next);
		Q->front->next=Q->front->next->next;
	}
	printf("---------------------------\n");
	printf("        ����������\n");
	printf("---------------------------\n\n");
	Q->length=-1;
	system("pause");
}

Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("        ����Ϊ��\n");
		printf("---------------------------\n\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("         ����δ��\n");
		printf("---------------------------\n\n");

	}
	system("pause");
	return TRUE;
}
Status GetHeadLQueue(LQueue *Q, void *e)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("     ����Ϊ�գ��޶�ͷ\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	printf("---------------------------\n");
	printf("      ��ͷΪ:%s\n",Q->front->next->data);
	printf("---------------------------\n\n");
	system("pause");
	return TRUE;
}
int LengthLQueue(LQueue *Q)
{
	printf("---------------------------\n");
	printf("���еĳ���Ϊ:%d\n",Q->length);
	printf("---------------------------\n\n");
	system("pause");
	return 0;
}
void ClearLQueue(LQueue *Q)
{
	while(Q->length--)
	{
		free(Q->front->next->data);

		Q->front->next=Q->front->next->next;
	}
	Q->rear=Q->front;       //��ն��У�ͷβָ��ָ����ͬ
	Q->rear->next=NULL;    //βָ��nextָ��NULL��
	Q->length=0;
	printf("---------------------------\n");
	printf("        ���������\n");
	printf("---------------------------\n\n");
	system("pause");
}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("   ����Ϊ�գ�������Ч\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	Node *p;   //�˽��������������
	p=Q->front->next;
	printf("---------------------------\n");
	printf("����Ϊ:");
	do
	{
		foo(p->data);
		p=p->next;
	}while(p);
	printf("\n---------------------------\n\n");
	system("pause");
	return TRUE;
}
void LPrint(void *q)
{
	printf("%s  ",q);
}
