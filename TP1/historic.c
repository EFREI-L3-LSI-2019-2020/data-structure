#include "historic.h"

void addElement(Historic *histo, void *el)
{
	bool updateCurrent = histo->list == histo->current;

	histo->list = addStart(histo->list, el);
	
	if(updateCurrent)
	{
		histo->current = histo->list;
	}
}

LinkedList *removeElement(Historic *histo)
{
	bool updateCurrent = histo->list == histo->current;

	LinkedList *ret = NULL;
	histo->list = deleteStart(histo->list, &ret);

	if(updateCurrent)
	{
		histo->current = histo->list;
	}

	return ret;
}

void forward(Historic *histo)
{
	if(histo->current != NULL)
	{
		if(histo->current->before != NULL)
		{
			histo->current = histo->current->before;
		}
	}
}

void backward(Historic *histo)
{
	if(histo->current != NULL)
	{
		if(histo->current->next != NULL)
		{
			histo->current = histo->current->next;
		}
	}
}

void displayHistoric(Historic *histo)
{
	if(histo != NULL)
	{
		display(histo->list);
		printf("Current : %p\n", histo->current);
	}
}

/*int main(int argc, char *argv[])
{
	Historic *histo = (Historic *) calloc(1, sizeof(Historic));

	int first = 1;
	int second = 2;

	addElement(histo, second);
	addElement(histo, first);
	addElement(histo, second);

	displayHistoric(histo);
	backward(histo);
	displayHistoric(histo);
	LinkedList *el = removeElement(histo);
	displayHistoric(histo);
	forward(histo);
	displayHistoric(histo);

	freeLinkedList(histo->list);
	free(histo);
	free(el);
}*/