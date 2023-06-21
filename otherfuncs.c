#include "monty.h"

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the list
 * @line_number: the line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	int temp;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	temp = (*stack)->n;
	(*stack)->n = (*stack)->next->n;
	(*stack)->next->n = temp;
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
	pop(stack, line_number);
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
