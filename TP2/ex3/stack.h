#ifndef __STACK__
#define __STACK__

#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>

typedef struct stack
{
	int data;
	struct stack *next;
	struct stack *before;
	
} Stack;

bool push(Stack **, int);
int pop(Stack **);
void printStack(Stack *);
void freeStack(Stack *);

bool save(Stack *, char *);
Stack *from(char *);

#endif