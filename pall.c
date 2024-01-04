#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

/**
 * pall - Prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	(void)line_number;
	while (*stack)
	{
		printf("%d\n", (*stack)->n);
		stack = &(*stack)->next;
	}
}
