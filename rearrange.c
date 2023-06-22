#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: ====
 * @line_number: ====
 */
void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *last, *second_last;

	(void) line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;
		second_last = last->next;

		while (last->next != NULL)
			last = last->next;
		last->next = *stack;
		(*stack)->prev = last;
		*stack = second_last;
		second_last->prev = NULL;
		last->next->next = NULL;
	}
}

/**
 * rotr - rotates stack to the bottom
 * @stack: ===
 * @line_number: ====
 */

void  rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last;

	(void) line_number;
	if (*stack != NULL && (*stack)->next != NULL)
	{
		last = *stack;

		while (last->next != NULL)
			last = last->next;

		last->next = *stack;
		(*stack)->prev = last;
		*stack = last;
		last = last->prev;
		last->next = NULL;
		(*stack)->prev = NULL;
	}
}
