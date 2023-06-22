#include "monty.h"

/**
 * get_opcodes - gets the opcode from the file
 * @token: the opcode
 * Return: the pointer to the opcode function
 */

void (*get_opcodes(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t opcodes[] = {
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{"sub", sub},
		{"div", m_div},
		{"mul", m_mul},
		{"mod", m_mod},
		{NULL, NULL}
	};
	int i = 0;

	while (opcodes[i].f != NULL)
	{
		if (strcmp(token, opcodes[i].opcode) == 0)
			return (opcodes[i].f);
		i++;
	}
	return (NULL);
}
