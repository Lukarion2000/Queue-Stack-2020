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

typedef struct queue * Queueptr;

Queueptr queue_create(const int capacity);

void queue_destroy(Queueptr queue);

void queue_enqueue(Queueptr queue, const queue_type_t type, ...);

void queue_dequeue(Queueptr queue, void *dequeue_destination);

void queue_peek(Queueptr queue, void *peek_destination);

queue_type_t queue_type_peek(Queueptr queue);

bool queue_is_empty(Queueptr queue);

void queue_print(Queueptr);


#endif
