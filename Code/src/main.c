#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queues.h"
#include "stacks.h"
#include <math.h>
#include <time.h>

int main(void)
{
	Stackptr my_stack = stack_create(10);
	stack_push(my_stack, STACK_CHAR, 'z');
	stack_push(my_stack, STACK_CHAR, 'x');
	stack_push(my_stack, STACK_CHAR, 'y');
    stack_push(my_stack, STACK_INT, 124);
    stack_push(my_stack, STACK_FLOAT, 4.55);
    float f;
    double d;
    stack_pop(my_stack, &d);
    stack_push(my_stack, STACK_DOUBLE, 7.21);
    stack_pop(my_stack, &d);

    
    return 0;
}
