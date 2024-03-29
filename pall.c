#include "monty.h"

/**
 * pall - The opcode pall prints all the values on the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	if (!stack)
	{
		exit(EXIT_FAILURE);
	}

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}

