#include "monty.h"

/**
 * rotl - rotates the stack to the top
 * @stack: pointer to the head of the list
 * @line_number: the line number (unused)
 */

void rotl(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	(void)line_number;

	if (*stack == NULL || (*stack)->next == NULL)
		return;
	temp = *stack;

	while (temp->next != NULL)
		temp = temp->next;
	(*stack)->prev = temp;
	temp->next = *stack;
	(*stack)->next->prev = NULL;
	(*stack) = (*stack)->next;
	temp->next->next = NULL;
}

/**
 * rotr - rotates the stack to the bottom
 * @stack: ====
 * @line_number: ===
 */

void rotr(stack_t **stack, unsigned int line_number)
{
	stack_t *last = *stack;

	(void)line_number;
	if (*stack == NULL || (*stack)->next == NULL)
		return;

	while (last->next != NULL)
		last = last->next;
	last->next = *stack;
	(*stack)->prev = last;
	last->prev->next = NULL;
	last->prev = NULL;
	*stack = (*stack)->prev;
}
