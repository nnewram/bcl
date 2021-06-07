#include "bcl_list.h"

void bcl(list, push)(struct List *list, void *element) {
	if ((list->length + 1) >= list->allocated_for) {
		list->start = realloc(list->start, realloc_algorithm(list->length) * list->underlying_size);
		list->allocated_for = realloc_algorithm(list->length);
		list->end = list->start + list->length * list->underlying_size;
	}

	*(list->start + list->length++) = element;
}

struct List *bcl(list, new)(size_t len, size_t underlying_size) {
	struct List *list = malloc(sizeof *list);
	list->underlying_size = underlying_size;
	list->length = 0;
	list->start = malloc(len * sizeof list->start);
	list->end = list->start + len * sizeof list->start;
	list->allocated_for = len;

	return list;
}


void bcl(list, free)(struct List *list) {
	free(list->start);
	list->start = NULL;
	list->end = NULL;
	list->allocated_for = list->length = 0;
	free(list);
}

// only accepts lists with trivial members
void bcl(list, deep_free)(struct List *list) {
	for (void **ptr = list->start; ptr != list->end; ptr += list->underlying_size) {
		if (*ptr)
			free(*ptr);
	}

	list->length = 0;
}
