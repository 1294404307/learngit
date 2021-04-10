#include <stdio.h>
#include <stdlib.h>
#include "self.h"
#include "LQueue.h"
int main()
{
	int input;
	void *E=0;
	char temp;
	LQueue queue;
	queue.length=-1;    // 长度-1作为没有生成队列的标志
again:
	system("cls");
	menu();
	printf("请选择:");
	input=get_input();

	//若没有生成队列，则只能进行生成队列或者退出操作
	if(queue.length == -1)
	{
		if(input != 0 && input != 1)
		{
			printf("---------------------------\n");
			printf("     请先初始化队列\n");
			printf("---------------------------\n\n");
			system("pause");
			goto again;
		}
	}

	// 若已生成队列，则需要销毁队列后再初始化队列
	else
	{
		if(input == 1)
		{
			printf("----------------------------------------\n");
			printf("若需要再次初始化队列，请先将原队列销毁\n");
			printf("----------------------------------------\n\n");
			system("pause");
			goto again;
		}
	}
	system("cls");
	switch(input)
	{
	case 0:
		printf("---------------------------\n");
		printf("        退出程序\n");
		printf("---------------------------\n\n");
		break;
	case 1:
		InitLQueue(&queue);  //初始化队列
		printf("---------------------------\n");
		printf("         初始化成功\n");
		printf("---------------------------\n\n");
		system("pause");
		goto again;
	case 2:
		DestoryLQueue(&queue);   //销毁队列
		goto again;

	case 3:
		IsEmptyLQueue(&queue);   //判断队列是否为空
		goto again;
	case 4:
		GetHeadLQueue(&queue,E);   //得到队头元素
		goto again;
	case 5:
		LengthLQueue(&queue);   //得到队列长度
		goto again;
	case 6:
		EnLQueue(&queue, &temp);   //入队列
		goto again;
	case 7:
		DeLQueue(&queue);    //出队列
		goto again;
	case 8:
		ClearLQueue(&queue);   //清空队列
		goto again;
	case 9:
		TraverseLQueue(&queue, &LPrint);  //遍历队列并打印
		goto again;
	default:
		system("cls");
		printf("---------------------------\n");
		printf("    输入错误，重新输入\n");
		printf("---------------------------\n\n");
		system("pause");
		goto again;
	}
    return 0;
}
