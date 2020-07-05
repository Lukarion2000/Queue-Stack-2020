#include "queuestack.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <stdarg.h>
#include <stdbool.h>

//false: print only error messages
//true: print all messages
#define Showmessages false

//########_Stacks_########

//  Struct to contain a Multitype Stack element
struct multi_stack_element {
    stack_type_t type;
    union {
        char val_c;
        int val_i;
        float val_f;
        double val_d;
        void * val_p;
    } data;
};

//TODO: Monotype Stacks; probably entirely new struct but i'll see

//TODO Descriptions
struct stack {
    int top;
    int capacity;
    struct multi_stack_element *elements;
};

// Creates and returns a new Multitype Stack
struct stack *stack_create_multi(const int capacity)
{
    struct stack *new_stack = malloc(sizeof *new_stack);
    if ( !new_stack )
    {
        fprintf(stderr, "Failed to allocate memory for new Stack.");
        exit(EXIT_FAILURE);
    }

    new_stack->capacity = capacity;
    new_stack->top = 0;

    new_stack->elements = malloc(sizeof *new_stack->elements * capacity);
    if ( !new_stack->elements )
    {
        free(new_stack);
        fprintf(stderr, "Failed to allocate memory for Stack elements.");
        exit(EXIT_FAILURE);
    }

    return new_stack;
}



void stack_multi_destroy(struct stack *stack)
{
    free(stack->elements);
    free(stack);
}

void stack_multi_push(struct stack *stack, const stack_type_t push_type, ...)
{
    if ( stack->top == stack->capacity )
    {
        fprintf(stderr, "Stackoverflow!\n");
        exit(EXIT_FAILURE);
    }

    va_list push_argument;
    va_start(push_argument, push_type);

    switch (push_type)
    {
        case STACK_CHAR:
            stack->elements[stack->top].data.val_c = (char) va_arg(push_argument, int);
            if(Showmessages){printf("Pushed char %c on the Stack", stack->elements[stack->top].data.val_c);}
            break;

        case STACK_INT:
            stack->elements[stack->top].data.val_i = va_arg(push_argument, int);
            if(Showmessages){printf("Pushed int %i on the Stack", stack->elements[stack->top].data.val_i);}
            break;

        case STACK_FLOAT:
            stack->elements[stack->top].data.val_f = (float) va_arg(push_argument, double);
            if(Showmessages){printf("Pushed float %f on the Stack", stack->elements[stack->top].data.val_f);}
            break;

        case STACK_DOUBLE:
            stack->elements[stack->top].data.val_d = va_arg(push_argument, double);
            if(Showmessages){printf("Pushed double %f on the Stack", stack->elements[stack->top].data.val_d);}
            break;

        case STACK_POINTER:
            stack->elements[stack->top].data.val_p = va_arg(push_argument, void *);
            if(Showmessages){printf("Pushed pointer %p on the Stack", stack->elements[stack->top].data.val_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in stack_push()\n");
            exit(EXIT_FAILURE);
    }
    
    stack->elements[stack->top++].type = push_type;

    va_end(push_argument);
}

void stack_pop(struct stack *stack, void * pop_destination)
{
    if ( stack->top == 0 )
    {
        fprintf(stderr, "Stackunderflow!\n");
        exit(EXIT_FAILURE);
    }

    switch ( stack->elements[--stack->top].type )
    {
        case STACK_CHAR:
            *((char *) pop_destination) = stack->elements[stack->top].data.val_c;
            if(Showmessages){printf("Popped pointer %c from the Stack", stack->elements[stack->top].data.val_c);}
            break;

        case STACK_INT:
            *((int *) pop_destination) = stack->elements[stack->top].data.val_i;
            if(Showmessages){printf("Popped int %d from the Stack", stack->elements[stack->top].data.val_i);}
            break;

        case STACK_FLOAT:
            *((float *) pop_destination) = stack->elements[stack->top].data.val_f;
            if(Showmessages){printf("Popped float %f from the Stack", stack->elements[stack->top].data.val_f);}
            break;

        case STACK_DOUBLE:
            *((double *) pop_destination) = stack->elements[stack->top].data.val_d;
            if(Showmessages){printf("Popped pointer %f from the Stack", stack->elements[stack->top].data.val_d);}
            break;

        case STACK_POINTER:
            *((void **) pop_destination) = stack->elements[stack->top].data.val_p;
            if(Showmessages){printf("Popped pointer %p from the Stack", stack->elements[stack->top].data.val_p);}
            break;

        default:
            fprintf(stderr, "Unknown type in stack_pop()\n");
            exit(EXIT_FAILURE);
    }
}

//void stack_multi_peek(Stack stack, void * p);

stack_type_t stack_type_peek(struct stack *stack)
{
    if ( stack->top == 0 )
    {
        fprintf(stderr, "Stackunderflow!\n");
        exit(EXIT_FAILURE);
    }

    return stack->elements[stack->top - 1].type;
}

bool stack_is_empty(struct stack *stack)
{
    return stack->top == 0;
}

//##_Simple int_Stacks_## 

int_Stack init_int_Stack()
{
	int_Stack Stack_new;
	Stack_new.top = -1;
	return Stack_new;
}

void push_int_Stack(int_Stack *iStack, int value)
{
	if(iStack->top + 1 == int_Stack_count_max)
	{
		//error Stackoverflow
		printf("STACKOVERFLOOOOOOOOW!\n");
		exit(0);
	}
	else
	{
		iStack->top++;
		printf("Pushing %d\n", iStack->items[iStack->top]);
		iStack->items[iStack->top] = value;
	}
}

int pop_int_Stack(int_Stack *iStack)
{
	if(iStack->top == -1)
	{
		//error Stackunderflow
		printf("STACKUNDERFLOOOOOOOOW!\n");
		exit(0);
	}
	else
	{
		printf("Popping %d\n", iStack->items[iStack->top]);
		int value = iStack->items[iStack->top];
		iStack->top--;
		return value;
	}
	
}

<<<<<<< HEAD
void peek_int_Stack(int_Stack iStack)
=======
void peek_int_Stackt_Stack iStack) //needs to return a value(is shortened version of pop + push)
>>>>>>> c7f8caf7b2071f06f5dd436d9d7c315b37bc1236
{
	printf("Showing top item of stack.\n");
	printf("%d\n", iStack.items[iStack.top]);
}

void show_int_Stack(int_Stack iStack)
{
	printf("Showing all items.\n");
	for (int i = 0; i < iStack.top + 1; ++i)
		{
			printf("[%d]\n", iStack.items[i]);
		}
}










