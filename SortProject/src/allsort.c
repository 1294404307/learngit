#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include "LinkStack.h"
#include <time.h>

void menu()
{
	printf("                   ѡ��\n");
	printf("------------------------------------------------\n");
	printf("1�����������㷨Ч��       2������С�������㷨Ч��\n\n");
	printf("3����ɫ����               4���ҵ���KС��ֵ\n\n");
	printf("5�����Ը��㷨������     6���˳� \n");
	printf("------------------------------------------------\n\n");
}

void print(int arr[],int n)   //��ӡ
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

int get_max(int arr[],int len)    //�õ�����������ֵ
{
	int max=0;
	for(int i=0;i<len;i++)
	{
		max=(max > arr[i]) ? max : arr[i];
	}
	return max;
}

int get_long(int arr[],int len)    //�õ����������λ��
{
	int length=0,i,j,m,n=10;
	for(i=0;i<len;i++)
	{
		m=1;
		for(j=1,n=10;m != 0;n=n*10,j++)
		{
			m = arr[i] / n;     //ͨ��ȡģ���ж�λ��
		}
		length = length > (j-1) ? length : (j-1);
	}
	return length;
}

void insertSort(int *a,int n)
{
	int i,j;
	for(i=1;i<n;i++)
	{
		j=i-1;
		int temp=*(a+i);

		//�ҵ���ӽ�����������ǰ�����
		while(temp < *(a+j) && j >= 0)
		{
			*(a+j+1) = *(a+j);
			j--;
		}
		*(a+j+1)=temp;
	}
}

void CountSort(int *a, int size , int max)
{
	int count=0,i,j;
	int *arrTemp = (int *)malloc(size * sizeof(int *));

	//��arrTempӵ�������ֵ
	for(i=0;i<size;i++)
		arrTemp[i]=*(a+i);
	int *temp = (int *)malloc((max+1) * sizeof(int *));
	temp[0]=0;
	for(i=0;i<max+1;i++)
	{
		count = 0;
		for(j=0;j<size;j++)
		{
			//�д���������������
			if(*(a+j) == i)
				count++;
		}
		if(i == 0)
			temp[0]=count;
		else
			temp[i]=temp[i-1]+count;  //�������õ�С�ڵ����������������
	}

	//���ı������鸳��ԭ����
	for(size=size-1;size>=0;size--)
	{
		*(a + temp[arrTemp[size]]-1)=arrTemp[size];
		temp[arrTemp[size]]-- ;
	}
}

void RadixCountSort(int *a,int size)
{
	int i,j,n=10,m,*temp,cgtemp;
	temp=(int *)malloc(size * sizeof(int *));

	int maxlong = get_long(a,size);  //�õ��λ��

	//��ʮ�ٵȵ�λ�����ж�
	for(i=1;i <= maxlong;n=n*10,i++)
	{
		for(j=0,m=0;j<size;j++,m++)
		{
			temp[m] =*(a+j) % n;  //��������
		}
		QuickSort(temp,size);   //���������������鰴˳������
		for(m=0;m<size;m++)
		{
			for(j=m;j<size;j++)
			{
				//ͨ���ж������Ƿ���ͬ����ԭ�����Ԫ�ظ���λ��
				if(temp[m] == *(a+j) % n )
				{
					cgtemp = *(a+m);
					*(a+m) = *(a+j);
					*(a+j) = cgtemp;
					break;
				}
			}
		}

	}
}

void ColorSort(int *a,int size)
{
	int p0=0,p=0,p2=size-1,temp;
	for(p=0;;p++)
	{
		if(*(a+p-1) == 2)   //���pǰһλ��Ϊ2����p����ԭ��λ�ò���
			p=p-1;
		if(*(a+p) == 2)
		{
			if(*(a+p2) == 2)  //�±�Ϊp2��ֵΪ2����p2��ǰ��
				p2--;
			else
			{
				temp=*(a+p);
				*(a+p)=*(a+p2);
				*(a+p2)=temp;
				p2--;
			}
		}

		//�±�Ϊp��Ӧ����ֵΪ0������ֵ��p0����
		if(*(a+p) == 0)
		{
			temp=*(a+p);
			*(a+p)=*(a+p0);
			*(a+p0)=temp;
			p0++;
		}
		if(p == p2)
			break;
	}
}

