#ifndef QUEUESTACK_H
#define QUEUESTACK_H

#include "stdlib.h"
#include "string.h"

//########_Stacks_########

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
