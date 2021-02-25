#ifndef __QUEUE_H___
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX 100

typedef struct queue
{
	int data[MAX];
	int top;
	int bottom;
	unsigned int count;
} Queue;

Queue* init();
bool push(Queue **, int val);
int pop(Queue **);
void display(Queue *);
void freeQueue(Queue *);

#endif