void MergeArray(int *a,int begin,int mid,int end,int *temp)
{
	int len,i,pl,pr;
	pl=begin;
	pr=mid+1;
	len=end - begin +1;
	i=0;
	while(pl <= mid && pr <= end)
	{

		//���������ͽ�����ʱ������temp��
		if(*(a+pl) < *(a+pr))
		{
			*(temp+i)=*(a+pl);
			pl++;
			i++;
		}
		else
		{
			*(temp+i)=*(a+pr);
			pr++;
			i++;
		}
	}

	//��ʣ�µ�ֵ�������
	while(pl <= mid)
	{
		*(temp+i) = *(a+pl);
		i++;
		pl++;
	}
	while(pr <= end)
	{
		*(temp+i) = *(a+pr);
		i++;
		pr++;
	}

	//������ƴ������
	for(i=0;i<len;i++)
	{
		*(a +(i + begin))=*(temp + i);
	}
}

void MergeSort(int *a,int begin,int end,int *temp)
{
	int len=end - begin +1,sz,i,mid,l,r;

	//ͨ��ѭ�������黮�ֺ������ٹ鲢��һ��
	for(sz = 1;sz<len;sz+=sz)
	{
		for(i=0;i<len-sz;i+=2*sz)
		{
			l=i;
			r=i+2*sz;
			mid = i+sz -1;
			MergeArray(a,l,mid,(r-1 < len-1) ? (r-1):(len-1),temp);
		}
	}
}

void swap(int *a,int *b)   //����ֵ
{
	int temp;
	temp = *a;
	*a = *b;
	*b=temp;
}

int Partition(int *a, int begin, int end)
{
	int point =*(a+begin);
	while(begin < end)
	{

		//�ҵ���pointС��ֵ
		while(begin < end && *(a+end) >= point)
		{
			end--;
		}
		if(begin < end)
		{
			*(a+begin)=*(a+end);
		}

		//�ҵ���point���ֵ
		while(begin < end && *(a+begin) <= point)
		{
			begin++;
		}
		if(begin < end)
		{
			*(a+end) = *(a+begin);
		}
	}
	*(a+begin)=point;  //ȷ������λ��
	return begin;
}

void QuickSort_Recursion(int *a, int begin, int end)
{
	int point;
	if(begin >= end)
		return;
	point = Partition(a,begin,end);  //�õ�ÿ������
	QuickSort_Recursion(a,begin,point-1);
	QuickSort_Recursion(a,point+1,end);
}

Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));   //������ʼ�ڴ�ռ�
	if(!s->top)  //����ʧ��ʱ
	{
		return ERROR;
	}
	s->top->next=NULL;
	s->count=0;            //ջ�ĳ���Ϊ0����ʾ��ջ
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->count==0)   ////������ջ��ջ����С�����٣����ٴη����ڴ�ռ�
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
	}
	else
	{
		LinkStack temp;
		temp.top=(LinkStackPtr)malloc(sizeof(StackNode));     //��һ��ջ����Ҫ�����һ���ڴ�ռ�
		temp.top->data = data;
		temp.top->next=s->top;
		s->top=temp.top;
	}
	s->count++;
	return SUCCESS;
}

int popLStack(LinkStack *s)
{
	int data;
	data=s->top->data;
	s->top=s->top->next;   //��ջ��ջ��������
	s->count--;
	return data;
}

void QuickSort(int *a,int size)
{
	LinkStack s;
	int left=0,right = size - 1;

	 //�ݹ��ʵ��������ջ����ջ��ջ����������ջ�ķ�������ʵ�ֵݹ�
	initLStack(&s);
	pushLStack(&s,left);
	pushLStack(&s,right);
	while(s.count != 0)
	{
		right = popLStack(&s);
		left = popLStack(&s);

		int point = Partition(a,left,right);
		if((point - 1) > left)
		{
			pushLStack(&s,left);
			pushLStack(&s,(point - 1));
		}
		if((point + 1) < right)
		{
			pushLStack(&s,(point + 1));
			pushLStack(&s,right);
		}
	}
}

int get_knum(int *a,int left,int right,int k)
{
	int len = right - left + 1;
	if(left >= right || k > len)
		return 0;
	int point = Partition(a,left,right);
	while(point != k-1)
	{
		if(point > k-1)
		{
			right = point - 1;     //�ұ߽�ı䣬�������ܵ���������
			point = Partition(a,left,right);
		}
		if(point < k-1)
		{
			left = point + 1;     //��߽�ı�
			point = Partition(a,left,right);
		}
	}
	return  *(a + point);
}



