#include "monty.h"

/**
 * push - push the elements to a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	(void)line_number;

	if (input != NULL)
	{
		stack_t *ptr = malloc(sizeof(stack_t));

		ptr->n = atoi(input);
		ptr->next = (*stack);
		ptr->prev = NULL;

		if ((*stack) != NULL)
		{
			(*stack)->prev = ptr;
		}
		(*stack) = ptr;
	}
}

/**
 * pall - prints the elements of a linked list
 * @stack: the pointer to stack's first element
 * @line_number: line of the file being processed.
 * Return: void
 */

void pall(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;
	if (stack == NULL || *stack == NULL)
		return;
	ptr = *stack;
	while (ptr)
	{
		printf("%d\n", ptr->n);
		ptr = ptr->next;
	}
}

/**
 * pint - prints item of the stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being treated
 * Return: void
 */

void pint(stack_t **stack, unsigned int line_number)
{
	if (!*stack || !stack)
	{
		dprintf(STDERR_FILENO, "L%d: can't pint, stack empty\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
		dprintf(STDOUT_FILENO, "%d\n", (*stack)->n);
}

/**
 * pop - removes the last element of a stack
 * @stack: the pointer to the stack
 * @line_number: line of the file being processed.
 * Return: void
 */

void pop(stack_t **stack, unsigned int line_number)
{
	stack_t *ptr;

	(void)line_number;

	if (stack == NULL || *stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		exit(EXIT_FAILURE);
	}
	ptr = *stack;
	*stack = ptr->next;
	if (ptr->next != NULL)
		ptr->next->prev = NULL;
	free(ptr);
}

/**
 * swap - swap 2 first nodes
 * @stack: stack
 * @line_number: line number
 */

void swap(stack_t **stack, unsigned int line_number)
{
	stack_t *p = (*stack);
	int length = 0;

	while (p != NULL)
	{
		length++;
		p = p->next;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", line_number);
		exit(EXIT_FAILURE);
	}
	else
	{
		stack_t *node1 = (*stack);
		stack_t *node2 = (*stack)->next;
												node1->next = node2->next;
		node1->prev = node2;

		node2->prev = NULL;
		node2->next = node1;

		(*stack) = node2;
	}
}
