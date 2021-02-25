#include "stack.h"

bool push(Stack **stack, int data)
{
	Stack *el = (Stack *)calloc(1, sizeof(Stack));
	if(el == NULL)
	{
		return false;
	}

	el->data = data;

	if(*stack == NULL)
	{
		el->next = NULL;
	}
	else
	{
		el->next = *stack;
		(*stack)->before = el;
	}

	*stack = el;
	
	return true;
}

int pop(Stack **stack)
{
	if(*stack == NULL)
	{
		return -1;
	}

	Stack *el = *stack;
	int data = el->data;
	*stack = el->next;
	free(el);
	return data;
}

void printStack(Stack *stack)
{
	if(stack == NULL)
	{
		printf("Stack is empty \n");
		return;
	}

	while(stack != NULL)
	{
		printf("Stack : %d\n", stack->data);
		stack = stack->next;
	}
}

void freeStack(Stack *stack)
{
	if(stack == NULL)
	{
		printf("Free : stack is empty \n");
		return;
	}

	while(stack != NULL)
	{
		Stack *tmp = stack;
		free(stack);
		stack = tmp->next;
	}
}

bool save(Stack *stack, char *fileName)
{
	if(stack == NULL || fileName == NULL)
	{
		return false;
	}

	FILE *file = fopen(fileName, "w");
	if(file == NULL)
	{
		return false;
	}

	while(stack->next != NULL){ stack = stack->next; }

	while(stack != NULL)
	{
		fprintf(file, "%d\n", stack->data);
		stack = stack->before;
	}

	fclose(file);
}

Stack *from(char * fileName)
{
	Stack *stack = NULL;

	if(fileName == NULL)
	{
		return NULL;
	}

	FILE *file = fopen(fileName, "r");
	if(file == NULL)
	{
		return NULL;
	}

	char c;
	while((c = getc(file)) != EOF)
	{
		if(c != '\n')
		{
			push(&stack, c - '0');
		}
	}

	fclose(file);

	return stack;
}

int main(int argc, char *argv[])
{
	Stack stack = NULL;

	bool res = push(&stack, 1);
	res = push(&stack, 2);
	printf("\nPrint stack\n");
	printStack(stack);

	printf("\nSaving stack\n");
	save(stack, "save.txt");

	int data = pop(&stack);
	printf("Pop data : %d\n", data);
	printf("\nPrint stack\n");
	printStack(stack);

	printf("\nFrom file\n");
	Stack *stack2 = from("save.txt");
	printStack(stack2);

	freeStack(stack);
	freeStack(stack2);

	return 0;
}