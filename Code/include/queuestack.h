#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include "stdlib.h"
#include "string.h"
#include <stdbool.h>

//########_Stacks_########

typedef enum stack_type{
    STACK_CHAR,
    STACK_INT,
    STACK_FLOAT,
    STACK_DOUBLE,
    STACK_POINTER
}stack_type_t;

typedef struct stack * Stack;

void stack_destroy(Stack stack);

void stack_push(Stack stack, const stack_type_t type, ...);

void stack_pop(Stack stack, void * p);

stack_type_t stack_type_peek(Stack stack);

bool stack_is_empty(Stack stack);


//##_Multitype_Stacks_##
Stack stack_create_multi(const int capacity);

//##_Monotype_Stacks_##
Stack stack_create_mono(const int capacity, stack_type_t stacktype);



// simple integer Stack

#define int_Stack_count_max 100

typedef struct int_Stack
{
	int items[int_Stack_count_max];
	int top;
} int_Stack;

int_Stack init_int_Stack();

void push_int_Stack(int_Stack *iStack, int value);
void pop_int_Stack(int_Stack *iStack);

void peek_int_Stack(int_Stack iStack);
void show_int_Stack(int_Stack iStack);

 // Hard Mode
typedef struct item
{
	void *data;
} item;

typedef struct Stack_t
{
	int count;
	item items;
	int top;
} Stack_t;

 // Initializing an empty stack
Stack_t init_stack(int count);

#endif
