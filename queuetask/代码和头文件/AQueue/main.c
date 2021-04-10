#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#include "AQueue.h"
#include "self.h"
int main()
{
	int input;
	void *E=0;
	char temp;
	AQueue queue;
	queue.length=-1;    // ����-1��Ϊû�����ɶ��еı�־
again:
	system("cls");
	menu();
	printf("��ѡ��:");
	input=get_input();

	//��û�����ɶ��У���ֻ�ܽ������ɶ��л����˳�����
	if(queue.length == -1)
	{
		if(input != 0 && input != 1)
		{
			printf("---------------------------\n");
			printf("     ���ȳ�ʼ������\n");
			printf("---------------------------\n\n");
			system("pause");
			goto again;
		}
	}

	// �������ɶ��У�����Ҫ���ٶ��к��ٳ�ʼ������
	else
	{
		if(input == 1)
		{
			printf("----------------------------------------\n");
			printf("����Ҫ�ٴγ�ʼ�����У����Ƚ�ԭ��������\n");
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
		printf("        �˳�����\n");
		printf("---------------------------\n\n");
		break;
	case 1:
		InitAQueue(&queue);  //��ʼ������
		printf("---------------------------\n");
		printf("         ��ʼ���ɹ�\n");
		printf("---------------------------\n\n");
		system("pause");
		goto again;
	case 2:
		DestoryAQueue(&queue);   //���ٶ���
		goto again;
	case 3:
		IsFullAQueue(&queue);   //�ж϶����Ƿ�����
		goto again;
	case 4:
		IsEmptyAQueue(&queue);   //�ж϶����Ƿ�Ϊ��
		goto again;
	case 5:
		GetHeadAQueue(&queue,E);   //�õ���ͷԪ��
		goto again;
	case 6:
		LengthAQueue(&queue);   //�õ����г���
		goto again;
	case 7:
		EnAQueue(&queue, &temp);   //�����
		goto again;
	case 8:
		DeAQueue(&queue);    //������
		goto again;
	case 9:
		ClearAQueue(&queue);   //��ն���
		goto again;
	case 10:
		TraverseAQueue(&queue, &APrint);  //�������в���ӡ
		goto again;
	default:
		system("cls");
		printf("---------------------------\n");
		printf("    ���������������\n");
		printf("---------------------------\n\n");
		system("pause");
		goto again;
	}
	return 0;
}
