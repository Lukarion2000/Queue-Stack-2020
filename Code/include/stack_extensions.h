#ifndef STACK_EXTENSIONS_H
#define STACK_EXTENSIONS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "stacks.h"

typedef enum
{
    s_pop,
    s_peek
}mode_type_s;

typedef enum
{
    s_search_type,
    s_search_value
}search_mode_s;


void stack_randomaccess(Stackptr stack, void *ra_destination, int n, mode_type_s mode);

int stack_search(Stackptr stack, const stack_type_t searched_type, search_mode_s search_mode, ...);

#endif