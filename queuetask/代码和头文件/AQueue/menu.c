#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "self.h"

void menu()
{
	printf("--------------------\n");
	printf("0、退出程序\n");
	printf("1、初始化一个队列\n");
	printf("2、销毁队列\n");
	printf("3、检查队列是否已满\n");
	printf("4、检查队列是否为空\n");
	printf("5、查看队头元素\n");
	printf("6、确定队列长度\n");
	printf("7、入队\n");
	printf("8、出队\n");
	printf("9、清空队列\n");
	printf("10、遍历队列\n");
	printf("--------------------\n");
}
