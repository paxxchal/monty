#include "monty.h"

/**
 * processMontyFile - Read and interpret a Monty bytecode file line by line.
 * @file: A pointer to the Monty bytecode file.
 * @stack: A pointer to the stack.
 */
void processMontyFile(FILE *file, stack_t **stack)
{
	char *line = NULL;
	size_t len = 256;
	unsigned int line_number = 0;
	char *token;

	line = (char *)malloc(len);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

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
					push(stack, atoi(token), line_number);
				else
				{
					fprintf(stderr, "L%u: usage: push integer\n", line_number);
					exit(EXIT_FAILURE);
				}
			}
			else if (strcmp(token, "pall") == 0)
			{
				/* Execute the pall opcode */
				pall(stack, line_number);
			}
		}
	}
	free(line);
}

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

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	processMontyFile(file, &stack);

	/* Close the file */
	fclose(file);

	/* Free the stack if not empty */
	while (stack != NULL)
	{
		stack_t *tmp = stack;

		stack = stack->next;
		free(tmp);
	}

	return (0);
}
