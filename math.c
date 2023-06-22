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

/**
 * sub - subtracts the values of the top two elements of the list
 * @stack: pointer to the first node
 * @line_number: the line number
 * Description: the function subtracts the two top values of the list
 * if there are less than two elements in the list it prints an error
 * adn exits
 * the result is stored in the second top element
 * the top element is removed and the second becomes the top
 */

void sub(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n -= top->n;

	*stack = second;
	free(top);
	(*stack)->prev = NULL;
}

/**
 * m_div - monty_div divides the two top elements in the stack
 * @stack: the pointer to the head of the stack
 * @line_number: the line number
 * Description: it divides the top 2 elements in the list
 * if there are less than 2 elements it returns an error
 * if the top value is 0 it returns an error
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n /= top->n;

	*stack = second;
	free(top);
	(*stack)->prev = NULL;
}

/**
 * m_mul - multiplication counterpart of the math.c functions
 * @stack: pointer to the head of the list
 * @line_number: the bytecode line number
 */

void m_mul(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}

	top = *stack;
	second = top->next;

	second->n *= top->n;

	*stack = second;
	free(top);
	(*stack)->prev = NULL;
}

/**
 * m_mod - modulus counterpart of the math.c functions
 * @stack: pointer to the head of the list
 * @line_number: bytecode line number
 * Description: works like the m_div function
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
	stack_t *top, *second;

	if (*stack == NULL || (*stack)->next == NULL)
	{
		fprintf(stderr, "L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	top = *stack;
	second = top->next;

	if (top->n == 0)
	{
		fprintf(stderr, "L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}

	second->n %= top->n;

	*stack = second;
	free(top);
	(*stack)->prev = NULL;
}
