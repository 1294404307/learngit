#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define bigsize 10
#define addsize 5
typedef double elemtype;

typedef struct stack
{
	elemtype *top;
	elemtype *bottom;
	int stacksize;
}sqstack;

void initstack(sqstack *stack)
{
	stack->bottom=(elemtype *)malloc(bigsize * sizeof(elemtype));
	stack->top=stack->bottom;
	stack->stacksize=bigsize;
}

void push(sqstack *stack,elemtype e)
{
	if(stack->top - stack->bottom >=stack->stacksize)
	{
		stack->bottom=(elemtype *)realloc(stack->bottom,(stack->stacksize + addsize)*sizeof(elemtype));
	}
	*(stack->top)++=e;
}

void pop(sqstack *stack,elemtype *e)
{
	if(stack->top == stack->bottom)
	{
		printf("ÊäÈë´íÎó\n");
	}
	(*e)=*--(stack->top);
}
int stacklen(sqstack stack)
{
	return ((stack.top) - (stack.bottom));
}

//typedef struct	Cstack
//{
//	char *top;
//	char *bottom;
//	int stacksize;
//}Csqstack;
//
//void Cinitstack(Csqstack *stack)
//{
//	stack->bottom = (elemtype *)malloc(bigsize * sizeof(elemtype));
//	stack->top = stack->bottom;
//	stack->stacksize = bigsize;
//}
//
//void Cpush(Csqstack *stack, elemtype e)
//{
//	if (stack->top - stack->bottom >= stack->stacksize)
//	{
//		stack->bottom = (elemtype *)realloc(stack->bottom, (stack->stacksize + addsize) * sizeof(elemtype));
//	}
//	*(stack->top)++ = e;
//}
//
//void Cpop(Csqstack *stack, elemtype *e)
//{
//	if (stack->top == stack->bottom)
//	{
//		printf("Õ»ÒÑÇå¿Õ\n");
//		exit(0);
//	}
//	(*e) = *--(stack->top);
//}
//int Cstacklen(Csqstack stack)
//{
//	return ((stack.top) - (stack.bottom));
//}
