#include "monty.h"

/**
 * process_file - Process the Monty bytecode file
 * @file: Pointer to the file
 * Return: EXIT_SUCCESS or EXIT_FAILURE
 */
int process_file(FILE *file)
{
	char opcode[100];
	char arg[100];
	unsigned int line_number = 0;

	stack_t *stack = NULL;

	while (fscanf(file, "%99s", opcode) == 1)
	{
		line_number++;
		if (strcmp(opcode, "push") == 0)
		{
			if (fscanf(file, "%99s", arg) != 1)
			{
				fprintf(stderr, "L%u: usage: push integer\n", line_number);
				fclose(file);
				free(stack);
				return (EXIT_FAILURE);
			}
			push(&stack, arg, line_number);
		}
		else if (strcmp(opcode, "pall") == 0)
		{
			pall(&stack);
		}
		else
		{
			fprintf(stderr, "L%u: unknown instruction %s\n", line_number, opcode);
			fclose(file);
			free(stack);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
