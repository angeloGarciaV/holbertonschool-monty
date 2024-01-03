#include "monty.h"

/**
 * add - The opcode add adds the top two elements of the stack.
 * @stack: Double pointer to the beginning of the stack
 * @line_number: Line number in the Monty byte code file
 */
void add(stack_t **stack, unsigned int line_number)
{
    if (!stack || !(*stack) || !(*stack)->next)
    {
        fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    (*stack)->next->n += (*stack)->n;  /* Add the top two elements */
    pop(stack, line_number);           /* Remove the top element */
}

