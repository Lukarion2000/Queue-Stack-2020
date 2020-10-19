#include "stacks.h"
#include "stack_extensions.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

 // Get Access to the n-th Entry from the top (n == 1 -> stack_randomaccess = stack_pop) 
 // NOTE: uses push and pop instead of direct access to the stack array
void stack_randomaccess(Stackptr stack, void *ra_destination, int n, mode_type_s mode)
{
	Stackptr help_stack = stack_create(stack_capacity(stack));
	 // Skip to wished pop-location by pushing onto a helpstack
	for (int m = 0; m < (n-1); m++)
	{
		stack_type_t type = stack_type_peek(stack);
		 // Typeswitch
		switch (type)
		{
			case STACK_CHAR:
			{
				char c;
				stack_pop(stack, &c);
				stack_push(help_stack, STACK_CHAR, c);
				break;
			}
			case STACK_INT:
			{
				int i;
				stack_pop(stack, &i);
				stack_push(help_stack, STACK_INT, i);
				break;
			}
			case STACK_FLOAT:
			{
				float f;
				stack_pop(stack, &f);
				stack_push(help_stack, STACK_FLOAT, f);
				break;
			}
			case STACK_DOUBLE:
			{
				double d;
				stack_pop(stack, &d);
				stack_push(help_stack, STACK_DOUBLE, d);
				break;
			}
			case STACK_POINTER:
			{
				void *p;
				stack_pop(stack, &p);
				stack_push(help_stack, STACK_POINTER, p);
				break;
			}
			default:
				break;
		}
	}

	 // Extract wished Entry to ra_destination
	switch (mode)
	{
		case s_pop:
		{
			stack_pop(stack, ra_destination);
			break;
		}
		case s_peek:
		{
			stack_peek(stack, ra_destination);
			break;
		}
		default:
			break;
	}
	
	 // push the skipped entries back onto the Stack
	for (int m = 0; m < n-1; m++)
	{
		stack_type_t type = stack_type_peek(help_stack);
		 // Typeswitch
		switch (type)
		{
			case STACK_CHAR:
			{
				char c;
				stack_pop(help_stack, &c);
				stack_push(stack, STACK_CHAR, c);
				break;
			}
			case STACK_INT:
			{
				int i;
				stack_pop(help_stack, &i);
				stack_push(stack, STACK_INT, i);
				break;
			}
			case STACK_FLOAT:
			{
				float f;
				stack_pop(help_stack, &f);
				stack_push(stack, STACK_FLOAT, f);
				break;
			}
			case STACK_DOUBLE:
			{
				double d;
				stack_pop(help_stack, &d);
				stack_push(stack, STACK_DOUBLE, d);
				break;
			}
			case STACK_POINTER:
			{
				void *p;
				stack_pop(help_stack, &p);
				stack_push(stack, STACK_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
	 // destroy the help stack
	stack_destroy(help_stack);
}

int stack_search(Stackptr stack, const stack_type_t searched_type, search_mode_s search_mode, ...)
{
	Stackptr help_stack = stack_create(stack_capacity(stack));

	int n = -1; 
	int i, i2;
	char c, c2;
	float f, f2;
	double d, d2;
	void *p, *p2;

	bool entry_found = false;

	va_list searched_argument;
    va_start(searched_argument, search_mode);

     // Typeswitch
    switch (searched_type)
    {
        case STACK_CHAR:
        {
            c = (char) va_arg(searched_argument, int);
            break;
        }
        case STACK_INT:
        {
            i = va_arg(searched_argument, int);
            break;
        }
        case STACK_FLOAT:
        {
            f = (float) va_arg(searched_argument, double);
            break;
        }
        case STACK_DOUBLE:
        {
            d = va_arg(searched_argument, double);
            break;
        }
        case STACK_POINTER:
        {
            p = va_arg(searched_argument, void *);
            break;
        }
        default:
        	break;
    }
    va_end(searched_argument);

    int start_amount = stack_element_amount(stack);
	for (int m = 0; m < start_amount; m++)
	{
		stack_type_t type = stack_type_peek(stack);
		if (type == searched_type)
		{
			switch(search_mode)
			{
				case s_search_type:
				{
					n = m + 1;
					entry_found = true;
					break;
				}
				case s_search_value:
				{
				     // Typeswitch
				    switch (searched_type)
    				{
        				case STACK_CHAR:
        				{
        					stack_peek(stack, &c2);
            				if (c == c2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case STACK_INT:
        				{
        					stack_peek(stack, &i2);
            				if (i == i2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case STACK_FLOAT:
            			{
            				stack_peek(stack, &f2);
            				if (f == f2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case STACK_DOUBLE:
            			{
            				stack_peek(stack, &d2);
            				if (d == d2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
				            break;
				        }
        				case STACK_POINTER:
            			{
            				stack_peek(stack, &p2);
            				if (p == p2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				default:
				        	break;
    				}
					break;
				}
			}
		}
		if (entry_found) break;
		switch (type)
		{
			case STACK_CHAR:
			{
				char c;
				stack_pop(stack, &c);
				stack_push(help_stack, STACK_CHAR, c);
				break;
			}
			case STACK_INT:
			{
				int i;
				stack_pop(stack, &i);
				stack_push(help_stack, STACK_INT, i);
				break;
			}
			case STACK_FLOAT:
			{
				float f;
				stack_pop(stack, &f);
				stack_push(help_stack, STACK_FLOAT, f);
				break;
			}
			case STACK_DOUBLE:
			{
				double d;
				stack_pop(stack, &d);
				stack_push(help_stack, STACK_DOUBLE, d);
				break;
			}
			case STACK_POINTER:
			{
				void *p;
				stack_pop(stack, &p);
				stack_push(help_stack, STACK_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
	 // push the skipped entries back onto the Stack
	int x;
	if (n > 0) x = n-1; // Called if a matching Entry was found -> n -1 on help_stack
	else x = stack_element_amount(help_stack);	// Called if no matching Entry was found -> all Entries on help_stack

	for (int m = 0; m < x; m++)
	{
		stack_type_t type = stack_type_peek(help_stack);
		 // Typeswitch
		switch (type)
		{
			case STACK_CHAR:
			{
				char c;
				stack_pop(help_stack, &c);
				stack_push(stack, STACK_CHAR, c);
				break;
			}
			case STACK_INT:
			{
				int i;
				stack_pop(help_stack, &i);
				stack_push(stack, STACK_INT, i);
				break;
			}
			case STACK_FLOAT:
			{
				float f;
				stack_pop(help_stack, &f);
				stack_push(stack, STACK_FLOAT, f);
				break;
			}
			case STACK_DOUBLE:
			{
				double d;
				stack_pop(help_stack, &d);
				stack_push(stack, STACK_DOUBLE, d);
				break;
			}
			case STACK_POINTER:
			{
				void *p;
				stack_pop(help_stack, &p);
				stack_push(stack, STACK_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
	 // destroy the help stack
	stack_destroy(help_stack);
	return n;
}
