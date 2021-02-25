#include "queue.h"

int main(int argc, char *argv[])
{
	Queue *q = init();

	printf("Push %d\n", push(&q, 1));
	printf("Push %d\n", push(&q, 2));
	printf("Push %d\n", push(&q, 3));

	printf("Pop %d\n", pop(&q));
	printf("Pop %d\n", pop(&q));

	display(q);
	freeQueue(q);
}