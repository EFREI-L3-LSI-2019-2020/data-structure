#include "dict.h"

Dict *initDict()
{
	Dict *dict = (Dict *)calloc(1, sizeof(Dict));
	dict->next = NULL;
	dict->child = NULL;

	return dict;
}

void insertWord(char* word, char *def, Dict **dict)
{
	if(word == NULL || def == NULL || dict == NULL || *dict == NULL){
		return;
	}

	char letter = word[0];

	Dict *next = (*dict)->next;
	printf("%d\n", (*dict)->child != NULL);
	printf("%d\n", (*dict)->child->letter == letter);
	bool isIn = (*dict)->child != NULL && (*dict)->child->letter == letter;

	while(next != NULL && !isIn){
		if(next->letter == letter){
			isIn = true;
		} else {
			next = next->next;
		}
    }

	Dict *insert;
	unsigned int c = 1;
	if(next == NULL && (*dict)->child == NULL)
	{
		insert = initDict();
		insert->letter = letter;
		(*dict)->child = insert;
	}
	else
	{
		c = 2;
		Dict *insert = initDict();
		insert->letter = word[1];
		printf("Next %c\n", letter);
		if(isIn){
			printf("is in\n");
			(*dict)->next = insert;
		}
		else{
			(*dict)->child->next = insert;
		}
	}

	if(strlen(word) == 1){
		next->def = def;
    } else {
		insertWord(word + c, def, &insert);
	}
}

/* char *searchWord(char *word, Dict *dict)
{

    if(word[0] == dict->val){

    }
	searchWord(word + 1, )
} */

void printDict(Dict *dict)
{
	if(dict != NULL)
	{
        printf("%c\n", dict->letter);
		if(dict->def != NULL) {
			printf("Definition : %s\n", dict->def);
		}

		printDict(dict->child);
		printDict(dict->next);
	}
}

void freeDict(Dict *dict)
{
	if(dict != NULL)
	{
		freeDict(dict->next);
		freeDict(dict->child);
		free(dict);
	}
}
