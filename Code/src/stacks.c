#include "stacks.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

 //false: print only error messages
 //true: print all messages
#define Showmessages true

 //########_Stacks_########

 // Struct to contain a Multitype Stack element
struct stack_element
{
    stack_type_t type;
    union {
        char sval_c;
        int sval_i;
        float sval_f;
        double sval_d;
        void * sval_p;
    } data;
};

 //TODO Descriptions
struct stack
{
    int top;
    int capacity;
    struct stack_element *elements;
};

 // Creates and returns a new Multitype Stack
struct stack *stack_create(const int capacity)
{
    struct stack *new_stack = malloc(sizeof *new_stack);
    if (!new_stack)
    {
        fprintf(stderr, "Failed to allocate memory for new Stack.");
        exit(EXIT_FAILURE);
    }

    new_stack->capacity = capacity;
    new_stack->top = 0;

    new_stack->elements = malloc(sizeof *new_stack->elements * capacity);
    if (!new_stack->elements)
    {
        free(new_stack);
        fprintf(stderr, "Failed to allocate memory for Stack elements.");
        exit(EXIT_FAILURE);
    }

    return new_stack;
}



void stack_destroy(struct stack *stack)
{
    free(stack->elements);
    free(stack);
}

void stack_push(struct stack *stack, const stack_type_t push_type, ...)
{
    if (stack->top == stack->capacity)
    {
        fprintf(stderr, "Stack overflow!\n");
        exit(EXIT_FAILURE);
    }

    va_list push_argument;
    va_start(push_argument, push_type);

    switch (push_type)
    {
        case STACK_CHAR:
            stack->elements[stack->top].data.sval_c = (char) va_arg(push_argument, int);
            if(Showmessages){printf("Pushed char %c on the Stack \n", stack->elements[stack->top].data.sval_c);}
            break;

        case STACK_INT:
            stack->elements[stack->top].data.sval_i = va_arg(push_argument, int);
            if(Showmessages){printf("Pushed int %i on the Stack \n", stack->elements[stack->top].data.sval_i);}
            break;

        case STACK_FLOAT:
            stack->elements[stack->top].data.sval_f = (float) va_arg(push_argument, double);
            if(Showmessages){printf("Pushed float %f on the Stack \n", stack->elements[stack->top].data.sval_f);}
            break;

        case STACK_DOUBLE:
            stack->elements[stack->top].data.sval_d = va_arg(push_argument, double);
            if(Showmessages){printf("Pushed double %f on the Stack \n", stack->elements[stack->top].data.sval_d);}
            break;

        case STACK_POINTER:
            stack->elements[stack->top].data.sval_p = va_arg(push_argument, void *);
            if(Showmessages){printf("Pushed pointer %p on the Stack \n", stack->elements[stack->top].data.sval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in stack_push()\n");
            exit(EXIT_FAILURE);
    }
    
    stack->elements[stack->top++].type = push_type;

    va_end(push_argument);
}

void stack_pop(struct stack *stack, void *pop_destination)
{
    if (stack_is_empty(stack))
    {
        fprintf(stderr, "Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    switch (stack->elements[--stack->top].type)
    {
        case STACK_CHAR:
            *((char *) pop_destination) = stack->elements[stack->top].data.sval_c;
            if(Showmessages){printf("Popped char %c from the Stack.\n", stack->elements[stack->top].data.sval_c);}
            break;

        case STACK_INT:
            *((int *) pop_destination) = stack->elements[stack->top].data.sval_i;
            if(Showmessages){printf("Popped int %d from the Stack.\n", stack->elements[stack->top].data.sval_i);}
            break;

        case STACK_FLOAT:
            *((float *) pop_destination) = stack->elements[stack->top].data.sval_f;
            if(Showmessages){printf("Popped float %f from the Stack.\n", stack->elements[stack->top].data.sval_f);}
            break;

        case STACK_DOUBLE:
            *((double *) pop_destination) = stack->elements[stack->top].data.sval_d;
            if(Showmessages){printf("Popped double %f from the Stack.\n", stack->elements[stack->top].data.sval_d);}
            break;

        case STACK_POINTER:
            *((void **) pop_destination) = stack->elements[stack->top].data.sval_p;
            if(Showmessages){printf("Popped pointer %p from the Stack.\n", stack->elements[stack->top].data.sval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in stack_pop()\n");
            exit(EXIT_FAILURE);
    }
}

stack_type_t stack_type_peek(struct stack *stack)
{
    if ( stack->top == 0 )
    {
        fprintf(stderr, "Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->elements[stack->top - 1].type;
}

//stack_peek without removing the item from the Stack
void stack_peek(struct stack *stack, void *peek_destination)
{
    if ( stack->top == 0 )
    {
        fprintf(stderr, "Stack underflow!\n");
        exit(EXIT_FAILURE);
    }

    switch ( stack->elements[stack->top].type )
    {
        case STACK_CHAR:
            *((char *) peek_destination) = stack->elements[stack->top].data.sval_c;
            if(Showmessages){printf("Peeked at char %c from the Stack.\n", stack->elements[stack->top].data.sval_c);}
            break;

        case STACK_INT:
            *((int *) peek_destination) = stack->elements[stack->top].data.sval_i;
            if(Showmessages){printf("Peeked at int %d from the Stack.\n", stack->elements[stack->top].data.sval_i);}
            break;

        case STACK_FLOAT:
            *((float *) peek_destination) = stack->elements[stack->top].data.sval_f;
            if(Showmessages){printf("Peeked at float %f from the Stack.\n", stack->elements[stack->top].data.sval_f);}
            break;

        case STACK_DOUBLE:
            *((double *) peek_destination) = stack->elements[stack->top].data.sval_d;
            if(Showmessages){printf("Peeked at double %f from the Stack.\n", stack->elements[stack->top].data.sval_d);}
            break;

        case STACK_POINTER:
            *((void **) peek_destination) = stack->elements[stack->top].data.sval_p;
            if(Showmessages){printf("Peeked at pointer %p from the Stack.\n", stack->elements[stack->top].data.sval_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in stack_pop()\n");
            exit(EXIT_FAILURE);
    }
}


// Alternate peek implementation
/*
void stack_peek(struct stack *stack, void *peek_destination)
{
    stack_type_t push_type = stack_type_peek(stack);
    stack_pop(stack, &peek_destination);
    stack_push(stack, push_type, peek_destination);
}
*/


bool stack_is_empty(struct stack *stack)
{
    return stack->top == 0;
}
