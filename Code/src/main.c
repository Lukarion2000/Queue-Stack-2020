#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "queuestack.h"
#include <math.h>
#include <time.h>

int main (void)
{
	int_Stack My_iStack = init_int_Stack();
	srand(time(0));
	for (int i = 0; i < 100; ++i)
	{
		int r = rand();
		push_int_Stack(&My_iStack, r);
	}
	show_int_Stack(My_iStack);
	int i = 40;
	push_int_Stack(&My_iStack, i);
	return 0;
}
