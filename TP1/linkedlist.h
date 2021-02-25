#ifndef __LINKED_LIST__
#define __LINKED_LIST__

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

typedef struct linked_list
{
	void *val;
	struct linked_list *before;
	struct linked_list *next;
} LinkedList;

LinkedList *addStart(LinkedList *, void *);
LinkedList *addEnd(LinkedList *, void *);
LinkedList *search(LinkedList *, void *);
LinkedList *deleteStart(LinkedList *, void **);
LinkedList *deleteEnd(LinkedList *, void **);
LinkedList *deleteVal(LinkedList *, bool (*compare)(void *));
int size(LinkedList *);
void display(LinkedList *);
void freeLinkedList(LinkedList *);

#endif