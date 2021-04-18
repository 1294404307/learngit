#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef enum Status
{
	ERROR = 0,
	SUCCESS = 1
} Status;

typedef int ElemType;

typedef  struct StackNode
{
	ElemType data;
	struct StackNode *next;
}StackNode, *LinkStackPtr;

typedef  struct  LinkStack
{
	LinkStackPtr top;
	int	count;
}LinkStack;


void menu();
int get_max();
int get_long(int arr[],int len);
int get_input();
void print(int arr[],int n);
void writetofile(const char *finame,int arr[],int num);
void readfromfile(const char *FiName,int arr[],int num);

int inserttime(int *a,int num);
int mergetime(int *a,int num);
int QuickSort_Recurtime(int *a,int num);
int QuickSorttime(int *a,int num);
int countsorttime(int *a,int num);
int RadixCountSorttime(int *a,int num);
void testspeed();
void testcolor();
void testfindknum();
void testmansmdata();
void testall();


//��ջ
Status initLStack(LinkStack *s);//��ʼ��ջ
Status isEmptyLStack(LinkStack *s);//�ж�ջ�Ƿ�Ϊ��
Status getTopLStack(LinkStack *s,ElemType *e);//�õ�ջ��Ԫ��
Status clearLStack(LinkStack *s);//���ջ
Status destroyLStack(LinkStack *s);//����ջ
Status LStackLength(LinkStack *s,int *length);//���ջ����
Status pushLStack(LinkStack *s,ElemType data);//��ջ
int popLStack(LinkStack *s);//��ջ


#endif
