#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: double pointer to the head of the stack
 * @line_number: line number of the command in the Monty bytecode file
 */
void swap(stack_t **stack, unsigned int line_number)
{
    /* Check if stack exists and has at least two elements */
    if (!stack || !(*stack) || !((*stack)->next))
    {
        fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
        exit(EXIT_FAILURE);
    }

    /* Store the top and second nodes in temporary variables */
    stack_t *top = *stack;
    stack_t *next = top->next;

    /* Adjust the pointers to swap the top two nodes */
    top->prev = next;
    top->next = next->next;
    next->prev = NULL;
    next->next = top;

    /* If there is a third node, adjust its prev pointer */
    if (top->next)
        top->next->prev = top;

    /* Set the head of the stack to the second node */
    *stack = next;
}

