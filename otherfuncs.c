#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the list
 * @line_number: the line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->next;
	if (temp->next != NULL)
	{
		(*stack)->next = temp->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		temp->prev->prev = temp;
		temp->prev->next = NULL;
	}
	temp->prev = NULL;
	temp->next = *stack;
	*stack = temp;
}

/**
 * add - adds the two top elements of the stack
 * @stack: pointer to the head of the list
 * @line_number: the line_number
 * Description: the fucntion adds the top two elements of the stack
 * if the stack contains less than two elemnts it prints an error
 * the two elements are added as seen below and the result is stored
 * in the second top element((*stack)->next->n)
 * the top element is removed using 'pop'
 */

void add(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't add, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n += (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * nop - the nop function does nothing
 * @stack: unused
 * @line_number: unused
 */

void nop(stack_t **stack, unsigned int line_number)
{
	(void)stack;
	(void)line_number;
}
