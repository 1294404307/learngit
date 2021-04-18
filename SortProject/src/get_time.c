#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include "LinkStack.h"
#include <time.h>

int inserttime(int *a,int num)
{
	struct timeb ts1,ts2;

	ftime(&ts1);  //�õ����������㷨ǰ��ʱ��
	insertSort(a,num);
	ftime(&ts2);   //�õ����������㷨���ʱ��

	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);   //�õ�����ӿ�ʼ���������ĺ���
	return sec;

}

int insertSumtime(int *a,int num)
{
	struct timeb ts1,ts2;

	ftime(&ts1);  //�õ����������㷨ǰ��ʱ��
	insertSort(a,num);
	ftime(&ts2);   //�õ����������㷨���ʱ��

	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);   //�õ�����ӿ�ʼ���������ĺ���
	return sec;

}

int mergetime(int *a,int num)
{
	struct timeb ts1,ts2;

	ftime(&ts1);
	int *temp=(int *)malloc(num * sizeof(int *));
	MergeSort(a,0,num-1,temp);
	ftime(&ts2);

	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);
	return sec;
}

int QuickSort_Recurtime(int *a,int num)
{
	struct timeb ts1,ts2;
	ftime(&ts1);

	QuickSort_Recursion(a,0,num-1);
	ftime(&ts2);

	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);
	return sec;

}

int QuickSorttime(int *a,int num)
{
	struct timeb ts1,ts2;
	ftime(&ts1);
	QuickSort(a,num);
	ftime(&ts2);
	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);
	return sec;

}

int countsorttime(int *a,int num)
{
	struct timeb ts1,ts2;
	int max = get_max(a,num);
	ftime(&ts1);

	CountSort(a,num,max);

	ftime(&ts2);
	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);
	return sec;
}

int RadixCountSorttime(int *a,int num)
{
	struct timeb ts1,ts2;
	ftime(&ts1);
	RadixCountSort(a,num);
	ftime(&ts2);
	int sec =(ts2.time - ts1.time)* 1000 + (ts2.millitm - ts1.millitm);
	return sec;
}
