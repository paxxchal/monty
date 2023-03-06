#include "monty.h"

/**
 * pall - prints all the values on the stack,
 * starting from the top of the stack
 * @stack: double pointer to the beginning of the stack
 * @line_number: line number being executed from script file
 *
 * Return: void
 */
void pall(stack_t **stack, unsigned int line_number)
{
        stack_t *temp;

        (void)line_number;
        for (temp = *stack; temp; temp = temp->next)
                printf("%d\n", temp->n);
}