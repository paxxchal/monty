#include "monty.h"

/**
 * main - Entry point for the Monty interpreter.
 * @argc: Number of command-line arguments.
 * @argv: Array of command-line arguments.
 *
 * This function reads and interprets Monty byte code files.
 *
 * Return: 0 on success, EXIT_FAILURE on error.
 */
int main(int argc, char *argv[])
{
	FILE *file;
	stack_t *stack = NULL;
	char *line = NULL;
	size_t len = 256; /* You can change this value as needed */
	unsigned int line_number = 0;
	char *token;

	/* Check the number of command-line arguments */
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	/* Open the Monty byte code file */
	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	/* Allocate memory for the line variable */
	line = malloc(len);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	/* Read and interpret the Monty byte code file line by line */
	while (fgets(line, len, file) != NULL)
	{
		line_number++;

		token = strtok(line, " \n\t");
		if (token != NULL)
		{
			if (strcmp(token, "push") == 0)
			{
				/* Execute the push opcode */
				token = strtok(NULL, " \n\t");
				if (token != NULL)
					push(&stack, atoi(token), line_number);
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(token, "pall") == 0)
			{
				/* Execute the pall opcode */
				pall(&stack, line_number);
			}
			/*Add more opcode cases as needed for other instructions*/
		}
	}

	/* Free resources and close the file */
	free(line);
	fclose(file);

	/* Free the stack if not empty */
	while (stack != NULL)
	{
		stack_t *tmp = stack;
		stack = stack->next;
		free(tmp);
	}

	return 0;
}
