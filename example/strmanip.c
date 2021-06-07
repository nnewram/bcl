#include "bcl_string.h"

int main() {
	struct String *str = bcl(string, copy)("bruh what is this shit");

//	struct String *sanitized = bcl(string, replace)(str, "")

	struct List *ll = bcl(string, split)(str, " ");

	for (int i = 0; i < ll->length; i++)
		printf("%s\n", (*((struct String **)(ll->start) + i))->start);


	for (int i = 0; i < ll->length; i++)
		bcl(string, free)(((struct String **)ll->start)[i]);
	
	bcl(list, free)(ll);
	bcl(string, free)(str);
}