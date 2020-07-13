#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queues.h"
#include "stacks.h"
#include "benchmarks.h"
#include <math.h>
#include <time.h>

int main(void)
{	
	/*
	Queueptr my_queue2 = queue_create(485000000);
	benchmark_queue_in_out(my_queue2, 485000000, QUEUE_POINTER);
	queue_destroy(my_queue2);


	Stackptr my_stack2 = stack_create(485000000);
	benchmark_stack_in_out(my_stack2, 485000000, STACK_POINTER);
	stack_destroy(my_stack2);
    */

	
	Stackptr peekStack = stack_create(10);
	stack_push(peekStack, STACK_CHAR, '*');
    char c;
	char b;

	float start2 = (float)clock()/CLOCKS_PER_SEC;
	for (size_t i = 0; i < 500000000; ++i)
	{	
		alternate_stack_peek(peekStack, &b);
	}

	float end2 = (float)clock()/CLOCKS_PER_SEC;
	float time2 = end2 - start2;
	printf("shorter code: %f\n", time2);

	float start = (float)clock()/CLOCKS_PER_SEC;
	for (size_t i = 0; i < 500000000; ++i)
	{
		stack_peek(peekStack, &c);
	}
	float end = (float)clock()/CLOCKS_PER_SEC;
	float time = end - start;
	printf("longer code: %f\n", time);
	stack_destroy(peekStack);
	

	/*
	Stackptr demo_stack = stack_create(50);
	srand(time(0)); 
    int n;
	for (int i = 0; i < 50; ++i)
	{
		n = rand();
		stack_push(demo_stack, STACK_INT, n);
	}
	stack_print(demo_stack);
	for (int i = 0; i < 50; ++i)
	{
		stack_pop(demo_stack, &n);
	}

	Queueptr demo_queue = queue_create(50);
	for (int i = 0; i < 50; ++i)
	{
		n = rand();
		queue_enqueue(demo_queue, QUEUE_INT, n);
	}
	for (int i = 0; i < 50; ++i)
	{
		queue_dequeue(demo_queue, &n);
	}
	stack_destroy(demo_stack);
	queue_destroy(demo_queue);
	*/
	


    return 0;
}
