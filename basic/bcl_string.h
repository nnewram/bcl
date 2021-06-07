#include "bcl_tools.h"
#include "bcl_list.h"

#ifndef bcl_string
#define bcl_string

struct String {
	iterator_define(char)
	size_t length;
};

struct String *bcl(string, new)(size_t);

struct String *bcl(string, concat)(struct String *, struct String *);
struct String *bcl(string, between)(char *, char *);
struct String *bcl(string, format)(struct String *, ...);

struct List   *bcl(string, split_impl_charp)(struct String *, char *);
struct List   *bcl(string, split_impl_string)(struct String *, struct String *);
#define bcl_string_split(p1, p2) _Generic((p2), char *: bcl(string, split_impl_charp), struct string *: bcl(string, split_impl_string))(p1, p2)

struct String *bcl(string, copy_impl_charp)(char *);
struct String *bcl(string, copy_impl_string)(struct String *);
#define bcl_string_copy(what) _Generic((what), char *: bcl(string, copy_impl_charp), struct string *: bcl(string, copy_impl_string))(what)

void bcl(string, free)(struct String *);

#endif