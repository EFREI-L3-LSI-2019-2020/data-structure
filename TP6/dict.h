#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

typedef struct dict
{
	char letter;
	char *def;
	struct dict *child; //Level + 1
    struct dict *next; //LinkedList A-Z same level
} Dict;

Dict *initDict();
void insertWord(char*, char *, Dict **);
char *searchWord(char *, Dict *);

void printDict(Dict *);
void freeDict(Dict *);