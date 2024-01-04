#include "monty.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>

/**
 * nop - The opcode nop doesn't do anything.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
