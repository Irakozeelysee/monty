#include "monty.h"

/**
 * add - adds the two top elements of the stack
 * @stack: pointer to the first node
 * @line_number: the line number
 * Description: the function adds the two top elements of the stack
 * the result is stored in the second top element
 * the top element is removed and the second top becomes the top
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n += top->n;

	*stack = second;
	free(top);
	(*stack)->prev = NULL;
}
