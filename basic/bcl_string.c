#include "bcl_string.h"
#include "bcl_list.h"

struct String *bcl(string, new)(size_t len) {
	if (len == 0)
		len = 1;
	
	struct String *new = malloc(sizeof *new);
	new->start = calloc(len, 1);
	new->end = new->start + len;
	new->length = len;

	return new;
}

struct String *bcl(string, copy_impl_charp)(char *old) {
	size_t old_len = strlen(old);
	struct String *new = bcl(string, new)(old_len);
	memcpy(new->start, old, old_len);

	return new;
}

struct String *bcl(string, copy_impl_string)(struct String *old) {
	struct String *new = bcl(string, new)(old->length);
	memcpy(new->start, old->start, old->length);

	return new;
}

struct String *bcl(string, concat)(struct String *a, struct String *b) {
	struct String *new = bcl(string, new)(a->length + b->length + 1);

	memcpy(new->start, a->start, a->length);
	memcpy(new->start + a->length, b->start, b->length);

	return new;
}

struct String *bcl(string, between)(char *p1, char *p2) {
	struct String *new = bcl(string, new)(p2 - p1 + 1);
	memcpy(new->start, p1, p2 - p1);

	return new;
}

struct List *bcl(string, split_impl_string)(struct String *str, struct String *delim) {
	struct List *list = bcl(list, new)(1, sizeof str->start);
	char *previous = str->start;

	for (char *ptr = str->start; ptr < str->end; ptr++) {
		char *ptr_cpy = ptr;
		while (*ptr_cpy == *(delim->start + (ptr_cpy - ptr))) {
			if (ptr_cpy - ptr == delim->end - delim->start - 1) {
				bcl(list, push)(list, bcl(string, between)(previous, ptr));
				ptr = ptr_cpy + 1;
				previous = ptr;
				break;
			}
			else if (ptr_cpy >= str->end)
				break;
			else
				ptr_cpy++;
		}
	}

	bcl(list, push)(list, bcl(string, between)(previous, str->end));

	return list;
}

struct List *bcl(string, split_impl_charp)(struct String *str, char *delim) {
	struct List *list = bcl(list, new)(1, sizeof str->start);
	char *previous = str->start;

	size_t delimsize = strlen(delim);

	for (char *ptr = str->start; ptr < str->end; ptr++) {
		char *ptr_cpy = ptr;
		while (*ptr_cpy == *(delim + (ptr_cpy - ptr))) {
			if (ptr_cpy - ptr == delimsize - 1) {
				bcl(list, push)(list, bcl(string, between)(previous, ptr));
				ptr = ptr_cpy + 1;
				previous = ptr;
				break;
			}
			else if (ptr_cpy >= str->end)
				break;
			else
				ptr_cpy++;
		}
	}

	bcl(list, push)(list, bcl(string, between)(previous, str->end));

	return list;
}

void bcl(string, free)(struct String *str) {
	free(str->start);
	str->start = NULL;
	str->end = NULL;
	str->length = -1;
	free(str);
}