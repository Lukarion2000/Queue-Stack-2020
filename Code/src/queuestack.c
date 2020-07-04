#include "queuestack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>

//########_Stacks_########

int_Stack init_int_Stack()
{
	int_Stack Stack_new;
	Stack_new.top = -1;
	return Stack_new;
}

void push_int_Stack(int_Stack *iStack, int value)
{
	if(iStack->top + 1 == int_Stack_count_max)
	{
		printf("STACKOVERFLOOOOOOOOW!\n");
	}
	else
	{
		iStack->top++;
		printf("%d\n", iStack->top);
		iStack->items[iStack->top] = value;
	}
}

int pop_int_Stack(int_Stack *iStack)
{
	if(iStack->top == -1)
	{
		printf("STACKUNDERFLOOOOOOOOW!\n");
	}
	else
	{
		printf("Popping %d\n", iStack->top);
		int value = iStack->items[iStack->top];
		iStack->top--;
	}
}

void peek_int_Stackt_Stack iStack) //needs to return a value(is shortened version of pop + push)
{
	printf("Showing top item of stack.\n");
	printf("%d\n", iStack.items[iStack.top]);
}

void show_int_Stack(int_Stack iStack)
{
	printf("Showing all items.\n");
	for (int i = 0; i < iStack.top + 1; ++i)
		{
			printf("[%d]\n", iStack.items[i]);
		}
}



/*Stack_t init_stack(int count_max)
{
	Stack_t Stack_new =
	{
		int count = count_max;
		int top = -1;
		item items[count]; 
	}
	return Stack_new;
}*/


