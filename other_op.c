#include "monty.h"

/**
 * pop - removes the top of a stack(i.e the last node of a
 * doubly linked list)
 * @stack: ====
 * @line_number: ====
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%u: can't pop an empty stack\n", line_number);
		free_list(stack);
		exit(EXIT_FAILURE);
	}
	else
		del_nodebeg(stack);
}

/**
 * swap - swaps the top two elements of the stack
 * @stack: pointer to the head of the list
 * @line_number: the line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	top->prev = second;
	top->next = second->next;
	if (second->next != NULL)
		second->next->prev = top;
	second->prev = NULL;
	second->next = top;

	*stack = second;
}
