#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void add(stack_t **stack, unsigned int line_number)
{
	stack_t *first;
	stack_t *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	first = *stack;
	second = first->next;

	first->next->n += first->n; /*Add the top two elements*/
	*stack = second;	    /*Remove the top element*/
	second->prev = NULL;
	free(first);
}
