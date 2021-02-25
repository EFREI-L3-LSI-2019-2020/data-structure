#include "stack.h"

Stack initStack()
{
	Stack stack;
	stack.index = -1;
	stack.values = (void **)calloc(BLOCKSIZE, sizeof(void *));
	stack.size = BLOCKSIZE;

	return stack;
}

bool push(Stack *stack, void *data)
{
	if(stack == NULL || stack->values == NULL)
	{
		return false;
	}

	stack->index++;
	if(stack->index >= stack->size)
	{
		stack->size = stack->size + BLOCKSIZE;
		stack->values = (void **)realloc(stack->values, stack->size * sizeof(void *));
	}

	stack->values[stack->index] = data;
	
	return true;
}

void *pop(Stack *stack)
{
	if(stack == NULL)
	{
		return NULL;
	}

	void *data = stack->values[stack->index];
	//free(stack->values[stack->index]);
	stack->index--;
	return data;
}

void printStack(Stack *stack)
{
	if(stack == NULL)
	{
		printf("Stack is empty \n");
		return;
	}

	for(int i = 0; i <= stack->index; i++)
	{
		printf("Stack val : %p\n", stack->values[i]);
	}
}

int main(int argc, char *argv[])
{
	Stack stack = initStack();

	int x = 1;
	bool res = push(&stack, &x);
	printf("%d\n", *((int *)(stack.values[0])));

	float y = 1.0f;
	res = push(&stack, &y);
	printf("%f\n", *((float *)(stack.values[1])));
	printStack(&stack);

	void *data = pop(&stack);
	printf("Pop data : %p\n", data);
	printStack(&stack);

	free(stack.values);

	return 0;
}