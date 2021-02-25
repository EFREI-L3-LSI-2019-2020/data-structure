#include "queue.h"

Queue* init()
{
	Queue *q = (Queue *)calloc(1, sizeof(Queue));
	q->next = NULL;
	q->before = NULL;
	q->value = -1;
	return q;
}

bool push(Queue **q, int val)
{
	bool res = false;

	if((*q) != NULL)
	{
		if((*q)->value == -1)
		{
			(*q)->value = val;
		}
		else
		{
			Queue *last = (*q);
			while(last->next != NULL)
			{
				last = last->next;
			}

			Queue *next = (Queue *)calloc(1, sizeof(Queue));
			next->value = val;
			next->before = last;
			next->next = NULL;

			last->next = next;
		}
		res = true;
	}

	return res;
}

int pop(Queue **q)
{
	int res = -1;

	if((*q) != NULL)
	{
		Queue *current = (*q);
		res = current->value;

		Queue *next = current->next;
		next->before = NULL;

		*q = next;
		free(current);
	}

	return res;
}

void display(Queue *q)
{
	if(q != NULL)
	{
		Queue *current = q;
		if(current != NULL)
		{
			printf("Queue %p : %d\n", current, current->value);
			display(current->next);
		}
	}
}

void freeQueue(Queue *q)
{
	if(q != NULL)
	{
		if(q != NULL)
		{
			freeQueue(q->next);
		}

		free(q);
	}
}