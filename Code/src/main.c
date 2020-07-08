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
	Queueptr my_queue2 = queue_create(485000000);
	benchmark_queue_in_out(my_queue2, 485000000, QUEUE_POINTER);
	queue_destroy(my_queue2);


	Stackptr my_stack2 = stack_create(485000000);
	benchmark_stack_in_out(my_stack2, 485000000, STACK_POINTER);
	stack_destroy(my_stack2);
    
    return 0;
}
