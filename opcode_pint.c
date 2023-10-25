#include "monty.h"

/**
 * pint - Print the value at the top of the stack and remove it.
 * @stack: A pointer to the stack.
 * @line_number: The current line number being executed.
 */
void pint(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	printf("%d\n", tmp->n);

	/* Remove the top element from the stack */
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(tmp);
}
