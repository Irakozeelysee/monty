#include "monty.h"

/**
 * pint - prints the top node
 * @stack: pointer to the head of the list
 * @line_number: line_number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
