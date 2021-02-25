#include "stack.h"

bool push(Stack **stack, char data)
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
	}

	*stack = el;
	
	return true;
}

char pop(Stack **stack)
{
	if(*stack == NULL)
	{
		return NULL;
	}

	Stack *el = *stack;
	char data = el->data;
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
		printf("Stack : %c\n", stack->data);
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