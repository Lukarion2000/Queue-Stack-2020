#include "queues.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

 //false: print only error messages
 //true: print all messages
#define Showmessages true


//########_Queues_########

 // Struct to contain a Multitype queue element
struct queue_element
{
    queue_type_t type;
    union {
        char qval_c;
        int qval_i;
        float qval_f;
        double qval_d;
        void * qval_p;
    } data;
};

 //TODO Descriptions
struct queue {
    int tail;
    int head;
    int capacity;
    struct queue_element *elements;
};

 // Creates and returns a new Multitype queue
struct queue *queue_create(const int capacity)
{
    struct queue *new_queue = malloc(sizeof *new_queue);
    if ( !new_queue )
    {
        fprintf(stderr, "Failed to allocate memory for new queue.");
        exit(EXIT_FAILURE);
    }

    new_queue->capacity = capacity;
    new_queue->tail = 0;

    new_queue->elements = malloc(sizeof *new_queue->elements * capacity);
    if ( !new_queue->elements )
    {
        free(new_queue);
        fprintf(stderr, "Failed to allocate memory for queue elements.");
        exit(EXIT_FAILURE);
    }

    return new_queue;
}



void queue_destroy(struct queue *queue)
{
    free(queue->elements);
    free(queue);
}

void queue_enqueue(struct queue *queue, const queue_type_t enqueue_type, ...)
{
    if ( queue->tail == queue->capacity )
    {
        fprintf(stderr, "Stackoverflow!\n");
        exit(EXIT_FAILURE);
    }

    va_list enqueue_argument;
    va_start(enqueue_argument, enqueue_type);

    switch (enqueue_type)
    {
        case QUEUE_CHAR:
            queue->elements[queue->tail].data.qval_c = (char) va_arg(enqueue_argument, int);
            if(Showmessages){printf("Enqueued char %c on the queue.\n", queue->elements[queue->tail].data.qval_c);}
            break;

        case QUEUE_INT:
            queue->elements[queue->tail].data.qval_i = va_arg(enqueue_argument, int);
            if(Showmessages){printf("Enqueued int %i on the queue.\n", queue->elements[queue->tail].data.qval_i);}
            break;

        case QUEUE_FLOAT:
            queue->elements[queue->tail].data.qval_f = (float) va_arg(enqueue_argument, double);
            if(Showmessages){printf("Enqueued float %f on the queue.\n", queue->elements[queue->tail].data.qval_f);}
            break;

        case QUEUE_DOUBLE:
            queue->elements[queue->tail].data.qval_d = va_arg(enqueue_argument, double);
            if(Showmessages){printf("Enqueued double %f on the queue.\n", queue->elements[queue->tail].data.qval_d);}
            break;

        case QUEUE_POINTER:
            queue->elements[queue->tail].data.qval_p = va_arg(enqueue_argument, void *);
            if(Showmessages){printf("Enqueued pointer %p on the queue.\n", queue->elements[queue->tail].data.qval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in queue_enqueue()\n");
            exit(EXIT_FAILURE);
    }
    
    queue->elements[queue->tail++].type = enqueue_type;

    va_end(enqueue_argument);
}

void queue_dequeue(struct queue *queue, void *dequeue_destination)
{
    if ( queue->tail == 0 )
    {
        fprintf(stderr, "Stackunderflow!\n");
        exit(EXIT_FAILURE);
    }

    switch ( queue->elements[--queue->tail].type )
    {
        case QUEUE_CHAR:
            *((char *) dequeue_destination) = queue->elements[queue->tail].data.qval_c;
            if(Showmessages){printf("Popped pointer %c from the queue.\n", queue->elements[queue->tail].data.qval_c);}
            break;

        case QUEUE_INT:
            *((int *) dequeue_destination) = queue->elements[queue->tail].data.qval_i;
            if(Showmessages){printf("Popped int %d from the queue.\n", queue->elements[queue->tail].data.qval_i);}
            break;

        case QUEUE_FLOAT:
            *((float *) dequeue_destination) = queue->elements[queue->tail].data.qval_f;
            if(Showmessages){printf("Popped float %f from the queue.\n", queue->elements[queue->tail].data.qval_f);}
            break;

        case QUEUE_DOUBLE:
            *((double *) dequeue_destination) = queue->elements[queue->tail].data.qval_d;
            if(Showmessages){printf("Popped double %f from the queue.\n", queue->elements[queue->tail].data.qval_d);}
            break;

        case QUEUE_POINTER:
            *((void **) dequeue_destination) = queue->elements[queue->tail].data.qval_p;
            if(Showmessages){printf("Popped pointer %p from the queue.\n", queue->elements[queue->tail].data.qval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in queue_dequeue()\n");
            exit(EXIT_FAILURE);
    }
}

queue_type_t queue_type_peek(struct queue *queue)
{
    if ( queue->tail == 0 )
    {
        fprintf(stderr, "Stackunderflow!\n");
        exit(EXIT_FAILURE);
    }

    return queue->elements[queue->tail - 1].type;
}


void queue_peek(struct queue *queue, void *peek_destination)
{
    if ( queue->tail == 0 )
    {
        fprintf(stderr, "Stackunderflow!\n");
        exit(EXIT_FAILURE);
    }

    switch ( queue->elements[queue->tail].type )
    {
        case QUEUE_CHAR:
            *((char *) peek_destination) = queue->elements[queue->tail].data.qval_c;
            if(Showmessages){printf("Peeked at char %c from the queue", queue->elements[queue->tail].data.qval_c);}
            break;

        case QUEUE_INT:
            *((int *) peek_destination) = queue->elements[queue->tail].data.qval_i;
            if(Showmessages){printf("Peeked at int %d from the queue", queue->elements[queue->tail].data.qval_i);}
            break;

        case QUEUE_FLOAT:
            *((float *) peek_destination) = queue->elements[queue->tail].data.qval_f;
            if(Showmessages){printf("Peeked at float %f from the queue", queue->elements[queue->tail].data.qval_f);}
            break;

        case QUEUE_DOUBLE:
            *((double *) peek_destination) = queue->elements[queue->tail].data.qval_d;
            if(Showmessages){printf("Peeked at double %f from the queue", queue->elements[queue->tail].data.qval_d);}
            break;

        case QUEUE_POINTER:
            *((void **) peek_destination) = queue->elements[queue->tail].data.qval_p;
            if(Showmessages){printf("Peeked at pointer %p from the queue", queue->elements[queue->tail].data.qval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in queue_dequeue()\n");
            exit(EXIT_FAILURE);
    }
}


 // Alternate peek implementation
/*
void queue_peek(struct queue *queue, void *peek_destination)
{
    queue_type_t enqueue_type = queue_type_peek(queue);
    queue_dequeue(queue, &peek_destination);
    queue_enqueue(queue, enqueue_type, peek_destination);
}
*/


bool queue_is_empty(struct queue *queue)
{
    return queue->tail == 0;
}