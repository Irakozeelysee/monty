#include "monty.h"

/**
 * sub - subtracts thr value from the top element and the
 * second top element
 * @stack: =====
 * @line_number: ===
 * Description: subtracts the value from the top element and the
 * second top element
 * the result is stored in the second top element
 * the top elemnt of the stack is removed and the second top that stores
 * the result becomes the top element
 */

void sub(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't sub, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n -= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * m_div - monty div works the same way as the sub function(opcode)
 * @stack: ====
 * @line_number: ======
 * Description: works the same way as the sub function except it divides
 * instead of subtracting, if the top element is 0 it prints an error and
 * exits
 * the result is stored in the second top(which will be the new top after the
 * top is deleted)
 */

void m_div(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't div, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n /= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * m_mul - monty multiplication
 * @stack: ====
 * @line_number: ====
 * Description: does multiplication
 */

void m_mul(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mul, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n *= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}

/**
 * m_mod - monty modulos
 * @stack: ====
 * @line_number: ====
 */

void m_mod(stack_t **stack, unsigned int line_number)
{
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't mod, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	if ((*stack)->n == 0)
	{
		printf("L%u: division by zero\n", line_number);
		exit(EXIT_FAILURE);
	}
	(*stack)->next->n %= (*stack)->n;
	*stack = (*stack)->next;
	free((*stack)->prev);
	(*stack)->prev = NULL;
}
