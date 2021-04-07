#define _CRT_SECURE_NO_WARNINGS 1
#define _CRT_SILENCE_NONCONFORMING_TGMATH_H
#include <stdio.h>
#include <stdlib.h>
//#include "get_input.h"
#include <string.h>
#include "change.h"
char *convert(char *str, int num)
{
	int down = 0, line = 0, forblank = 0, lastblank = 0, blank = 0, cgdown = 0,n;
	int len = strlen(str);
	char cgstr[Size];    //接收转换后的字符串
	printf("转换结果为:\n");
	if (line == 0)    //打印第一行的时候，第一行用line = 0表示
	{
		for (down = 0; down < len; down = down + 2 * (num - 1))
		{
			printf("%c  ", str[down]);
			cgstr[cgdown++] = str[down];     //接收打印的字符
			blank = num - 2;    //空格数与总行数的关系
			while (blank--)
				printf("%c  ", ' ');
		}
		printf("\n\n");
	}

	//打印第二行到倒数第二行的情况
	for (line = 1; line < num-1; line++)
	{
		for (down = line; down < len; down = down + 2 * line)
		{
			printf("%c  ", str[down]);
			cgstr[cgdown++] = str[down];
			forblank = num - 2 - line;     //空格数与总行数和现在行数的关系
			while ((forblank--) > 0)
			{
				printf("%c  ", ' ');
			}
			down=down +  2 * (num - line - 1);    //得到同行下一个需要打印的字符的在原字符串中的下标
			if (down < len)
			{
				lastblank = line - 1;
				printf("%c  ",str[down]);
				cgstr[cgdown++] = str[down];
				while ((lastblank--) > 0)
				{
					printf("%c  ", ' ');
				}
			}

		}
		printf("\n\n");
	}

	//打印最后一行的情况
	if (line == num - 1)
	{
		for (down = num - 1; down < len; down = down + 2 * line)
		{
			printf("%c  ", str[down]);
			cgstr[cgdown++] = str[down];
			blank = num - 2;
			while (blank--)
				printf("%c  ", ' ');
		}
	}
	cgstr[cgdown] = '\0';   //字符串结束的标志

	printf("\n\n\n转换后的字符串为:\n");
	n = 0;
	while (cgstr[n] != '\0')
	{
		printf("%c",cgstr[n++]);
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}
