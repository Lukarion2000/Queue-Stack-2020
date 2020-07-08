#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queues.h"
#include "stacks.h"
#include "benchmarks.h"
#include <math.h>
#include <time.h>

void benchmark_queue_in_out(struct queue *queue, int count, queue_type_t type)
{
	 //Typeswitch
	switch(type)
	{
		case QUEUE_CHAR:
		{
			char c;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				queue_enqueue(queue, type, '*');
			}

			for (size_t i = 0; i < count; ++i)
			{	
				queue_dequeue(queue, &c);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case QUEUE_INT:
		{
			int n;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				queue_enqueue(queue, type, 42);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				queue_dequeue(queue, &n);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case QUEUE_FLOAT:
		{
			float f;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				queue_enqueue(queue, type, 42.f);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				queue_dequeue(queue, &f);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case QUEUE_DOUBLE:
		{
			double d;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				queue_enqueue(queue, type, 42);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				queue_dequeue(queue, &d);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case QUEUE_POINTER:
		{
			void *p;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				queue_enqueue(queue, type, (void *) &queue);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				queue_dequeue(queue, &p);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}
	}
}



//########_Stacks_########

void benchmark_stack_in_out(struct stack *stack, int count, stack_type_t type)
{
	 //Typeswitch
	switch(type)
	{
		case STACK_CHAR:
		{
			char c;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				stack_push(stack, type, '*');
			}

			for (size_t i = 0; i < count; ++i)
			{	
				stack_pop(stack, &c);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case STACK_INT:
		{
			int n;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				stack_push(stack, type, 42);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				stack_pop(stack, &n);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case STACK_FLOAT:
		{
			float f;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				stack_push(stack, type, 42.f);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				stack_pop(stack, &f);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case STACK_DOUBLE:
		{
			double d;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				stack_push(stack, type, 42);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				stack_pop(stack, &d);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}

		case STACK_POINTER:
		{
			void *p;
			float start = (float)clock()/CLOCKS_PER_SEC;

			for (size_t i = 0; i < count; ++i)
			{
				stack_push(stack, type, (void *) &stack);
			}

			for (size_t i = 0; i < count; ++i)
			{	
				stack_pop(stack, &p);
			}

			float end = (float)clock()/CLOCKS_PER_SEC;
			float time = end - start;
			printf("%f\n", time);
			break;
		}
	}
}