void testspeed()
{
	int t1,t2,t3,t4,t5,t6;
	int i,num,NumRange;
	srand((unsigned int)time(NULL));
	printf("---------------------------------------------------\n");
	printf("����������ɶ��ٸ����ٷ�Χ�ڵ�����(��ΧΪ0~32767)��\n");
	printf("---------------------------------------------------\n");
	printf("������:");
	num = get_input();
	printf("��Χ(��������):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("\n-----------------\n");
		printf("     �������\n");
		printf("-----------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("������Ч��Χ��������Ч������\n");
		printf("---------------------------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand()%NumRange + 1;
	}
	writetofile("data.txt",arr,num);
	printf("\n���ڼ��㣬���Ե�........\n");

	readfromfile("data.txt",arr,num);   // ���ļ��ж�ȡ����
	t1 = inserttime(arr,num);            //�õ�����ʹ��ʱ��

	printf("\n---------------------------------------\n");
	printf("       �������������ʱΪ��%dms\n",t1);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);              //��Ϊ�����arr���鱻�ı䣬�������´��ļ��ж�ȡ����
	t2 = mergetime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      �鲢���������ʱΪ��%dms\n",t2);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t3 = QuickSort_Recurtime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      �ݹ��������������ʱΪ��%dms\n",t3);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t4 = QuickSorttime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      �ǵݹ��������������ʱΪ��%dms\n",t4);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t5 = countsorttime(arr,num);

	printf("\n---------------------------------------\n");
	printf("        �������������ʱΪ��%dms\n",t5);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t6 = RadixCountSorttime(arr,num);

	printf("\n�Ҽ�����е���Ŷ�����Ե�......\n");

	printf("\n---------------------------------------\n");
	printf("        �����������������ʱΪ��%dms\n",t6);
	printf("---------------------------------------\n");
	system("pause");

}

