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

/**
 * pchar - prints the char at the top of the stack, followed by a new line
 * @stack: pointer to the head of the list
 * @line_number: bytecode line_number
 */
void pchar(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}

	if ((*stack)->n < 0 || (*stack)->n > 127)
	{
		fprintf(stderr, "L%u: can't pchar, value out of range\n",
				line_number);
		exit(EXIT_FAILURE);
	}

	putchar((*stack)->n);
	putchar('\n');
}

/**
 * pstr - prints the top node of the stack(as ascii letters)
 * @stack: pointer to the head of the list
 * @line_number: line number
 */

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *current = *stack;

	(void) line_number;
	if (*stack == NULL)
		return;

	while ((current != NULL) && (current->n != 0) &&
	      (current->n >= 0) && (current->n <= 127))
	{
		putchar(current->n);
		current = current->next;
	}
	putchar('\n');
}
