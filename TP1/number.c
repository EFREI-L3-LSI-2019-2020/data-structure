#include "number.h"

unsigned short getRest(unsigned short nb1, unsigned short nb2, unsigned short **deduction)
{
	printf("\nnb1 : %d\n", nb1);
	printf("nb2 : %d\n", nb2);

	unsigned short sum = nb1 + nb2 + **deduction;
	**deduction = sum >= 10 ? 1 : 0;
	unsigned short rest = sum % 10;

	printf("sum : %d\n", sum);
	printf("deduction : %d\n", **deduction);
	printf("rest : %d\n", rest);

	return rest;
}

LinkedList *sum(LinkedList *nb1, LinkedList *nb2)
{
	if(nb1 == NULL)
	{
		return nb2;
	}

	if(nb2 == NULL)
	{
		return nb1;
	}

	int size1 = size(nb1);
	int size2 = size(nb2);

	LinkedList *max, *min;

	if(size1 > size2)
	{
		max = nb1;
		min = nb2;
	}
	else
	{
		max = nb2;
		min = nb1;
	}
	
	LinkedList *result = NULL;

	while(max->next != NULL) { max = max->next; }
	while(min->next != NULL) { min = min->next; }

	unsigned char deduction = 0;
	unsigned long bound = 100000;

	bool minDone = false;
	bool maxDone = false;

	while(max != NULL)
	{
		unsigned int maxVal, minVal;
		maxVal = (unsigned int) max->val;
		minVal = 0;

		max = max->before;

		if(min != NULL)
		{
			minVal = (unsigned int) min->val;
			min = min->before;
		}

		printf("sum : %d + %d + %ld\n", maxVal, minVal, deduction);

		unsigned long sum, rest;
		sum = maxVal + minVal + deduction;
		printf("Sum : %ld\n", sum);
		
		rest = sum == bound ? sum : sum % bound;
		deduction = sum > bound ? 1 : 0; 

		printf("Deduction : %d\n", deduction);
		printf("Rest : %ld\n", rest);

		result = addStart(result, rest);
	}

	if(deduction)
	{
		result = addStart(result, deduction);
	}

	return result;
}

char *listToString(LinkedList * list)
{
	char *str = (char *)calloc(1, sizeof(char));

	LinkedList *current = list;
	while(current != NULL)
	{
		char val[6];
		sprintf(val, "%d", (int) current->val);
		strcat(str, val);

		current = current->next;
	}

	return str;
}

int main(int arc, char *argv[])
{
	LinkedList *l1, *l2, *result;
	l1 = l2 = result = NULL;

	l1 = addStart(l1, 99999);

	/**
	 * This is invalide
	 * l1 = addStart(l1, 9);
	 * l1 = addStart(l1, 9);
	 * 
	*/

	l2 = addStart(l2, 99999);
	l2 = addStart(l2, 99999);

	char *nb1 = listToString(l1);
	printf("Number : %s\n", nb1);

	char *nb2 = listToString(l2);
	printf("Number : %s\n", nb2);

	free(nb1);
	free(nb2);

	/*printf("\nl1\n");
	display(l1);
	printf("l2\n");
	display(l2);*/

	result = sum(l1, l2);

	/*printf("\nl1\n");
	display(l1);
	printf("l2\n");
	display(l2);
	printf("result\n");
	display(result);*/

	char *nb = listToString(result);
	printf("Result : %s\n", nb);

	free(nb);

	//printf("\nfree l1\n");
	freeLinkedList(l1);
	//printf("free l2\n");
	freeLinkedList(l2);
	//printf("free result\n");
	freeLinkedList(result);
}