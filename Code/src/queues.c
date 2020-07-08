#include "queues.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

 //false: print only error messages
 //true: print all messages
#define Showmessages false


//########_Queues_########

 // Struct to contain a multitype queue element
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

 // Struct to represent a Cicular Queue
struct queue
{
     // Boolean flag needed to differentiate between queue overflow and an empty queue
    bool is_empty;
     // "Back" of the queue
    int tail;
     // "Front" of the queue
    int head;
     // Maximum amount of objects in the queue
    int capacity;
     // Array of queue_element
    struct queue_element *elements;
};

 // Creates and returns a new Multitype queue
struct queue *queue_create(const int capacity)
{
    struct queue *new_queue = malloc(sizeof *new_queue);
    if (!new_queue)
    {
        fprintf(stderr, "Failed to allocate memory for new queue.");
        exit(EXIT_FAILURE);
    }

    new_queue->capacity = capacity;
    new_queue->tail = 0;
    new_queue->head = 0;
    new_queue->is_empty = true;

    new_queue->elements = malloc(sizeof *new_queue->elements * capacity);
    if (!new_queue->elements)
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
     // Check for Queue overflow 
    if (queue->tail == queue->head && !queue_is_empty(queue))
    {
        fprintf(stderr, "Queue overflow!\n");
        exit(EXIT_FAILURE);
    }

     // Operations for <stdarg.h>
    va_list enqueue_argument;
    va_start(enqueue_argument, enqueue_type);

     // Typeswitch
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
    
    va_end(enqueue_argument);

     // Set element type
    queue->elements[queue->tail].type = enqueue_type;

     // Set the is_empty flag to false
    if(queue_is_empty(queue))
    {
        queue->is_empty = false;
    }

    if(queue->tail == queue->capacity - 1) 
    {
        queue->tail = 0;
    }
    else
    {
        queue->tail++;
    }
}

void queue_dequeue(struct queue *queue, void *dequeue_destination)
{
    if (queue_is_empty(queue))
    {
        fprintf(stderr, "Queue underflow!\n");
        exit(EXIT_FAILURE);
    }

     // Typeswitch
    switch (queue->elements[queue->head].type)
    {
        case QUEUE_CHAR:
            *((char *) dequeue_destination) = queue->elements[queue->head].data.qval_c;
            if(Showmessages){printf("Dequeued char %c from the queue.\n", queue->elements[queue->head].data.qval_c);}
            break;

        case QUEUE_INT:
            *((int *) dequeue_destination) = queue->elements[queue->head].data.qval_i;
            if(Showmessages){printf("Dequeued int %d from the queue.\n", queue->elements[queue->head].data.qval_i);}
            break;

        case QUEUE_FLOAT:
            *((float *) dequeue_destination) = queue->elements[queue->head].data.qval_f;
            if(Showmessages){printf("Dequeued float %f from the queue.\n", queue->elements[queue->head].data.qval_f);}
            break;

        case QUEUE_DOUBLE:
            *((double *) dequeue_destination) = queue->elements[queue->head].data.qval_d;
            if(Showmessages){printf("Dequeued double %f from the queue.\n", queue->elements[queue->head].data.qval_d);}
            break;

        case QUEUE_POINTER:
            *((void **) dequeue_destination) = queue->elements[queue->head].data.qval_p;
            if(Showmessages){printf("Dequeued pointer %p from the queue.\n", queue->elements[queue->head].data.qval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in queue_dequeue()\n");
            exit(EXIT_FAILURE);
    }

    if(queue->head == queue->capacity - 1) 
    {
        queue->head = 0;
    }
    else
    {
        queue->head++;
    }

    if(queue->tail == queue->head)
    {
        queue->is_empty = true;
    }
}

queue_type_t queue_type_peek(struct queue *queue)
{
    if (queue_is_empty(queue))
    {
        fprintf(stderr, "Queue underflow!\n");
        exit(EXIT_FAILURE);
    }

    return queue->elements[queue->head].type;
}


void queue_peek(struct queue *queue, void *peek_destination)
{
    if (queue_is_empty(queue))
    {
        fprintf(stderr, "Queue underflow!\n");
        exit(EXIT_FAILURE);
    }

     // Typeswitch
    switch (queue->elements[queue->head].type)
    {
        case QUEUE_CHAR:
            *((char *) peek_destination) = queue->elements[queue->head].data.qval_c;
            if(Showmessages){printf("Peeked at char %c from the queue", queue->elements[queue->head].data.qval_c);}
            break;

        case QUEUE_INT:
            *((int *) peek_destination) = queue->elements[queue->head].data.qval_i;
            if(Showmessages){printf("Peeked at int %d from the queue", queue->elements[queue->head].data.qval_i);}
            break;

        case QUEUE_FLOAT:
            *((float *) peek_destination) = queue->elements[queue->head].data.qval_f;
            if(Showmessages){printf("Peeked at float %f from the queue", queue->elements[queue->head].data.qval_f);}
            break;

        case QUEUE_DOUBLE:
            *((double *) peek_destination) = queue->elements[queue->head].data.qval_d;
            if(Showmessages){printf("Peeked at double %f from the queue", queue->elements[queue->head].data.qval_d);}
            break;

        case QUEUE_POINTER:
            *((void **) peek_destination) = queue->elements[queue->head].data.qval_p;
            if(Showmessages){printf("Peeked at pointer %p from the queue", queue->elements[queue->head].data.qval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in queue_dequeue()\n");
            exit(EXIT_FAILURE);
    }
}

//boolean Flag is a working Placeholder until a better solution is found
bool queue_is_empty(struct queue *queue)
{
    return queue->is_empty;
}

// Print the whole Queue
void queue_print(struct queue *queue)
{
    
}