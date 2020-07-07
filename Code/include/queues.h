#ifndef QUEUES_H
#define QUEUES_H

#include "stdlib.h"
#include "string.h"
#include <stdbool.h>


//########_Queues_########

typedef enum
{
    QUEUE_CHAR,
    QUEUE_INT,
    QUEUE_FLOAT,
    QUEUE_DOUBLE,
    QUEUE_POINTER
}queue_type_t;

typedef struct queue * queueptr;

queueptr queue_create(const int capacity);

void queue_destroy(queueptr queue);

void queue_enqueue(queueptr queue, const queue_type_t type, ...);

void queue_dequeue(queueptr queue, void *dequeue_destination);

void queue_peek(queueptr queue, void *peek_destination);

queue_type_t queue_type_peek(queueptr queue);

bool queue_is_empty(queueptr queue);

//void queue_print(queueptr)


#endif
