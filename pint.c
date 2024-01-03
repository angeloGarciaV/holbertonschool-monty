#include "monty.h"

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

