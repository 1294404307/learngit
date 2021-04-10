#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"

void InitAQueue(AQueue *Q)
{
	Q->front=Q->rear=0;   //初始化队列，头尾指向相同
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
	printf("        队列已销毁\n");
	printf("---------------------------\n");
	//printf("%s", Q->data[0]);
	system("pause");
}

Status IsFullAQueue(const AQueue *Q)
{
	if(Q->length == MAXQUEUE)    //队列长度达到最大时
	{
		printf("---------------------------\n");
		printf("         队列已满\n");
		printf("---------------------------\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("         队列未满\n");
		printf("---------------------------\n");
	}
	system("pause");
	system("cls");
	return TRUE;
}
Status IsEmptyAQueue(const AQueue *Q)
{
	if(Q->length == 0)   //队列长度为0时
	{
		printf("---------------------------\n");
		printf("         队列为空\n");
		printf("---------------------------\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("        队列不为空\n");
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
		printf("   队列为空，无队头元素\n");
		printf("---------------------------\n");
	}
	else
	{
		e=Q->data[Q->front];
		printf("---------------------------\n");
		printf("    队头元素为:%s\n",e);
		printf("---------------------------\n");
	}
	system("pause");
	system("cls");
	return TRUE;
}

int LengthAQueue(AQueue *Q)
{
	printf("---------------------------\n");
	printf("      队列长度为:%d\n",Q->length);
	printf("---------------------------\n");
	system("pause");
	system("cls");
	return 0;
}
Status EnAQueue(AQueue *Q, void *data)
{

	//队列已满，无法进队列
	if(Q->length == MAXQUEUE)
	{
		printf("---------------------------\n");
		printf("         队列已满\n");
		printf("---------------------------\n");
		system("pause");
		system("cls");
		return TRUE;
	}
	Q->data[Q->rear]=malloc(32);
	printf("---------------------------\n");
	printf("     请输入入队列的值\n");
	printf("---------------------------\n");
	scanf("%s",Q->data[Q->rear]);
	Q->rear=(Q->rear+1)%MAXQUEUE;   //取余数使得rear大小永远不会超过最大限度，并且可以通过余数来实现循环
	Q->length++;    //进队列，长度加1
	return TRUE;
}
Status DeAQueue(AQueue *Q)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("    队列为空，无法出队\n");
		printf("---------------------------\n");
		system("pause");
		system("cls");
		return TRUE;
	}
	free(Q->data[Q->front]);  //释放空间
	Q->front=(Q->front+1)%MAXQUEUE;
	Q->length--;   //出队列长度减1
	printf("---------------------------\n");
	printf("        出队列成功\n");
	printf("---------------------------\n");
	if(Q->length == 0)
		Q->front = Q->rear;   //长度为0，头尾指向相同
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
	Q->front=Q->rear;  //队列清空，头尾指向相同
	printf("---------------------------\n");
	printf("          队列已空\n");
	printf("---------------------------\n");
//	printf("%s",Q->data[0]);
	system("pause");
}

Status TraverseAQueue(const AQueue *Q, void (*foo)(void *q))
{

	//空队列，不用遍历
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("          队列为空\n");
		printf("---------------------------\n");
		system("pause");
		return TRUE;
	}
	int i=Q->front,j=Q->length;
	printf("-----------------------------------\n");
	printf("队列为:");
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
//		printf("    队列已满");
//		printf("-----------------\n");
//		system("pause");
//		system("cls");
//		return TRUE;
//	}
//	Q->data[Q->rear]=data;
//}
