#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/**
 * push - ASDF
 * @stack: ASDF
 * @line_number: woienfowejnf
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;

	if (!new)
	{
		dprintf(STDERR_FILENO, "Error: memory allocation failed\n");
		free(new);
		exit(EXIT_FAILURE);
	}
	new = malloc(sizeof(stack_t));
	new->n = line_number;
	new->next = *stack;
	new->prev = NULL;
	*stack = new;
}
