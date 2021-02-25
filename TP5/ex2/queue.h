#ifndef __QUEUE_H___
#define __QUEUE_H__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct queue
{
	struct queue *next;
	struct queue *before;
	int value;
} Queue;

Queue* init();
bool push(Queue **, int val);
int pop(Queue **);
void display(Queue *);
void freeQueue(Queue *);

#endif