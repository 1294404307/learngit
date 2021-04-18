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


//链栈
Status initLStack(LinkStack *s);//初始化栈
Status isEmptyLStack(LinkStack *s);//判断栈是否为空
Status getTopLStack(LinkStack *s,ElemType *e);//得到栈顶元素
Status clearLStack(LinkStack *s);//清空栈
Status destroyLStack(LinkStack *s);//销毁栈
Status LStackLength(LinkStack *s,int *length);//检测栈长度
Status pushLStack(LinkStack *s,ElemType data);//入栈
int popLStack(LinkStack *s);//出栈


#endif
