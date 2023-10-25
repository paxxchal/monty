#include "monty.h"

/**
 * readLine - Read a line from the Monty bytecode file.
 * @file: A pointer to the Monty bytecode file.
 * @line: A buffer to store the read line.
 * @len: The length of the buffer.
 *
 * Return: 1 if a line was read, 0 if EOF is reached, -1 on error.
 */
int readLine(FILE *file, char *line, size_t len)
{
	if (fgets(line, len, file) != NULL)
	{
		return (1);
	}
	if (feof(file))
	{
		return (0);
	}
	return (-1);
}

/**
 * parseToken - Parse a token from the line.
 * @line: The line to parse.
 * @delim: The delimiter to use.
 *
 * Return: The token, or NULL if none.
 */
char *parseToken(char *line, char *delim)
{
	char *token;

	token = strtok(line, delim);
	return (token);
}

/**
 * executeOpcode - Execute an opcode from the token.
 * @token: The token to execute.
 * @stack: A pointer to the stack.
 * @line_number: The line number of the token.
 */
void executeOpcode(char *token, stack_t **stack, unsigned int line_number)
{
	if (strcmp(token, "push") == 0)
	{
		/* Execute the push opcode */
		token = parseToken(NULL, " \n\t");
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
	else if (strcmp(token, "pint") == 0)
	{
		/* Execute the pint opcode */
		pint(stack, line_number);
	}
	else if (strcmp(token, "pop") == 0)
	{
		/* Execute the pop opcode */
		pop(stack, line_number);
	}
	else if (strcmp(token, "swap") == 0)
	{
		/* Execute the swap opcode */
		swap(stack, line_number);
	}
	else if (strcmp(token, "add") == 0)
	{
		/* Execute the add opcode */
		add(stack, line_number);
	}
}

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
	int result;

	line = (char *)malloc(len);
	if (line == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}

	while ((result = readLine(file, line, len)) != 0)
	{
		if (result == 1)
		{
			line_number++;

			token = parseToken(line, " \n\t");
			if (token != NULL)
				executeOpcode(token, stack, line_number);
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
	stack_t *stack;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		return (EXIT_FAILURE);
	}

	file = fopen(argv[1], "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		return (EXIT_FAILURE);
	}

	stack = NULL;
	processMontyFile(file, &stack);

	fclose(file);

	while (stack != NULL)
	{
		stack_t *tmp = stack;

		stack = stack->next;
		free(tmp);
	}

	return (0);
}
