#include "monty.h"

/**
 * sub - Subtracts the top element from the second top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	second->n -= first->n; /*Subtract the top element from the second top element*/
	*stack = second;       /*Remove the top element*/
	second->prev = NULL;
	free(first);
}
