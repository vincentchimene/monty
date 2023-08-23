#include "monty.h"

/**
 * pall - Prints the values on the stack
 * @stack: Pointer to the top of the stack (Head Stack)
 * @line_number: Line number
 * Return: no return
 */
void pall(stack_t **stack, unsigned int line_number)
{
    (void)line_number;

    stack_t *now = *stack;

    while (now != NULL)
    {
        printf("%d\n", now->n);
        now = now->next;
    }
}
