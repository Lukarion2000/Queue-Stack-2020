#include "queues.h"
#include "queue_extensions.h"

#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <stdarg.h>
#include <stdbool.h>

void queue_randomaccess(Queueptr queue, void *ra_destination, int n, mode_type_q mode)
{
	if (n > queue_element_amount(queue))
		{
			int x;
			if (n % queue_element_amount(queue) == 0) x = queue_element_amount(queue);
			else x = n % queue_element_amount(queue);
			fprintf(stderr, "Error detected: Position of Randomaccess (%d) is bigger than the amount of Elements in the queue (%d).\n", n, queue_element_amount(queue));
			fprintf(stderr, "Function instead returns value for Position %d.\n", x);
		}
	 // Skip to wished dequeue-location by reapeting a dequeue-enqueue-sequence
	for (int m = 0; m < (n-1); m++)
	{
		queue_type_t type = queue_type_peek(queue);
		 // Typeswitch
		switch (type)
		{
			case QUEUE_CHAR:
			{
				char c;
				queue_dequeue(queue, &c);
				queue_enqueue(queue, QUEUE_CHAR, c);
				break;
			}
			case QUEUE_INT:
			{
				int i;
				queue_dequeue(queue, &i);
				queue_enqueue(queue, QUEUE_INT, i);
				break;
			}
			case QUEUE_FLOAT:
			{
				float f;
				queue_dequeue(queue, &f);
				queue_enqueue(queue, QUEUE_FLOAT, f);
				break;
			}
			case QUEUE_DOUBLE:
			{
				double d;
				queue_dequeue(queue, &d);
				queue_enqueue(queue, QUEUE_DOUBLE, d);
				break;
			}
			case QUEUE_POINTER:
			{
				void *p;
				queue_dequeue(queue, &p);
				queue_enqueue(queue, QUEUE_POINTER, p);
				break;
			}
			default:
				break;
		}
	}

	 // Extract wished Entry to ra_destination
	switch (mode)
	{
		case q_dequeue:
		{
			queue_dequeue(queue, ra_destination);
			break;
		}
		case q_peek:
		{
			queue_peek(queue, ra_destination);
			break;
		}
		default:
			break;
	}
	
	 // dequeue the rest of the entries back onto the Queue, to protect the Order of items
	for (int m = 0; m < queue_element_amount(queue) - (n-1); m++)
	{
		queue_type_t type = queue_type_peek(queue);
		 // Typeswitch
		switch (type)
		{
			case QUEUE_CHAR:
			{
				char c;
				queue_dequeue(queue, &c);
				queue_enqueue(queue, QUEUE_CHAR, c);
				break;
			}
			case QUEUE_INT:
			{
				int i;
				queue_dequeue(queue, &i);
				queue_enqueue(queue, QUEUE_INT, i);
				break;
			}
			case QUEUE_FLOAT:
			{
				float f;
				queue_dequeue(queue, &f);
				queue_enqueue(queue, QUEUE_FLOAT, f);
				break;
			}
			case QUEUE_DOUBLE:
			{
				double d;
				queue_dequeue(queue, &d);
				queue_enqueue(queue, QUEUE_DOUBLE, d);
				break;
			}
			case QUEUE_POINTER:
			{
				void *p;
				queue_dequeue(queue, &p);
				queue_enqueue(queue, QUEUE_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
}

 // returns the position of the oldest object of the searched type or value
int queue_search(Queueptr queue, const queue_type_t searched_type, search_mode_q search_mode, ...)
{
	int n = -1; 
	int i, i2;
	char c, c2;
	float f, f2;
	double d, d2;
	void *p, *p2;

	bool entry_found = false;

	 //read va_arg
	va_list searched_argument;
    va_start(searched_argument, search_mode);

     // Typeswitch
    switch (searched_type)
    {
        case QUEUE_CHAR:
        {
            c = (char) va_arg(searched_argument, int);
            break;
        }
        case QUEUE_INT:
        {
            i = va_arg(searched_argument, int);
            break;
        }
        case QUEUE_FLOAT:
        {
            f = (float) va_arg(searched_argument, double);
            break;
        }
        case QUEUE_DOUBLE:
        {
            d = va_arg(searched_argument, double);
            break;
        }
        case QUEUE_POINTER:
        {
            p = va_arg(searched_argument, void *);
            break;
        }
        default:
        	break;
    }
    va_end(searched_argument);

     // Search loop
    int start_amount = queue_element_amount(queue);
	for (int m = 0; m < start_amount; m++)
	{
		queue_type_t type = queue_type_peek(queue);
		if (type == searched_type)
		{
			switch(search_mode)
			{
				case q_search_type:
				{
					n = m + 1;
					entry_found = true;
					break;
				}
				case q_search_value:
				{
				     // Typeswitch
				    switch (searched_type)
    				{
        				case QUEUE_CHAR:
        				{
        					queue_peek(queue, &c2);
            				if (c == c2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case QUEUE_INT:
        				{
        					queue_peek(queue, &i2);
            				if (i == i2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case QUEUE_FLOAT:
            			{
            				queue_peek(queue, &f2);
            				if (f == f2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
            				break;
            			}
        				case QUEUE_DOUBLE:
            			{
            				queue_peek(queue, &d2);
            				if (d == d2)
            				{
            					n = m + 1;
            					entry_found = true;
            				}
				            break;
				        }
        				case QUEUE_POINTER:
            			{
            				queue_peek(queue, &p2);
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
		// break after first Matching Entry
		if (entry_found) break;
		 // Put the item from head to tail
		 // Typeswitch
		switch (type)
		{
			case QUEUE_CHAR:
			{
				char c;
				queue_dequeue(queue, &c);
				queue_enqueue(queue, QUEUE_CHAR, c);
				break;
			}
			case QUEUE_INT:
			{
				int i;
				queue_dequeue(queue, &i);
				queue_enqueue(queue, QUEUE_INT, i);
				break;
			}
			case QUEUE_FLOAT:
			{
				float f;
				queue_dequeue(queue, &f);
				queue_enqueue(queue, QUEUE_FLOAT, f);
				break;
			}
			case QUEUE_DOUBLE:
			{
				double d;
				queue_dequeue(queue, &d);
				queue_enqueue(queue, QUEUE_DOUBLE, d);
				break;
			}
			case QUEUE_POINTER:
			{
				void *p;
				queue_dequeue(queue, &p);
				queue_enqueue(queue, QUEUE_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
	 // enqueue the skipped entries back onto the queue
	int x;
	if (n > 0) x = queue_element_amount(queue) - (n-1); // Called if a matching Entry was found -> n - 1 sequences needed to restore the queue
	else x = 0;	// Called if no matching Entry was found -> queue was looped once: items in correct order
	for (int m = 0; m < x; m++)
	{
		queue_type_t type = queue_type_peek(queue);
		 // Typeswitch
		switch (type)
		{
			case QUEUE_CHAR:
			{
				char c;
				queue_dequeue(queue, &c);
				queue_enqueue(queue, QUEUE_CHAR, c);
				break;
			}
			case QUEUE_INT:
			{
				int i;
				queue_dequeue(queue, &i);
				queue_enqueue(queue, QUEUE_INT, i);
				break;
			}
			case QUEUE_FLOAT:
			{
				float f;
				queue_dequeue(queue, &f);
				queue_enqueue(queue, QUEUE_FLOAT, f);
				break;
			}
			case QUEUE_DOUBLE:
			{
				double d;
				queue_dequeue(queue, &d);
				queue_enqueue(queue, QUEUE_DOUBLE, d);
				break;
			}
			case QUEUE_POINTER:
			{
				void *p;
				queue_dequeue(queue, &p);
				queue_enqueue(queue, QUEUE_POINTER, p);
				break;
			}
			default:
				break;
		}
	}
	return n;
}