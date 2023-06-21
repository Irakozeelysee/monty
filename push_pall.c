#include "monty.h"

/**
 * push - adds a node at the start of a list
 * @stack: head of the list
 * @line_number: line nummber
 * @arg: the integer
 */

void push(stack_t **stack, unsigned int line_number, char *arg)
{
	if (is_integer(arg) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_nodebeg(stack, atoi(arg)) == -1)
		{
			free_list(stack);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 * pall - prints all the nodes in a stack
 * @stack: ====
 * @line_number: ====
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *temp = *stack;

	(void)line_number;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
