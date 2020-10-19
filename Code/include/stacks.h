#ifndef STACKS_H
#define STACKS_H

#include <stdlib.h>
#include <string.h>
#include <stdbool.h>

//########_Stacks_########

typedef enum
{
    STACK_CHAR,
    STACK_INT,
    STACK_FLOAT,
    STACK_DOUBLE,
    STACK_POINTER
}stack_type_t;

typedef struct stack * Stackptr;

Stackptr stack_create(const int capacity);

void stack_destroy(Stackptr stack);

void stack_push(Stackptr stack, const stack_type_t type, ...);

void stack_pop(Stackptr stack, void *pop_destination);

void stack_peek(Stackptr stack, void *peek_destination);

void alternate_stack_peek(Stackptr stack, void *peek_destination);

stack_type_t stack_type_peek(Stackptr stack);

bool stack_is_empty(Stackptr stack);

void stack_print(Stackptr stack);

int stack_capacity(Stackptr stack);

int stack_element_amount(Stackptr stack);

#endif
