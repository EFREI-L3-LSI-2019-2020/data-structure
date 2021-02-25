#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <string.h>
#include <ctype.h>

int factorial(int nb)
{
	if (nb == 1)
		return 1;
	else
		return nb * factorial(nb - 1);
}

int series(int n)
{
	if (n == 0)
		return 5;
	if (n== 1)
		return 7;
	if (n == 2)
		return 3;
	return series(n - 1) + (3 * series(n - 2)) - series(n - 3);
}

int multiply(int a, int b)
{
	if (!a || !b)
		return 0;
	if (a == 1)
		return b;
	if (b == 1)
		return a;

	return multiply(a - 1, b - 1) + a + b - 1;
}

int display(int max)
{
	if (max != 0)
	{
		display(max - 1);
		printf("%d ", max);
	}
}

void hanoi(int n, char frompeg, char topeg, char auxpeg)
{
	if (n == 1)
	{
		printf("\n%c => %c", frompeg, topeg);
	}
	else
	{
		hanoi(n - 1, frompeg, auxpeg, topeg);
		printf("\n%c => %c", frompeg, topeg);
		hanoi(n - 1, auxpeg, topeg, frompeg);
	}
}

bool expr(char*, unsigned int, unsigned int*);
bool term(char*, unsigned int, unsigned int*);
bool factor(char*, unsigned int, unsigned int*);

bool expr(char* str, unsigned int len, unsigned int* pos)
{
	if (!term(str, len, pos)) return false;
	if(*pos == len) return true;
	if(str[*pos] != '+') return true;
	(*pos)++;
	return term(str, len, pos);
}

bool term(char *str, unsigned int len, unsigned int* pos)
{
	if (!factor(str, len, pos)) return false;
	if(*pos == len) return true;
	if(str[*pos] != '*') return true;
	(*pos)++;
	return factor(str, len, pos);
}

bool factor(char *str, unsigned int len, unsigned int* pos)
{
	if(*pos > len) return false;

	if(str[*pos] == 'a')
	{
		(*pos)++;
		return true;
	}

	if(str[*pos] == '(')
	{
		(*pos)++;
		if(expr(str, len, pos))
		{
			if(*pos < len && str[*pos] == ')')
			{
				(*pos)++;
				return true;
			}
		}
	}

	return false;
}

int main(int argc, char *argv[])
{
	printf("\nfactorial : %d\n", factorial(5));
	printf("Series : %d\n", series(4));
	printf("multiply : %d\n", multiply(5, 5));
	display(5);
	hanoi(3, 'A', 'B', 'C');

	unsigned int pos = 0;
	char *str = "a*(a*a)+a";
	if(expr(str, strlen(str), &pos))
	{
		printf("\nValid\n");
	}
	else
	{
		printf("\nInvalid\n");
	}
}