void testcolor()
{
	int i,num;
	srand((unsigned int)time(NULL));
	printf("----------------------------\n");
	printf("����������ɶ��ٸ����ݣ�\n");
	printf("----------------------------\n");
	num = get_input();
	if(num == -1)
	{
		printf("----------------\n");
		printf("    �������\n");
		printf("----------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand() % 3;
	}
	printf("----------------\n");
	printf("  ����ԭ����Ϊ:\n");
	printf("----------------\n\n");
	print(arr,num);
	printf("\n\n----------------\n");
	printf("����������Ϊ:\n");
	printf("----------------\n\n");
	ColorSort(arr,num);           //��ɫ����
	print(arr,num);              //��ӡ�������
	printf("\n\n");
	system("pause");
}

void testfindknum()
{
	int i,num,k,NumRange;
	srand((unsigned int)time(NULL));
	printf("---------------------------------------------------\n");
	printf("����������ɶ��ٸ����ٷ�Χ�ڵ�����(��ΧΪ0~32767)��\n");
	printf("---------------------------------------------------\n");
	printf("������:");
	num = get_input();
	printf("��Χ(��������):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("--------------\n");
		printf("   �������\n");
		printf("--------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("   ������Ч��Χ��������Ч������\n");
		printf("---------------------------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand()%NumRange + 1;       //��������ɵ�����ֵ������
	}
	printf("--------------------\n");
	printf("   ����ԭ����Ϊ:\n");
	printf("--------------------\n\n");
	print(arr,num);
	printf("\n\n--------------------\n");
	printf("  �����ҵڼ�С������\n");
	printf("--------------------\n");
	k=get_input();
	if(k == -1)
	{
		printf("\n---------------\n");
		printf("   �������\n");
		printf("---------------\n");
		system("pause");
		return;
	}
	if(k <= 0 || k > num)
	{
		printf("\n------------------------\n");
		printf("������Ч��Χ�ڲ�����Ŷ\n");
		printf("------------------------\n");
		system("pause");
		return;
	}
	int kmin = get_knum(arr,0,num-1,k);
	printf("-------------------------\n");
	printf("��%dС����Ϊ��%d\n",k,kmin);
	printf("-------------------------\n\n");
	system("pause");
}

void testmansmdata()
{
	int t1=0,t2=0,t3=0,t4=0,t5=0,t6=0;
	int i,j,num,NumRange,Grou;
	srand((unsigned int)time(NULL));
	printf("----------------------------------------------------------------\n");
	printf("����������ɶ�����ÿ����ٸ��ڶ��ٷ�Χ�ڵ�����(��ΧΪ0~32767)��\n");
	printf("----------------------------------------------------------------\n");
	printf("����:");
	Grou = get_input();
	printf("������:");
	num = get_input();
	printf("��Χ(��������):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1 || Grou == -1)
	{
		printf("\n--------------\n");
		printf("   �������\n");
		printf("--------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0 || Grou == 0)
	{
		printf("\n-----------------------------------\n");
		printf("   ������Ч��Χ��������Ч������\n");
		printf("-----------------------------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	printf("\n���ڼ��㣬���Ե�..........\n");
	for(i=0;i<Grou;i++)
	{
		for(j=0;j<num;j++)
		{
			*(arr+j) = rand()%NumRange + 1;
		}
		writetofile("data.txt",arr,num);

		t1 = t1 + inserttime(arr,num);

		readfromfile("data.txt",arr,num);
		t2 = t2 + mergetime(arr,num);

		readfromfile("data.txt",arr,num);
		t3 = t3 + QuickSort_Recurtime(arr,num);

		readfromfile("data.txt",arr,num);
		t4 = t4 + QuickSorttime(arr,num);

		readfromfile("data.txt",arr,num);
		t5 = t5 + countsorttime(arr,num);

		readfromfile("data.txt",arr,num);
		t6 = t6 + RadixCountSorttime(arr,num);
	}
	printf("\n------------------------------------------------\n");
	printf("����%d��%d������ʱ�������������ʱΪ��%dms\n",Grou,num,t1);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("����%d��%d������ʱ�鲢���������ʱΪ��%dms\n",Grou,num,t2);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("����%d��%d������ʱ�ݹ����Ų�����ʱΪ��%dms\n",Grou,num,t3);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("����%d��%d������ʱ�ǵݹ����Ų�����ʱΪ��%dms\n",Grou,num,t4);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("����%d��%d������ʱ�������������ʱΪ��%dms\n",Grou,num,t5);
	printf("------------------------------------------------\n");

	printf("\n-------------------------------------------------\n");
	printf("����%d��%d������ʱ�����������������ʱΪ��%dms\n",Grou,num,t6);
	printf("-------------------------------------------------\n");

	system("pause");
}

void testall()
{
	int i,num,NumRange;
	srand((unsigned int)time(NULL));
	printf("---------------------------------------------------\n");
	printf("����������ɶ��ٸ����ٷ�Χ�ڵ�����(��ΧΪ0~32767)��\n");
	printf("---------------------------------------------------\n");
	printf("������:");
	num = get_input();
	printf("��Χ(��������):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("\n-----------------\n");
		printf("     �������\n");
		printf("-----------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("������Ч��Χ��������Ч������\n");
		printf("---------------------------------\n");
		system("pause");
		return;
	}
	int *temp=(int *)malloc(num * sizeof(int *));     // ���ٿռ�Ϊ�Ժ�ʹ��
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand()%NumRange + 1;
	}
	writetofile("data.txt",arr,num);
	printf("\n--------------------\n");
	printf("����ԭ����Ϊ:\n");

	print(arr,num);
	printf("\n--------------------\n\n");
	readfromfile("data.txt",arr,num);
	insertSort(arr,num);

	printf("\n-------------------------\n");
	printf("�������򷨽��Ϊ:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	MergeSort(arr,0,num-1,temp);

	printf("\n-------------------------\n");
	printf("�鲢���򷨽��Ϊ:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	QuickSort_Recursion(arr,0,num-1);

	printf("\n-------------------------\n");
	printf("�ݹ����ŷ����Ϊ:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	QuickSort(arr,num);

	printf("\n-------------------------\n");
	printf("�ǵݹ����ŷ����Ϊ:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	int max = get_max(arr,num);
	CountSort(arr,num,max);

	printf("\n-------------------------\n");
	printf("�������򷨽��Ϊ:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	RadixCountSort(arr,num);

	printf("\n-------------------------\n");
	printf("�����������򷨽��Ϊ:\n");
	print(arr,num);

	printf("\n\n");
	system("pause");
}
