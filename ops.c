#include "monty.h"

void push(stack_t **stack, unsigned int line_number);
{
	if(top == MAX-1) // Checking Array is full or not.
	{
		printf("Overflow\n");
	}
	else
	{
		top += 1; // top = top + 1
		stack[top] = line_number;
	}
	return;
}

/**
 * pall - print all nodes in stack
 * @stack: head of list
 * @line_number: bytecode line number
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *tmp = NULL;

	if (!stack || !*stack)
		return;

	(void) line_number;
	tmp = *stack;
	while (tmp != NULL)
	{
		printf("%d\n", tmp->n);
		tmp = tmp->next;
	}
}

/**
 * pint - print top node in stack
 * @stack: head of list
 * @line_number: bytecode line number
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!stack || !*stack)
	{
		printf("L%u: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}

/**
 * pop - removes node at front of dlinkedlist
 * @stack: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 */

void pop(stack_t **stack, unsigned int line_number)
{
	if (stack == NULL || *stack == NULL)
	{
		printf("L%u: can't pop an empty stack\n", line_number);
		free_dlist(stack);
		exit(EXIT_FAILURE);
	}
	else
	delete_end_node(stack);
}

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
