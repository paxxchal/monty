#include "monty.h"

/**
 * pall - Prints all values on the stack, starting from the top.
 * @stack: A pointer to the stack (doubly linked list).
 * @line_number: The current line number in the Monty bytecode file.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number; /*Avoid "unused parameter" warning*/

	while (current)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
