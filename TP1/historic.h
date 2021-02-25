#ifndef __HISTORIC__
#define __HISTORIC__

#include "linkedlist.h"

typedef struct Historic
{
	LinkedList *list;
	LinkedList *current;
} Historic;

void addElement(Historic *, void *);
LinkedList *removeElement(Historic *);
void forward(Historic *);
void backward(Historic *);
void displayHistoric(Historic *);

#endif