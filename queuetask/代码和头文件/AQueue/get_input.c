#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "self.h"
int get_input()
{
	char inputt, str[Putsize],str3[]="-1073741510";
	int i = 0, Input = 0;
	fflush(stdin);     // ������뻺��������ֹ�´����������Ӱ��
	scanf("%c", &inputt);
	if(inputt=='\n')   //��ֱ�ӵ���س�
	{
		strcpy(str, str3);
		goto end;
	}

	//ͨ��ѭ�������ȡ�ַ���ֱ����ȡ���س�
	while (inputt != '\n')
	{
		if (i > Putsize)   //��������ַ���λ�����࣬����ElemType����ֵ�����Χʱ
		{
			strcpy(str, str3);  //��str3��Ĵ��󷵻�ֵ��str������һ������ֵ���Ա�ʾ�������
			i = 0;
			goto end;  //�������ʱ��ֱ���˳�����
		}

		//���û���Ҫ���븺���������űض�ֻ�ܳ������ַ������±�Ϊ0��λ�ã����������ж�
		if (i==0)
		{
			if(inputt == '-')
			{
				str[i++]='-';
				str[i]='\0';
				scanf("%c", &inputt);
			}
		}

		//ͨ��ASCII��ֵɸѡ���������ִ������ַ����У��������֣���Ϊ�Ƿ�����
		if (inputt >= 48 && inputt <= 57)
		{
			str[i++] = inputt;
			str[i] = '\0';
		}
		else
		{
			strcpy(str, str3);
			i = 0;
			goto end;
		}
		scanf("%c", &inputt);
	}
end:
	system("cls");
	fflush(stdin);
	Input = atoi(str);   //���ַ���strת��Ϊ��������
	return Input;
}
