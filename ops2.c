#include "monty.h"

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
