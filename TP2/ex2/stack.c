#include "stack.h"

bool push(Stack **stack, void *data)
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

void *pop(Stack **stack)
{
	if(*stack == NULL)
	{
		return NULL;
	}

	Stack *el = *stack;
	void *data = el->data;
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
		printf("Stack : %p\n", &stack->data);
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

int main(int argc, char *argv[])
{
	Stack stack = NULL;

	int x = 1;
	bool res = push(&stack, &x);
	printStack(stack);

	void *data = pop(&stack);
	printf("Pop data : %p\n", data);
	printStack(stack);

	freeStack(stack);

	return 0;
}