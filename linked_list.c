#include "monty.h"

/**
 * add_nodebeg -  adds a node to the beginning of a doubly linked list
 * @stack: pointer to the head of the list
 * @n: integer value to be added
 * Return: nothing.
 */

int add_nodebeg(stack_t **stack, int n)
{
	stack_t *newnode;

	newnode = (stack_t *)malloc(sizeof(stack_t));
	if (newnode == NULL)
		return (-1);
	newnode->n = n;
	newnode->next = NULL;
	newnode->prev = NULL;

	if (*stack == NULL)
	{
		*stack = newnode;
	}
	else
	{
		newnode->next = *stack;
		(*stack)->prev = newnode;
		*stack = newnode;
	}
	return (0);
}

/**
 * free_list - frees linked list
 * @stack: pointer to the head of the list
 */

void free_list(stack_t **stack)
{
	stack_t *temp = *stack;

	while (*stack != NULL)
	{
		temp = (*stack)->next;
		free(*stack);
		*stack = temp;
	}
}

/**
 * del_nodebeg - deletes a node at the start of the list
 * as corresponds with the LIFO(last in first out) of a stack
 * meaning the last element of the list is the first element of the stack
 * @stack: pointer to the top of the list
 */

void del_nodebeg(stack_t **stack)
{
	stack_t *temp;

	if (*stack == NULL)
		return;
	temp = *stack;
	*stack = (*stack)->next;
	if (*stack != NULL)
		(*stack)->prev = NULL;
	free(temp);
}
