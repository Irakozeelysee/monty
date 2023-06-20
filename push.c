#include <stdlib.h>
#include "monty.h"

/**
 * push - pushes an element onto the stack
 * @stack: double pointer to the stack
 * @arg: argument provided to the push opcode
 * @line_number: line number of the instruction
 */

void push(stack_t **stack, char *arg, unsigned int line_number)
{
	int value;
	stack_t *new_node = malloc(sizeof(stack_t));

	if (arg == NULL || !is_integer(arg))
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = atoi(arg);
	if (new_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->n = value;
	new_node->prev = NULL;
	if (*stack == NULL)
	{
		new_node->next = NULL;
		*stack = new_node;
	}
	else
	{
		new_node->next = *stack;
		(*stack)->prev = new_node;
	}
	*stack = new_node;
}

/**
 * is_integer - checks if a string represents a valid integer
 * @str: string to check
 * Return: 1 if str is a valid integer, 0 otherwise
 */

int is_integer(char *str)
{
	int i = 0;

	if (str == NULL || *str == '\0')
		return (0);
	if (str[i] == '-' || str[i] == '+')
		i++;
	for (; str[i] != '\0'; i++)
	{
		if (str[i] < '0' || str[i] > '9')
			return (0);
	}
	return (1);
}
