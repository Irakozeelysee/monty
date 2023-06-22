#define _GNU_SOURCE
#include "monty.h"

void cleanup(stack_t **stack, char *line, FILE *file);
void errormessage(unsigned int line_number, char *token);

/**
 * process - process the code to be passed to the main function
 * @filename: the name of the file to be opened
 */

void process(const char *filename)
{
	char *line = NULL, *token;
	unsigned int line_number = 1, check_push = 0;
	ssize_t num_read;
	size_t len = 0;
	stack_t *stack = NULL;
	FILE *file;

	file = fopen(filename, "r");
	if (file == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", filename);
		exit(EXIT_FAILURE);
	}
	while ((num_read = getline(&line, &len, file)) != -1)
	{
		token = strtok(line, " \t\a\n\r;:");
		while (token != NULL)
		{
			if (token[0] == '#')
				continue;
			if (check_push == 1)
			{
				push(&stack, line_number, token);
				check_push = 0;
				token = strtok(NULL, " \t\a\n\r;:");
				line_number++;
				continue;
			}
			else if (strcmp(token, "push") == 0)
			{
				check_push = 1;
				token = strtok(NULL, " \t\n\a\r;:");
				continue;
			}
			else
			{
				if (get_opcodes(token) != 0)
					get_opcodes(token)(&stack, line_number);
				else
				{
					free_list(&stack);
					errormessage(line_number, token);
				}
			}
			line_number++;
			token = strtok(NULL, " \t\r\a\n:;");
		}
	}
	cleanup(&stack, line, file);
}

/**
 * cleanup - cleans up the process
 * @stack: ====
 * @line: =====
 * @file: =====
 */

void cleanup(stack_t **stack, char *line, FILE *file)
{
	free_list(stack);
	free(line);
	fclose(file);
}

/**
 * errormessage - prints error message
 * @line_number: ====
 * @token: ====
 */

void errormessage(unsigned int line_number, char *token)
{
	fprintf(stderr, "L%u: unknown instruction %s\n", line_number, token);
	exit(EXIT_FAILURE);
}
