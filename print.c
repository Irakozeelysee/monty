#include "monty.h"

/**
 * pint - print the value at the top of the stack
 * @stack: pointer to the head of the list
 * @line_number: bytcode line number
 */
void pint(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
