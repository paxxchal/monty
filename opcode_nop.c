#include "monty.h"

/**
 * nop - Does nothing.
 * @stack: A pointer to the stack.
 * @line_number: The current line number in the Monty file.
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;	   /*Suppress unused parameter warning*/
	(void)line_number; /*Suppress unused parameter warning*/
			   /* This opcode does nothing */
}
