#include "bcl_tools.h"
#ifndef bcl_list
#define bcl_list

struct List {
	iterator_define(pointer(void))

	size_t length;
	size_t allocated_for;
	size_t underlying_size;
};

struct List *bcl(list, new)(size_t len, size_t underlying_size);

void bcl(list, push)(struct List *, void *);
void *bcl(list, pop)(struct List *);
void *bcl(list, remove)(struct List *, size_t index);

void bcl(list, free)(struct List *);
void bcl(list, deep_free)(struct List *);

#endif