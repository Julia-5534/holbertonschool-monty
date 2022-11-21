#include "monty.h"

/**
 * swap - swap locations of previous stack with the top stack
 * @stack: node to be swapped
 * @line_number: node number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;
	
	if (*stack == NULL || (*stack)->next == NULL)
	{
		printf("L%u: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	tmp = (*stack)->next;
	if (tmp->next != NULL)
	{
		(*stack)->next = tmp->next;
		(*stack)->next->prev = *stack;
	}
	else
	{
		tmp->prev->prev = tmp;
		tmp->prev->next = NULL;
	}
	tmp->prev = NULL;
	tmp->next = *stack;
	(*stack) = tmp;
}

/**
 * add - adds the first two elements of a stack, replaces both with sum
 * @stack: linked list stack to add
 * @line_number: current line number of bytecode file
 */

void add(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = *stack;

	if (!tmp || !tmp->next)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		free_stack(stack);
		err();
	}
	tmp->next->n += tmp->n;
	*stack = tmp->next;
	(*stack)->prev = NULL;
	free(tmp);
}

/**
 * nop - NO operator, does nothing.
 * @stack: ignored
 * @line_number: ignored
 */
void nop(stack_t **stack, unsigned int line_number)
{
	(void) stack;
	(void) line_number;
}
