#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"
#include "LinkStack.h"

int main()
{
	int input_1;
	while(1)
	{
		system("cls");
		menu();
		input_1=get_input();
		system("cls");
		switch(input_1)
		{
		case 1:
			testspeed();   //测试算法用时
			break;
		case 2:
			testmansmdata();   //测试多数组小数据算法的用时
			break;
		case 3:
			testcolor();     //颜色排序
			break;
		case 4:
			testfindknum();   //找到第k小的值
			break;
		case 5:
			testall();     //测试所有算法
			break;
		case 6:
			return 0;
		default:
			printf("--------------------------\n");
			printf("    输入错误，重新输入\n");
			printf("--------------------------\n");
			system("pause");
			break;
		}
	}
	return 0;
}
