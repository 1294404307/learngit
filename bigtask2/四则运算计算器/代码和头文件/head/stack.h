#ifndef STACK_H_INCLUDED
#define STACK_H_INCLUDED

typedef double elemtype;

typedef struct stack
{
	elemtype *top;
	elemtype *bottom;
	int stacksize;
}sqstack;

void initstack(sqstack *stack);
void push(sqstack *stack,elemtype e);
void pop(sqstack *stack,elemtype *e);
int stacklen(sqstack stack);


//typedef struct Cstack
//{
//	char *top;
//	char *bottom;
//	int stacksize;
//}Csqstack;
//
//void Cinitstack(Csqstack *stack);
//void Cpush(Csqstack *stack, elemtype e);
//void Cpop(Csqstack *stack, elemtype *e);
//int Cstacklen(Csqstack stack)
#endif // STACK_H_INCLUDED
