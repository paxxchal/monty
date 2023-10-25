#include "monty.h"

/**
 * push - Pushes an element onto the stack.
 * @stack: A pointer to the stack (doubly linked list).
 * @value: The integer value to be pushed.
 * @line_number: The current line number in the Monty bytecode file.
 *
 * If <int> is not an integer or if there is no argument given to push,
 * prints an error message and exits with EXIT_FAILURE.
 */
void push(stack_t **stack, int value, unsigned int line_number)
{
	stack_t *new_node;

	if (!stack)
	{
		fprintf(stderr, "L%u: stack is not initialized\n", line_number);
		exit(EXIT_FAILURE);
	}

	new_node = malloc(sizeof(stack_t));
	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	new_node->n = value;
	new_node->prev = NULL;
	new_node->next = *stack;

	if (*stack)
		(*stack)->prev = new_node;

	*stack = new_node;
}
