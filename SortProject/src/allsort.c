#include <stdio.h>
#include <stdlib.h>
#include "qgsort.h"
#include "LinkStack.h"
#include <time.h>

void menu()
{
	printf("                   选择\n");
	printf("------------------------------------------------\n");
	printf("1、大数据下算法效率       2、多组小数据下算法效率\n\n");
	printf("3、颜色排序               4、找到第K小的值\n\n");
	printf("5、测试各算法排序结果     6、退出 \n");
	printf("------------------------------------------------\n\n");
}

void print(int arr[],int n)   //打印
{
	int i=0;
	for(i=0;i<n;i++)
		printf("%d ",arr[i]);
}

int get_max(int arr[],int len)    //得到数组中最大的值
{
	int max=0;
	for(int i=0;i<len;i++)
	{
		max=(max > arr[i]) ? max : arr[i];
	}
	return max;
}

int get_long(int arr[],int len)    //得到数组中最长大位数
{
	int length=0,i,j,m,n=10;
	for(i=0;i<len;i++)
	{
		m=1;
		for(j=1,n=10;m != 0;n=n*10,j++)
		{
			m = arr[i] / n;     //通过取模来判断位数
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

		//找到最接近它的数，在前面插入
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

	//让arrTemp拥有数组的值
	for(i=0;i<size;i++)
		arrTemp[i]=*(a+i);
	int *temp = (int *)malloc((max+1) * sizeof(int *));
	temp[0]=0;
	for(i=0;i<max+1;i++)
	{
		count = 0;
		for(j=0;j<size;j++)
		{
			//有此数，则增加数量
			if(*(a+j) == i)
				count++;
		}
		if(i == 0)
			temp[0]=count;
		else
			temp[i]=temp[i-1]+count;  //加起来得到小于等于自身的数的数量
	}

	//将改变后的数组赋给原数组
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

	int maxlong = get_long(a,size);  //得到最长位数

	//个十百等等位数的判断
	for(i=1;i <= maxlong;n=n*10,i++)
	{
		for(j=0,m=0;j<size;j++,m++)
		{
			temp[m] =*(a+j) % n;  //储存余数
		}
		QuickSort(temp,size);   //将储存余数的数组按顺序排列
		for(m=0;m<size;m++)
		{
			for(j=m;j<size;j++)
			{
				//通过判断余数是否相同，将原数组的元素更换位置
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
		if(*(a+p-1) == 2)   //如果p前一位数为2，则将p换回原来位置不动
			p=p-1;
		if(*(a+p) == 2)
		{
			if(*(a+p2) == 2)  //下标为p2的值为2，则将p2往前移
				p2--;
			else
			{
				temp=*(a+p);
				*(a+p)=*(a+p2);
				*(a+p2)=temp;
				p2--;
			}
		}

		//下标为p对应的数值为0，则将其值与p0交换
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

		//满足条件就将数暂时储存在temp中
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

	//将剩下的值填回数组
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

	//将数组拼接起来
	for(i=0;i<len;i++)
	{
		*(a +(i + begin))=*(temp + i);
	}
}

void MergeSort(int *a,int begin,int end,int *temp)
{
	int len=end - begin +1,sz,i,mid,l,r;

	//通过循环将数组划分后排序再归并在一起
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

void swap(int *a,int *b)   //交换值
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

		//找到比point小的值
		while(begin < end && *(a+end) >= point)
		{
			end--;
		}
		if(begin < end)
		{
			*(a+begin)=*(a+end);
		}

		//找到比point大的值
		while(begin < end && *(a+begin) <= point)
		{
			begin++;
		}
		if(begin < end)
		{
			*(a+end) = *(a+begin);
		}
	}
	*(a+begin)=point;  //确定枢轴位置
	return begin;
}

void QuickSort_Recursion(int *a, int begin, int end)
{
	int point;
	if(begin >= end)
		return;
	point = Partition(a,begin,end);  //得到每个枢轴
	QuickSort_Recursion(a,begin,point-1);
	QuickSort_Recursion(a,point+1,end);
}

Status initLStack(LinkStack *s)
{
	s->top=(LinkStackPtr)malloc(sizeof(StackNode));   //创建初始内存空间
	if(!s->top)  //创造失败时
	{
		return ERROR;
	}
	s->top->next=NULL;
	s->count=0;            //栈的长度为0，表示空栈
	return SUCCESS;
}

Status pushLStack(LinkStack *s,ElemType data)
{
	if(s->count==0)   ////若生成栈后栈被不小心销毁，则再次分配内存空间
	{
		s->top=(LinkStackPtr)malloc(sizeof(StackNode));
		s->top->data=data;
		s->top->next=NULL;
	}
	else
	{
		LinkStack temp;
		temp.top=(LinkStackPtr)malloc(sizeof(StackNode));     //进一次栈，需要多分配一个内存空间
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
	s->top=s->top->next;   //出栈后栈顶往下移
	s->count--;
	return data;
}

void QuickSort(int *a,int size)
{
	LinkStack s;
	int left=0,right = size - 1;

	 //递归的实现类似于栈的入栈出栈操作，可用栈的方法类似实现递归
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
			right = point - 1;     //右边界改变，将不可能的区间舍弃
			point = Partition(a,left,right);
		}
		if(point < k-1)
		{
			left = point + 1;     //左边界改变
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
	printf("输入随机生成多少个多少范围内的数据(范围为0~32767)：\n");
	printf("---------------------------------------------------\n");
	printf("数据量:");
	num = get_input();
	printf("范围(多少以内):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("\n-----------------\n");
		printf("     输入错误\n");
		printf("-----------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("请在有效范围内生成有效个数据\n");
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
	printf("\n正在计算，请稍等........\n");

	readfromfile("data.txt",arr,num);   // 从文件中读取数据
	t1 = inserttime(arr,num);            //得到排序使用时间

	printf("\n---------------------------------------\n");
	printf("       插入排序操作用时为：%dms\n",t1);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);              //因为排序后arr数组被改变，所以重新从文件中读取数据
	t2 = mergetime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      归并排序操作用时为：%dms\n",t2);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t3 = QuickSort_Recurtime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      递归版快速排序操作用时为：%dms\n",t3);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t4 = QuickSorttime(arr,num);

	printf("\n---------------------------------------\n");
	printf("      非递归版快速排序操作用时为：%dms\n",t4);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t5 = countsorttime(arr,num);

	printf("\n---------------------------------------\n");
	printf("        计数排序操作用时为：%dms\n",t5);
	printf("---------------------------------------\n");

	readfromfile("data.txt",arr,num);
	t6 = RadixCountSorttime(arr,num);

	printf("\n我计算得有点慢哦，请稍等......\n");

	printf("\n---------------------------------------\n");
	printf("        基数计数排序操作用时为：%dms\n",t6);
	printf("---------------------------------------\n");
	system("pause");

}

void testcolor()
{
	int i,num;
	srand((unsigned int)time(NULL));
	printf("----------------------------\n");
	printf("输入随机生成多少个数据：\n");
	printf("----------------------------\n");
	num = get_input();
	if(num == -1)
	{
		printf("----------------\n");
		printf("    输入错误\n");
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
	printf("  生成原数据为:\n");
	printf("----------------\n\n");
	print(arr,num);
	printf("\n\n----------------\n");
	printf("排序后的数据为:\n");
	printf("----------------\n\n");
	ColorSort(arr,num);           //颜色排序
	print(arr,num);              //打印排序后结果
	printf("\n\n");
	system("pause");
}

void testfindknum()
{
	int i,num,k,NumRange;
	srand((unsigned int)time(NULL));
	printf("---------------------------------------------------\n");
	printf("输入随机生成多少个多少范围内的数据(范围为0~32767)：\n");
	printf("---------------------------------------------------\n");
	printf("数据量:");
	num = get_input();
	printf("范围(多少以内):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("--------------\n");
		printf("   输入错误\n");
		printf("--------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("   请在有效范围内生成有效个数据\n");
		printf("---------------------------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand()%NumRange + 1;       //将随机生成的数赋值给数组
	}
	printf("--------------------\n");
	printf("   生成原数据为:\n");
	printf("--------------------\n\n");
	print(arr,num);
	printf("\n\n--------------------\n");
	printf("  您想找第几小的数：\n");
	printf("--------------------\n");
	k=get_input();
	if(k == -1)
	{
		printf("\n---------------\n");
		printf("   输入错误\n");
		printf("---------------\n");
		system("pause");
		return;
	}
	if(k <= 0 || k > num)
	{
		printf("\n------------------------\n");
		printf("请在有效范围内查找数哦\n");
		printf("------------------------\n");
		system("pause");
		return;
	}
	int kmin = get_knum(arr,0,num-1,k);
	printf("-------------------------\n");
	printf("第%d小的数为：%d\n",k,kmin);
	printf("-------------------------\n\n");
	system("pause");
}

void testmansmdata()
{
	int t1=0,t2=0,t3=0,t4=0,t5=0,t6=0;
	int i,j,num,NumRange,Grou;
	srand((unsigned int)time(NULL));
	printf("----------------------------------------------------------------\n");
	printf("输入随机生成多少组每组多少个在多少范围内的数据(范围为0~32767)：\n");
	printf("----------------------------------------------------------------\n");
	printf("组数:");
	Grou = get_input();
	printf("数据量:");
	num = get_input();
	printf("范围(多少以内):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1 || Grou == -1)
	{
		printf("\n--------------\n");
		printf("   输入错误\n");
		printf("--------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0 || Grou == 0)
	{
		printf("\n-----------------------------------\n");
		printf("   请在有效范围内生成有效组数据\n");
		printf("-----------------------------------\n");
		system("pause");
		return;
	}
	int *arr=(int *)malloc(num * sizeof(int *));
	printf("\n正在计算，请稍等..........\n");
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
	printf("处理%d组%d个数据时插入排序操作用时为：%dms\n",Grou,num,t1);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("处理%d组%d个数据时归并排序操作用时为：%dms\n",Grou,num,t2);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("处理%d组%d个数据时递归版快排操作用时为：%dms\n",Grou,num,t3);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("处理%d组%d个数据时非递归版快排操作用时为：%dms\n",Grou,num,t4);
	printf("------------------------------------------------\n");

	printf("\n------------------------------------------------\n");
	printf("处理%d组%d个数据时计数排序操作用时为：%dms\n",Grou,num,t5);
	printf("------------------------------------------------\n");

	printf("\n-------------------------------------------------\n");
	printf("处理%d组%d个数据时基数计数排序操作用时为：%dms\n",Grou,num,t6);
	printf("-------------------------------------------------\n");

	system("pause");
}

void testall()
{
	int i,num,NumRange;
	srand((unsigned int)time(NULL));
	printf("---------------------------------------------------\n");
	printf("输入随机生成多少个多少范围内的数据(范围为0~32767)：\n");
	printf("---------------------------------------------------\n");
	printf("数据量:");
	num = get_input();
	printf("范围(多少以内):");
	NumRange = get_input();
	if(num == -1 || NumRange == -1)
	{
		printf("\n-----------------\n");
		printf("     输入错误\n");
		printf("-----------------\n");
		system("pause");
		return;
	}
	if(num == 0 || NumRange == 0)
	{
		printf("---------------------------------\n");
		printf("请在有效范围内生成有效个数据\n");
		printf("---------------------------------\n");
		system("pause");
		return;
	}
	int *temp=(int *)malloc(num * sizeof(int *));     // 开辟空间为以后使用
	int *arr=(int *)malloc(num * sizeof(int *));
	for(i=0;i < num;i++)
	{
		*(arr+i) = rand()%NumRange + 1;
	}
	writetofile("data.txt",arr,num);
	printf("\n--------------------\n");
	printf("生成原数据为:\n");

	print(arr,num);
	printf("\n--------------------\n\n");
	readfromfile("data.txt",arr,num);
	insertSort(arr,num);

	printf("\n-------------------------\n");
	printf("插入排序法结果为:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	MergeSort(arr,0,num-1,temp);

	printf("\n-------------------------\n");
	printf("归并排序法结果为:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	QuickSort_Recursion(arr,0,num-1);

	printf("\n-------------------------\n");
	printf("递归版快排法结果为:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	QuickSort(arr,num);

	printf("\n-------------------------\n");
	printf("非递归版快排法结果为:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	int max = get_max(arr,num);
	CountSort(arr,num,max);

	printf("\n-------------------------\n");
	printf("计数排序法结果为:\n");

	print(arr,num);

	readfromfile("data.txt",arr,num);
	RadixCountSort(arr,num);

	printf("\n-------------------------\n");
	printf("基数计数排序法结果为:\n");
	print(arr,num);

	printf("\n\n");
	system("pause");
}
