#include "monty.h"

/**
 * swap - The opcode swap swaps the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    int temp;

    if (!stack || !(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    temp = (*stack)->n;
    (*stack)->n = (*stack)->next->n;
    (*stack)->next->n = temp;
}

