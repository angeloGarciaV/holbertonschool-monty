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

/**
 * pall - Prints all the values on the stack, starting
 * from the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	(void)line_number;
	tmp = *stack;
	while (tmp)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - The opcode pint prints the value at the top of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !(*stack))
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*stack)->n);
}

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

/**
 * swap - Swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (!stack || !(*stack) || !(*stack)->next)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	(*stack)->next = tmp->next;
	(*stack)->prev = tmp;
	tmp->next = *stack;
	tmp->prev = NULL;
	*stack = tmp;
}
