#include "monty.h"

/**
 * push - adds a node to the top of the stack
 * @stack: pointer to the head of the list
 * @line_number: the line_number
 * @arg: the integer
 */
void push(stack_t **stack, unsigned int line_number, char *arg)
{
	int num, i;

	if (arg == NULL)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}

	for (i = 0; arg[i] != '\0'; i++)
	{
		if (i == 0 && (arg[i] == '+' || arg[i] == '-'))
			continue;

		if (!isdigit(arg[i]))
		{
			fprintf(stderr, "L%u: usage: push integer\n", line_number);
			free_list(stack);
			exit(EXIT_FAILURE);
		}
	}

	num = atoi(arg);

	if (add_nodebeg(stack, num) == -1)
	{
		free_list(stack);
		exit(EXIT_FAILURE);
	}
}

/**
 * pall - prints all the values in a node
 * @stack: the pointer to the head of the node
 * @line_number: the line_number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	if (*stack == NULL)
		return;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
