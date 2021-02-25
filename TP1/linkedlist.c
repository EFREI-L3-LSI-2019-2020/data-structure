#include "linkedlist.h"

LinkedList *addStart(LinkedList *list, void *val)
{
	LinkedList *element = (LinkedList *)calloc(1, sizeof(LinkedList));
	element->val = val;
	element->next = list;
	if(list != NULL)
	{
		list->before = element;
	}
	return element;
}

LinkedList *addEnd(LinkedList *list, void *val)
{
	LinkedList *element = (LinkedList *)calloc(1, sizeof(LinkedList));
	element->val = val;

	if(list == NULL)
	{
		return element;
	}

	LinkedList *current = list;
	while(current->next != NULL)
	{
		current = current->next;
	}

	element->before = current;
	current->next = element;

	return list;
}

LinkedList *search(LinkedList *list, void *val)
{
	if(list == NULL)
	{
		return NULL;
	}

	if(list->val == val)
	{
		return list;
	}
	else
	{
		if(list->next != NULL)
		{
			return search(list->next, val);
		}
		else
		{
			return NULL;
		}
	}
}

LinkedList *deleteStart(LinkedList *list, void **ret)
{
	if(list == NULL)
	{
		return NULL;
	}

	LinkedList *temp = list->next;
	temp->before = NULL;
	*ret = list;
	return temp;
}

LinkedList *deleteEnd(LinkedList *list, void **ret)
{
	if(list != NULL)
	{
		if(list->next == NULL)
		{
			*ret = list;
			return NULL;
		}
		LinkedList *current = list;

		while(current->next != NULL)
		{
			if(current->next->next == NULL)
			{
				*ret = current->next;
				current->next = NULL;
				return list;
			}
			current = current->next;
		}
	}

	return list;
}

LinkedList *deleteVal(LinkedList *list, bool (*compare)(void *))
{
	if(list == NULL)
	{
		return NULL;
	}

	LinkedList *current, *last;
	current = list;
	unsigned int index = 0;

	while(current != NULL)
	{
		if(compare(current->val))
		{
			printf("Removing : %p\n", &current->val);
			LinkedList *next = current->next;
			if(index == 0)
			{
				list = next;
				index--;
			}
			else
			{
				free(current);
				if(last != NULL)
				{
					last->next = next;
				}
			}
			free(current);			
			current = next;
		}
		else
		{
			last = current;
			current = current->next;
		}

		index++;
	}

	return list;
	
	/*LinkedList *current, *last;
	current = list;

	if(current->val == val)
	{
		last = current->next;
		free(current);
		return last;
	}
	else
	{
		list->next = deleteVal(list->next, val);
		return list;
	}

	return list;*/
}

int size(LinkedList *list)
{
	int size = 0; 
    while (list != NULL) 
    { 
        list = list->next;
        size++; 
    } 
    return size; 
}

void display(LinkedList *list)
{
	if(list != NULL)
	{
		LinkedList *current = list;
		while(current->next != NULL)
		{
			printf("LinkedList : %d : %p\n", current->val, current);
			current = current->next;
		}

		printf("LinkedList : %d : %p\n", current->val, current);
	}
}

void freeLinkedList(LinkedList *list)
{
	if(list != NULL)
	{
		LinkedList *current = list;
		LinkedList *last = list;
		while(current->next != NULL)
		{
			//printf("free last : %p\n", last);
			current = current->next;
			free(last);
			last = current;
		}

		//printf("free current : %p\n", current);
		free(current);
	}
}

bool compare(void *val)
{
	return *(int *)val == 0;
}

/*int main(int argc, char * argv[])
{
	LinkedList *list = (LinkedList *)calloc(1, sizeof(LinkedList));
	list->val = 2;

	list = addStart(list, 1);
	list = addStart(list, 0);
	list = addStart(list, 0);
	list = addEnd(list, 3);

	display(list);

	printf("------------------\n");

	void *start = NULL;
	//list = deleteStart(list, &start);
	void *end = NULL;
	//list = deleteEnd(list, &end);

	free(start);
	free(end);

	list = deleteVal(list, compare);

	display(list);
	freeLinkedList(list);

	return 0;
}*/