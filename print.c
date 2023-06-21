#include "monty.h"

/**
 * pchar - prints the char at the top of the stack
 * @stack: ====
 * @line_number: the line_number
 * Description: prints th char at the top of the stack
 * if the value is not in the ASCII table it prints an error
 * if the stack is empty it prints an error
 */

void pchar(stack_t **stack, unsigned int line_number)
{
	int value;
	char character;

	if (*stack == NULL)
	{
		printf("L%u: can't pchar, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	value = (*stack)->n;

	if (value < 0 || value > 127)
	{
		printf("L%u: can't pchar, value out of range\n", line_number);
		exit(EXIT_FAILURE);
	}

	character = (char)value;
	printf("%c\n", character);
}

void pstr(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL)
	{
		printf("L%u: can't pstr, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = *stack;
	while ((temp != NULL) && (temp->n != 0) &&
	       (temp->n >= 0) && (temp->n <= 127))
	{
		printf("%c", temp->n);
		temp = temp->next;
	}
	printf("\n");
}
