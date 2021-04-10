#include <stdio.h>
#include <stdlib.h>
#include "self.h"
#include "LQueue.h"

void InitLQueue(LQueue *Q)
{
	Q->rear=(Node *)malloc(sizeof(Node));
	Q->front=(Node *)malloc(sizeof(Node));  //分配内存空间
	Q->front->data=Q->rear->data=NULL;
	Q->front=Q->rear;
	Q->rear->next=NULL;   //尾指针指向NULL
	Q->length=0;
}
Status EnLQueue(LQueue *Q, void *data)
{
	printf("---------------------------\n");
	printf("    请输入你想入队的值\n");
	printf("---------------------------\n");

	Q->rear->next=(Node *)malloc(sizeof(Node));  //分配空间
	Q->rear=Q->rear->next;   //为指针往后指
	Q->rear->data=malloc(32);
	scanf("%s",Q->rear->data);
	Q->rear->next=NULL;
	Q->length++;     //入队成功，长度加一
	system("cls");
	printf("---------------------------\n");
	printf("        入队成功\n");
	printf("---------------------------\n\n");
	system("pause");
	return TRUE;

}
Status DeLQueue(LQueue *Q)
{
	Node *p;  //用于保存出队列的结点的地址并释放

	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("    队列已空，无法出队\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	p=Q->front->next;
	Q->front->next=Q->front->next->next;  //头指针往后指，跳过出队列结点
	free(p);
	Q->length--;
	if(Q->length == 0)
	{
		Q->rear=Q->front;    //全部出队，头尾再次指向相同
		Q->rear->next=NULL;
	}
	printf("---------------------------\n");
	printf("        出队成功\n");
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
	printf("        队列已销毁\n");
	printf("---------------------------\n\n");
	Q->length=-1;
	system("pause");
}

Status IsEmptyLQueue(const LQueue *Q)
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("        队列为空\n");
		printf("---------------------------\n\n");
	}
	else
	{
		printf("---------------------------\n");
		printf("         队列未空\n");
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
		printf("     队列为空，无队头\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	printf("---------------------------\n");
	printf("      队头为:%s\n",Q->front->next->data);
	printf("---------------------------\n\n");
	system("pause");
	return TRUE;
}
int LengthLQueue(LQueue *Q)
{
	printf("---------------------------\n");
	printf("队列的长度为:%d\n",Q->length);
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
	Q->rear=Q->front;       //清空队列，头尾指针指向相同
	Q->rear->next=NULL;    //尾指针next指向NULL；
	Q->length=0;
	printf("---------------------------\n");
	printf("        队列已清空\n");
	printf("---------------------------\n\n");
	system("pause");
}
Status TraverseLQueue(const LQueue *Q, void (*foo)(void *q))
{
	if(Q->length == 0)
	{
		printf("---------------------------\n");
		printf("   队列为空，遍历无效\n");
		printf("---------------------------\n\n");
		system("pause");
		return TRUE;
	}
	Node *p;   //此结点用来遍历队列
	p=Q->front->next;
	printf("---------------------------\n");
	printf("队列为:");
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
