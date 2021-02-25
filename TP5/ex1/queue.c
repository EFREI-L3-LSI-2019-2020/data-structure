#include "queue.h"

Queue* init()
{
	Queue *q = (Queue *)calloc(1, sizeof(Queue));
	q->top = 0;
	q->bottom = 0;
	q->count = 0;
	return q;
}

bool push(Queue **q, int val)
{
	bool res = false;

	if((*q) != NULL && (*q)->top != MAX)
	{
		(*q)->data[(*q)->top] = val;
		(*q)->top = ((*q)->top + 1) % MAX;
		(*q)->count++;
		res = true;
	}

	return res;
}

int pop(Queue **q)
{
	int res = -1;

	if((*q) != NULL && (*q)->count != 0)
	{
		res = (*q)->data[(*q)->bottom];
		(*q)->bottom = ((*q)->bottom + 1) % MAX;
		(*q)->count--;
	}

	return res;
}

void display(Queue *q)
{
	if(q != NULL)
	{
		if(q->count == 0)
		{
			printf("Queue is empty\n");
		}
		else
		{
			for(unsigned int i = 0; i < q->count; i++)
			{
				printf("Queue[%d] : %d\n", i, q->data[i + q->bottom]);
			}
		}
	}
}

void freeQueue(Queue *q)
{
	if(q != NULL)
	{
		free(q);
	}
}