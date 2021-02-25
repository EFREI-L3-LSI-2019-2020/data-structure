#include "queue.h"

void push(Queue **q, Patient *val)
{
	Queue *tmp = (Queue *)calloc(1, sizeof(Queue));
	tmp->val = val;

	if (*q == NULL)
		*q = tmp;
	else
	{
		Queue *current = *q;
		while (current->next != NULL)
			current = current->next;
		current->next = tmp;
	}
}

Patient *pop(Queue **q)
{
	if (*q != NULL)
	{
		Queue *tmp = *q;
		Patient *val = tmp->val;
		*q = tmp->next;
		free(tmp);
		return val;
	}
	return NULL;
}

void freeQueue(Queue *q)
{
	if (q == NULL)
		return;

	freeQueue(q->next);
	free(q);
}

void displayQueue(Queue *q)
{
	if (q == NULL)
		return;

	displayQueue(q->next);
	displayPatient(q->val);
}