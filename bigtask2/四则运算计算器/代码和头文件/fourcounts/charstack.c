#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define bigsize 10
#define addsize 5
typedef struct charstack
{
	char *top;
	char *bottom;
	int stacksize;
}charstack;

void charinitstack(charstack *stack)
{
	stack->bottom=(char *)malloc(bigsize * sizeof(char));
	stack->top=stack->bottom;
	stack->stacksize=bigsize;
}

void charpush(charstack *stack,char e)
{
	if(stack->top - stack->bottom >=stack->stacksize)
	{
		stack->bottom=(char *)realloc(stack->bottom,(stack->stacksize + addsize)*sizeof(char));
	}
	*(stack->top)++=e;
}

void charpop(charstack *stack,char *e)
{
	if(stack->top == stack->bottom)
	{
		printf("Õ»ÒÑÇå¿Õ\n");
	}
	(*e)=*--(stack->top);
}
int charstacklen(charstack stack)
{
	return ((stack.top) - (stack.bottom));
}
