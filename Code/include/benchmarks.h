#ifndef BENCHMARKS_H
#define BENCHMARKS_H

#include "queues.h"
#include "stacks.h"

#include "stdlib.h"
#include "string.h"
#include <stdbool.h>




//########_Queues_########

void benchmark_queue_in_out(struct queue *queue, int count, queue_type_t type);

//########_Stacks_########

void benchmark_stack_in_out(struct stack *stack, int count, stack_type_t type);

#endif
