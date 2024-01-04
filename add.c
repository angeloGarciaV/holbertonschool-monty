#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;
	int sum;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = *stack;
	sum = tmp->n + tmp->next->n;
	tmp->next->n = sum;
	*stack = tmp->next;
	free(tmp);
}
