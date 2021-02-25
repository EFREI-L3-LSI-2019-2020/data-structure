#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

#define BLOCKSIZE 64

typedef struct stack
{
	void **values;
	long index;
	unsigned long size;
} Stack;

Stack initStack();
bool push(Stack *, void *);
void *pop(Stack *);
void printStack(Stack *);

#endif