#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stack
{
	char data;
	struct stack *next;
} Stack;

bool push(Stack **, char);
char pop(Stack **);
void printStack(Stack *);
void freeStack(Stack *);

#endif