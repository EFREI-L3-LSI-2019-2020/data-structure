#ifndef __QUEUE_H___
#define __QUEUE_H__

#include "patient.h"

typedef struct queue
{
	Patient *val;
	struct queue *next;
} Queue;

void push(Queue **, Patient *);
Patient *pop(Queue **);
Patient *lastElementQueue(Queue *);
void freeQueue(Queue *);
void displayQueue(Queue *);

#endif