#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <string.h>
#include <errno.h>

/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
*/
void push(stack_t **stack, unsigned int line_number)
{
	stack_t *new;
	char *arg;
	int i = 0;

	arg = strtok(NULL, " \n\t\r");
	if (!arg)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	while (arg[i])
	{
		if (arg[0] == '-' && i == 0)
		{
			i++;
			continue;
		}
		if (arg[i] < '0' || arg[i] > '9')
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			exit(EXIT_FAILURE);
		}
		i++;
	}
	new = malloc(sizeof(stack_t));
	if (!new)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new->n = atoi(arg);
	new->prev = NULL;
	new->next = *stack;
	if (*stack)
		(*stack)->prev = new;
	*stack = new;
}
