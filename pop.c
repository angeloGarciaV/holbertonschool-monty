#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

/**
 * pop - Removes the top element of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
