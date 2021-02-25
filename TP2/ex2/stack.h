#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stack
{
	void *data;
	struct stack *next;
} Stack;

bool push(Stack **, void *);
void *pop(Stack **);
void printStack(Stack *);
void freeStack(Stack *);

#endif