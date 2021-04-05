#ifndef CHARSTACK_H_INCLUDED
#define CHARSTACK_H_INCLUDED

typedef struct charstack
{
	char *top;
	char *bottom;
	int stacksize;
}charstack;

void charinitstack(charstack *stack);
void charpush(charstack *stack,char e);
void charpop(charstack *stack,char *e);
int charstacklen(charstack stack);

#endif // CHARSTACK_H_INCLUDED
