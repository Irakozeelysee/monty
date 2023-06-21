#include "monty.h"

/**
 * get_func - opcode selector
 * @token: the opcode
 * Return: pointer to the opcode function
 */

void (*get_func(char *token))(stack_t **stack, unsigned int line_number)
{
	instruction_t instructions[] = {
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
		{"pchar", pchar},
		{"pstr", pstr},
		{"rotl", rotl},
		{"rotr", rotr},
		{NULL, NULL}
	};
	int i = 0;

	while (instructions[i].f != NULL)
	{
		if (strcmp(token, instructions[i].opcode) == 0)
			return (instructions[i].f);
		i++;
	}
	return (NULL);
}
