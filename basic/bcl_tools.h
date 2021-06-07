#include <stddef.h>
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#ifndef bcsl_tools
#define bcl_tools

#define CONCAT(a, b, ...) a ## _ ## b ## _ ## __VA_ARGS__

#define bcl(a, ...) bcl_(a, ##__VA_ARGS__, 2, 1)
#define bcl_(a, b, argc, ...) bcl##argc(a, b)
#define bcl1(name, ...) CONCAT(bcl, name)
#define bcl2(name, funcname) CONCAT(bcl, name, funcname)

#define realloc_algorithm(old_size) ((old_size) + 1)
// change as needed


#define pointer(type) type *
#define iterator_define(type)\
	pointer(type) start;\
	pointer(type) end;

#endif