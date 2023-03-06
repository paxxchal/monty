#include "monty.h"
/**
 * push_stack - Pushes an element to the top of the stack.
 * @stack: Double pointer to the head of the stack.
 * @n: Integer to push onto the stack.
 *
 * Return: Pointer to the newly added node.
 */
stack_t *push_stack(stack_t **stack, int n)
{
	stack_t *new_node;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = n;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;

	return (new_node);
}
/**
 * push - Pushes an element to the stack.
 * @stack: Double pointer to the head of the stack.
 * @line_number: Line number in the monty file where the opcode was found.
 */
void push(stack_t **stack, unsigned int line_number)
{
	char *n;

	n = strtok(NULL, " \n\t");

	if (n == NULL || !is_integer(n))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	push_stack(stack, atoi(n));
}

/**
 * pall - Prints all the values on the stack.
 * @stack: Pointer to the head of the stack.
 * @line_number: Line number in the monty file where the opcode was found.
 */
void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void)line_number;

	while (current != NULL)
	{
		printf("%d\n", current->n);
		current = current->next;
	}
}
