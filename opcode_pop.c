#include "monty.h"

/**
 * pop - Remove the top element of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}

	temp = *stack;

	if (temp->next != NULL)
	{
		*stack = temp->next;
		temp->next->prev = NULL;
	}
	else
	{
		*stack = NULL;
	}

	free(temp);
}
