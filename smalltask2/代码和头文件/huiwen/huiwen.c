#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "huiwen.h"
void huiwen()
{
	char str[size];
	int i,len,Max,j,k,x,y,maxlen_1=1,maxlen_2=1,last_1=0,last_2=0,former_1=0,former_2=0;
again:
	system("cls");
	printf("\n\n\n\n\n\n\n\n\n\n\n\n");
	printf("%65s","请输入一串字符串(退出请输入#):");
	scanf("%s", str);
	system("cls");
	while(str[0]!='#')   //输入#时退出程序
	{
		Max=1,maxlen_1=1,maxlen_2=1,last_1=0,last_2=0,former_1=0,former_2=0;   //每次输入完字符串就将需要用到的数据重新初始化
		len=strlen(str);      //得到字符串长度
		for(i=0;i<len;i++)      //找奇数回文字符串
		{
			j=i-1;    //奇数字符串是回文的话至少长度为三
			k=i+1;
			while(j>=0 && k<len && str[j]==str[k])  //先找到最小的是回文的字符串，再判断更多的
			{

				//用来保留最长回文字符串的位置和长度
				if (k - j + 1 > maxlen_1)
				{
					maxlen_1 = k - j + 1;
					last_1 = k;
					former_1 = j;
				}
				j--;     //判断更多的字符
				k++;
			}
		}
		for(i=0;i<len;i++)   //偶数回文字符串找法
		{
			x=i;  //判断相邻两字符是否回文
			y=i+1;

			//再判断更广区域字符是否回文
			while(x>=0 && y<len && str[x]==str[y])
			{
				if (y - x + 1 > maxlen_2)
				{
					maxlen_2 = y - x + 1;
					last_2 = y;
					former_2 = x;
				}
				x--;
				y++;
			}
		}
		Max = Max > maxlen_1 ? Max : maxlen_1;     //取回文字符串最大长度
		Max = Max > maxlen_2 ? Max : maxlen_2;
		if (Max == 1)     //单个字符就是一个回文字符，但不是字符串，故没有找到回文字符串
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%60s","没有找到回文字符串");
		}
		else
		{
			system("cls");
			printf("\n\n\n\n\n\n\n\n\n\n\n\n");
			printf("%60s","最长回文字符串为:");
			if (Max == maxlen_1)    //奇数回文字符串长度最大时
			{
				while (former_1 <= last_1)
				{
					printf("%c", str[former_1++]);
				}
			}
			else     //偶数回文字符串长度最大时
			{
				while (former_2 <= last_2)
				{
					printf("%c", str[former_2++]);
				}
			}
		}
		printf("\n");
		system("pause");
		goto again;
    }
}
