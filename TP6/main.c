#include "tree.h"
#include "dict.h"

int main(int argc, char *argv[])
{
	char *test = "Occis";
	char *def = "Participe passé du verbe occire, synonyme d'assassiner ou de tuer.";
	Dict *dict = initDict();
	insertWord(test, def, &dict);

	char *test1 = "Jacassement";
	char *def1 = "Discussion ou bavardage futile et bruyant.";
	insertWord(test1, def1, &dict);


	char *test2 = "Jacobite";
	char *def2 = "Royaliste britannique partisan du jacobitisme, de Jacques II et de ses descendants.";
	insertWord(test2, def2, &dict);

	printDict(dict);
	freeDict(dict);

	return 0;
}