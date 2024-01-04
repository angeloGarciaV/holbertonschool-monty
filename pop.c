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

<<<<<<< HEAD
    if (*stack)
        (*stack)->prev = NULL;

    free(temp);
}
=======
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	*stack = (*stack)->next;
	free(tmp);
}
>>>>>>> e2eb007b278751c7da8d4e015a36dfc2a6fd362a
