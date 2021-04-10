#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"

void InitAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;   //��ʼ�����У�ͷβָ����ͬ
	Q->length=0;
}

void DestoryAQueue(AQueue *Q)
{
	while (Q->length != 0)
	{
		Q->data[Q->front] = NULL;
		Q->front=(Q->front+1)%MAXQUEUE;
		Q->length--;
	}
	Q->length=-1;
	printf("---------------------------\n");
	printf("        ����������\n");
	printf("---------------------------\n");
	//printf("%s", Q->data[0]);
	system("pause");
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->length == MAXQUEUE)    //���г��ȴﵽ���ʱ
	{
		printf("---------------------------\n");
		printf("         ��������\n");
		printf("---------------------------\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("         ����δ��\n");
		printf("---------------------------\n");
	}
	system("pause");
	system("cls");
	return TRUE;
}
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length == 0)   //���г���Ϊ0ʱ
	{
		printf("---------------------------\n");
		printf("         ����Ϊ��\n");
		printf("---------------------------\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("        ���в�Ϊ��\n");
		printf("---------------------------\n");
	}
	system("pause");
	system("cls");
	return TRUE;
}

Status GetHeadAQueue(AQueue *Q, void *e)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("   ����Ϊ�գ��޶�ͷԪ��\n");
		printf("---------------------------\n");
	}
	else
	{
		e=Q->data[Q->front];
		printf("---------------------------\n");
		printf("    ��ͷԪ��Ϊ:%s\n",e);
		printf("---------------------------\n");
	}
	system("pause");
	system("cls");
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	printf("---------------------------\n");
	printf("      ���г���Ϊ:%d\n",Q->length);
	printf("---------------------------\n");
	system("pause");
	system("cls");
	return 0;
}
Status EnAQueue(AQueue *Q, void *data)
{

	//�����������޷�������
	if(Q->length == MAXQUEUE)
	{
		printf("---------------------------\n");
		printf("         ��������\n");
		printf("---------------------------\n");
		system("pause");
		system("cls");
		return TRUE;
	}
	Q->data[Q->rear]=malloc(32);
	printf("---------------------------\n");
	printf("     ����������е�ֵ\n");
	printf("---------------------------\n");
	scanf("%s",Q->data[Q->rear]);
	Q->rear=(Q->rear+1)%MAXQUEUE;   //ȡ����ʹ��rear��С��Զ���ᳬ������޶ȣ����ҿ���ͨ��������ʵ��ѭ��
	Q->length++;    //�����У����ȼ�1
	return TRUE;
}
Status DeAQueue(AQueue *Q)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("    ����Ϊ�գ��޷�����\n");
		printf("---------------------------\n");
		system("pause");
		system("cls");
		return TRUE;
	}
	free(Q->data[Q->front]);  //�ͷſռ�
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;   //�����г��ȼ�1
	printf("---------------------------\n");
	printf("        �����гɹ�\n");
	printf("---------------------------\n");
	if(Q->length == 0)
		Q->front = Q->rear;   //����Ϊ0��ͷβָ����ͬ
	system("pause");
	system("cls");
	return TRUE;
}

void ClearAQueue(AQueue *Q)
{
	while(Q->length!=0)
	{
		free(Q->data[Q->front]);
		Q->front=(Q->front+1)%MAXQUEUE;
		Q->length--;
	}
	Q->front=Q->rear;  //������գ�ͷβָ����ͬ
	printf("---------------------------\n");
	printf("          �����ѿ�\n");
	printf("---------------------------\n");
//	printf("%s",Q->data[0]);
	system("pause");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{

	//�ն��У����ñ���
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("          ����Ϊ��\n");
		printf("---------------------------\n");
		system("pause");
		return TRUE;
	}
	int i=Q->front,j=Q->length;
	printf("-----------------------------------\n");
	printf("����Ϊ:");
	while(j--)
	{
		foo(Q->data[i]);
		i=(i+1)%MAXQUEUE;
	}
	printf("\n-----------------------------------\n\n");
	system("pause");
	return TRUE;
}

void APrint(void *q)
{
	printf("%s  ",q);
}

//Status EnAQueue(AQueue *Q, void *data)
//{
//	if(Q->length == MAXQUEUE)
//	{
//		printf("-----------------\n\n");
//		printf("    ��������");
//		printf("-----------------\n");
//		system("pause");
//		system("cls");
//		return TRUE;
//	}
//	Q->data[Q->rear]=data;
//}
