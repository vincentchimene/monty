#include "monty.h"

/**
 * push - Pushes an element to the stack
 * @stack: Pointer to the top of the stack (Head Stack)
 * @line_number: Line number
 * Return: no return
 */
void push(stack_t **stack, unsigned int line_number)
{
    char *argument = strtok(NULL, " \t\n");
    if (argument == NULL)
    {
        fprintf(stderr, "L%d: usage: push integer\n", line_number);
        exit(EXIT_FAILURE);
    }

    int value = atoi(argument);

    stack_t *new_node = malloc(sizeof(stack_t));
    if (new_node == NULL)
    {
        fprintf(stderr, "Error: malloc failed\n");
        exit(EXIT_FAILURE);
    }

    new_node->n = value;
    new_node->prev = NULL;
    new_node->next = *stack;

    if (*stack != NULL)
        (*stack)->prev = new_node;
    *stack = new_node;
}
