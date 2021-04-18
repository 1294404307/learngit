#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include "qgsort.h"

void writetofile(const char *FiName,int arr[],int num)
{
	FILE *fp = fopen(FiName,"w");
	if(fp == NULL)
	{
		printf("打开文件失败\n");
		exit(0);
	}
	int i;
	for(i=0;i<num;i++)
	{
		fprintf(fp,"%d ",arr[i]);
	}
	fclose(fp);
}

void readfromfile(const char *FiName,int arr[],int num)
{
	FILE *fp=fopen(FiName,"r");
	if(fp == NULL)
	{
		fp = fopen(FiName,"w+");
	}
	int i;
	for(i=0;i<num;i++)
	{
		fscanf(fp,"%d ",&arr[i]);
	}
	fclose(fp);
}


