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
	char cgstr[Size];    //����ת������ַ���
	printf("ת�����Ϊ:\n");
	if (line == 0)    //��ӡ��һ�е�ʱ�򣬵�һ����line = 0��ʾ
	{
		for (down = 0; down < len; down = down + 2 * (num - 1))
		{
			printf("%c  ", str[down]);
			cgstr[cgdown++] = str[down];     //���մ�ӡ���ַ�
			blank = num - 2;    //�ո������������Ĺ�ϵ
			while (blank--)
				printf("%c  ", ' ');
		}
		printf("\n\n");
	}

	//��ӡ�ڶ��е������ڶ��е����
	for (line = 1; line < num-1; line++)
	{
		for (down = line; down < len; down = down + 2 * line)
		{
			printf("%c  ", str[down]);
			cgstr[cgdown++] = str[down];
			forblank = num - 2 - line;     //�ո����������������������Ĺ�ϵ
			while ((forblank--) > 0)
			{
				printf("%c  ", ' ');
			}
			down=down +  2 * (num - line - 1);    //�õ�ͬ����һ����Ҫ��ӡ���ַ�����ԭ�ַ����е��±�
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

	//��ӡ���һ�е����
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
	cgstr[cgdown] = '\0';   //�ַ��������ı�־

	printf("\n\n\nת������ַ���Ϊ:\n");
	n = 0;
	while (cgstr[n] != '\0')
	{
		printf("%c",cgstr[n++]);
	}
	printf("\n\n\n");
	system("pause");
	return 0;
}
