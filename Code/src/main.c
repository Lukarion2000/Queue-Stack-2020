#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "queues.h"
#include "stacks.h"

#include "benchmarks.h"

#include "stack_extensions.h"
#include "queue_extensions.h"

#include <math.h>
#include <time.h>

int main(void)
{	
	srand(time(0));

	 //########_Fill-Empty Compare_########
	/*
	 // Compares the time difference between stacks and queues
	 // Acceptable Capacity may vary between users
	 // Showmessages false advised
	Queueptr my_queue2 = queue_create(485000000);
	benchmark_queue_in_out(my_queue2, 485000000, QUEUE_POINTER);
	queue_destroy(my_queue2);


	Stackptr my_stack2 = stack_create(485000000);
	benchmark_stack_in_out(my_stack2, 485000000, STACK_POINTER);
	stack_destroy(my_stack2);
    */

	 //########_Peek Compare_######## 
	/*
	 // Shows the time difference between stack_peek and alternate_stack_peek
	 // alternate_stack_peek takes longer
	 // Showmessages false advised
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
	*/

	 //########_Fill-Empty Demo_########
	/*
	 // Demonstrate a Stack and a Queue getting filled with random integers
	 // Showmessages true advised
	Stackptr demo_stack = stack_create(50);
	//srand(time(0)); 
    int n;
	for (int i = 0; i < 50; ++i)
	{
		n = rand();
		stack_push(demo_stack, STACK_INT, n);
	}
	//stack_print(demo_stack);
	for (int i = 0; i < 50; ++i)
	{
		stack_pop(demo_stack, &n);
	}

	Queueptr demo_queue = queue_create(50);
	for (int i = 0; i < 50; ++i)
	{
		n = rand();
		queue_enqueue(demo_queue, QUEUE_INT, i);
	}
	for (int i = 0; i < 10; ++i)
	{
		queue_dequeue(demo_queue, &n);
	}
	for (int i = 0; i < 10; ++i)
	{
		n = rand();
		queue_enqueue(demo_queue, QUEUE_INT, i+50);
	}
	queue_print(demo_queue);
	for (int i = 0; i < 40; ++i)
	{
		queue_dequeue(demo_queue, &n);
	}
	stack_destroy(demo_stack);
	queue_destroy(demo_queue);
	*/

	
	 //########_Random_Stack_Access_Demo_########
	/*
	 // Demonstrates the Random Access Function for stacks
	 // Showmessages true may be used but creates clutter
	Stackptr RA_Stack = stack_create(5);
	for (int i = 0; i < 5; i++)
	{
		int n = rand() % 50;
		stack_push(RA_Stack, STACK_INT, n);
	}
	printf("Number of items at Start: %d\n", stack_element_amount(RA_Stack));
	printf("Stack elements at Start:\n");
	stack_print(RA_Stack);
	
	int ra1, ra2, ra3;
	
	 // 5 Items in RA_Stack, 4th from top gets peeked at (second oldest)
	stack_randomaccess(RA_Stack, &ra1, 4,s_peek);
	printf("ra1 (peeked from RA_Stack): %d\n", ra1);
	printf("Number of items after peek: %d\n", stack_element_amount(RA_Stack));
	printf("Stack elements after peek:\n");
	stack_print(RA_Stack);
	
	 // 5 Items in RA_Stack, 4th from top gets popped (second oldest)
	stack_randomaccess(RA_Stack, &ra2, 4, s_pop);
	printf("ra2 (popped from RA_Stack): %d\n", ra2);
	printf("Number of items after first pop: %d\n", stack_element_amount(RA_Stack));
	printf("Stack elements after first pop:\n");
	stack_print(RA_Stack);
	
	 // 4 Items in RA_Stack, 4th from top gets popped (oldest)
	stack_randomaccess(RA_Stack, &ra3, 4,s_pop);
	printf("ra3 (popped from RA_Stack): %d\n", ra3);
	printf("Number of items after second pop: %d\n", stack_element_amount(RA_Stack));
	printf("Stack elements after second pop:\n");
	stack_print(RA_Stack);

	 // Only 3 Entries in RA_Stack Stackunderflow is caused
	stack_randomaccess(RA_Stack, &ra3, 4, s_pop);
	printf("ra3 (popped from RA_Stack): %d\n", ra3);
	printf("Number of items after third pop: %d\n", stack_element_amount(RA_Stack));
	printf("Stack elements after third pop:\n");
	stack_print(RA_Stack);
	
	stack_destroy(RA_Stack);
	*/

	 //########_Random_Queue_Access_Demo_########
	/*
	 // Demonstrates the Random Access Function for queues
	 // Showmessages true may be used but creates clutter
	Queueptr RA_Queue = queue_create(5);
	for (int i = 0; i < 5; i++)
	{
		int n = rand() % 50;
		queue_enqueue(RA_Queue, QUEUE_INT, n);
	}
	printf("Number of items at Start: %d\n", queue_element_amount(RA_Queue));
	printf("Queue elements at Start:\n");
	queue_print(RA_Queue);
	
	int ra1, ra2, ra3;
	
	 // 5 Items in RA_Queue, 4th from head gets peeked at (second newest)
	queue_randomaccess(RA_Queue, &ra1, 4,q_peek);
	printf("ra1 (peeked from RA_Queue): %d\n", ra1);
	printf("Number of items after peek: %d\n", queue_element_amount(RA_Queue));
	printf("Queue elements after peek:\n");
	queue_print(RA_Queue);
	
	 // 5 Items in RA_Queue, 4th from head gets dequeue (second newest)
	queue_randomaccess(RA_Queue, &ra2, 4, q_dequeue);
	printf("ra2 (dequeued from RA_Queue): %d\n", ra2);
	printf("Number of items after first dequeue: %d\n", queue_element_amount(RA_Queue));
	printf("Queue elements after first dequeue:\n");
	queue_print(RA_Queue);
	
	 // 4 Items in RA_Queue, 4th from head gets dequeue (newest)
	queue_randomaccess(RA_Queue, &ra3, 4,q_dequeue);
	printf("ra3 (dequeued from RA_Queue): %d\n", ra3);
	printf("Number of items after second dequeue: %d\n", queue_element_amount(RA_Queue));
	printf("Queue elements after second dequeue:\n");
	queue_print(RA_Queue);

	 // Only 3 Entries in RA_Queuem, Circular Queue will return the 1st item
	queue_randomaccess(RA_Queue, &ra3, 4, q_dequeue);
	printf("ra3 (dequeued from RA_Queue): %d\n", ra3);
	printf("Number of items after third dequeue: %d\n", queue_element_amount(RA_Queue));
	printf("Queue elements after third dequeue:\n");
	queue_print(RA_Queue);
	
	queue_destroy(RA_Queue);
	*/

	 //########_Search_Stack_Demo_########
	/*
	 // Demonstrates the Search Function for stacks
	 // Showmessages true may be used but creates clutter
	Stackptr SEARCH_stack = stack_create(10);
	stack_push(SEARCH_stack, STACK_CHAR, '*');
 	stack_push(SEARCH_stack, STACK_INT, 100);
 	for (int i = 0; i < 6; i++)
 	{
 		int n = rand() % 100;
 		stack_push(SEARCH_stack, STACK_INT, n);
 	}
 	stack_push(SEARCH_stack, STACK_CHAR, '#');
	stack_push(SEARCH_stack, STACK_CHAR, '+');
	stack_print(SEARCH_stack);

	// Successfull search returns a value greater than 0 (usable for stack_randomaccess)
	printf("The first '#' in the Stack lies %d from top. \n", stack_search(SEARCH_stack, STACK_CHAR, s_search_value, '#'));
	printf("There are no floats in this Stack indicated by: %d. \n", stack_search(SEARCH_stack, STACK_FLOAT, s_search_type));
	stack_print(SEARCH_stack); // Show that Order is kept
	stack_destroy(SEARCH_stack);
	*/

	 //########_Search_Queue_Demo_########
	/*
	 // Demonstrates the Search Function for queues
	 // Showmessages true may be used but creates clutter
	Queueptr SEARCH_queue = queue_create(10);
	queue_enqueue(SEARCH_queue, QUEUE_CHAR, '*');
 	queue_enqueue(SEARCH_queue, QUEUE_INT, 100);
 	for (int i = 0; i < 6; i++)
 	{
 		int n = rand() % 100;
 		queue_enqueue(SEARCH_queue, QUEUE_INT, n);
 	}
 	queue_enqueue(SEARCH_queue, QUEUE_CHAR, '#');
	queue_enqueue(SEARCH_queue, QUEUE_CHAR, '+');
	queue_print(SEARCH_queue);

	// Successfull search returns a value greater than 0 (usable for queue_randomaccess)
	printf("The first '#' in the Queue lies %d from head. \n", queue_search(SEARCH_queue, QUEUE_CHAR, s_search_value, '#'));
	queue_print(SEARCH_queue);
	printf("There are no floats in this Queue indicated by: %d. \n", queue_search(SEARCH_queue, QUEUE_FLOAT, s_search_type));
	queue_print(SEARCH_queue);  // Show that Order is kept
	queue_destroy(SEARCH_queue);
	*/

	//########_Delete all integers from a Stack_########
	/*
	 // Searchfunction and Random Access combined to search for certain Datatypes
	 // Showmessages  false advised
	Stackptr No_INT_Stack = stack_create(500);
	for (int i = 0; i < 500; ++i)
	{
		int n = rand() % 2;
		if(n == 1) stack_push(No_INT_Stack, STACK_INT, 1);
		else stack_push(No_INT_Stack, STACK_CHAR, '*');
	}
	printf("Stack with Integers:\n");
	stack_print(No_INT_Stack);
	
	 // Delete Loop
	int start_amount = stack_element_amount(No_INT_Stack);
	for (int i = 0; i < start_amount; i++)
	{
		int m = stack_search(No_INT_Stack, STACK_INT, s_search_type);
		if (m > 0)
		{
			int del; // Integer Dumpster
			stack_randomaccess(No_INT_Stack, &del, m, s_pop);
		}
		else break;
	}
	printf("Stack without Integers:\n");
	stack_print(No_INT_Stack);
	printf("Integers deleted: %d\n", (start_amount - stack_element_amount(No_INT_Stack)));
	stack_destroy(No_INT_Stack);
	*/

	//########_Delete all integers from a Queue_########
	/*
	 // Searchfunction and Random Access combined to search for certain Datatypes
	 // Showmessages false advised
	Stackptr No_INT_Stack = stack_create(500);
	for (int i = 0; i < 500; ++i)
	{
		int n = rand() % 2;
		if(n == 1) stack_push(No_INT_Stack, STACK_INT, 1);
		else stack_push(No_INT_Stack, STACK_CHAR, '*');
	}
	printf("Stack with Integers:\n");
	stack_print(No_INT_Stack);
	
	 // Delete Loop
	int start_amount = stack_element_amount(No_INT_Stack);
	for (int i = 0; i < start_amount; i++)
	{
		int m = stack_search(No_INT_Stack, STACK_INT, s_search_type);
		if (m > 0)
		{
			int del; // Integer Dumpster
			stack_randomaccess(No_INT_Stack, &del, m, s_pop);
		}
		else break;
	}
	printf("Stack without Integers:\n");
	stack_print(No_INT_Stack);
	printf("Integers deleted: %d\n", (start_amount - stack_element_amount(No_INT_Stack)));
	stack_destroy(No_INT_Stack);
	*/

	//########_Delete all integers from a Queue_########
	/*
	Queueptr No_INT_Queue = queue_create(500);
	for (int i = 0; i < 500; ++i)
	{
		int n = rand() % 2;
		if(n == 1) queue_enqueue(No_INT_Queue, QUEUE_INT, 1);
		else queue_enqueue(No_INT_Queue, QUEUE_CHAR, '*');
	}
	printf("Queue with Integers:\n");
	queue_print(No_INT_Queue);
	
	 // Delete Function
	int start_amount = queue_element_amount(No_INT_Queue);
	for (int i = 0; i < start_amount; i++)
	{
		int m = queue_search(No_INT_Queue, QUEUE_INT, s_search_type);
		if (m > 0)
		{
			int del; // Integer Dumpster
			queue_randomaccess(No_INT_Queue, &del, m, s_pop);
		}
		else break;
	}
	printf("Queue without Integers:\n");
	queue_print(No_INT_Queue);
	printf("Integers deleted: %d\n", (start_amount - queue_element_amount(No_INT_Queue)));
	queue_destroy(No_INT_Queue);
	*/


    return 0;
}