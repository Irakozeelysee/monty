#include "monty.h"

/**
 * pop - removes the top of a stack(i.e the last node of a
 * doubly linked list)
 * @stack: ====
 * @line_number: ====
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	else
		del_nodebeg(stack);
}
