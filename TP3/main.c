#include "stack.h"
#include <ctype.h>
#include <string.h>
#include <math.h>

bool isValidExpression(char *str)
{
	int parenthese, bracket, accolade;
	parenthese = bracket = accolade = 0;

	for(int i = 0; i < strlen(str); i++)
	{
		switch(str[i])
		{
			case '(': parenthese++; break;
			case ')': parenthese--; break;
			case '[': bracket++; break;
			case ']': bracket--; break;
			case '{': accolade++; break;
			case '}': accolade--; break;
			default: break;
		}
	}

	return parenthese == 0 && bracket == 0 && accolade == 0;
}

int priority(char operator)
{ 
    switch (operator) 
    { 
		case '+': 
		case '-': 
			return 1; 
	
		case '*': 
		case '/': 
			return 2; 
	
		case '^': 
			return 3; 
    } 

    return -1; 
} 

int operation(int a, int b, char operator)
{
	switch(operator)
	{ 
        case '+': return a + b; 
        case '-': return a - b; 
        case '*': return a * b; 
        case '/': return a / b;
		case '^': return pow(a, b);
    } 
}

bool isOperand(char ch) 
{ 
    return (ch >= 'a' && ch <= 'z') || (ch >= 'A' && ch <= 'Z'); 
} 
 
char *infixToPostfix(char* str)
{ 
    int i, k;
  
    Stack* stack = NULL;
	char *res = (char *)calloc(strlen(str), sizeof(char));
  
    for (i = 0, k = -1; str[i]; ++i)
    {
        if (isdigit(str[i]))
        {
			res[++k] = str[i];
		}
        else if (str[i] == '(')
		{
			push(&stack, str[i]);
		}
        else if (str[i] == ')')
        {
            while (stack != NULL && stack->data != '(')
            {
				res[++k] = pop(&stack);
			}           
            pop(&stack);
        } 
        else if(str[i] != ' ')
        {
            while (stack != NULL && priority(str[i]) <= priority(stack->data))
            {
				res[++k] = pop(&stack);
			} 
            push(&stack, str[i]);
        } 
    } 
  
    while (stack != NULL)
    {
		res[++k] = pop(&stack);
	}
  
    res[++k] = '\0';
    return res;
}

int evaluate(char *post)
{
	Stack* stack = NULL;

	for(int i = 0; i < strlen(post); i++)
	{
		if(isdigit(post[i]))
		{
			push(&stack, (int)post[i]);
		}
		else
		{
            int val1 = (int)pop(&stack) - '0';
			int val2 = (int)pop(&stack) - '0';
			int res = operation(val2, val1, post[i]);
			push(&stack, (char)(res + '0'));
		}
	}

	return (int)pop(&stack) - '0';
}

int main(int argc, char *argv[])
{
	char str[] = "(2*2+1)*3";
	if(isValidExpression(str))
	{
		char *post = infixToPostfix(str);
		printf("Postfix : %s\n", post);
		int res = evaluate(post);
		printf("Evaluate : %d\n", res);
		free(post);
	}
	else
	{
		printf("Expression is invalid !\n");
	}
	
	return 0;
}