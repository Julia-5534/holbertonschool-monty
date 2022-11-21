#include "monty.h"

/**
 * is_number - iterates each character of string to check of isdigit
 * @n: integer
 * Return: 0 if is number, else -1 if not
 */

int is_number(const char *n)
{
	int i = 0;

	if (*n == '-')
		i = 1;
	for (; *(n + i) != '\0'; i++)
	{
		if (isdigit(*(n + i)) == 0)
			return (-1);
	}
	return (0);
}

/**
 * push - adds node to the start of dlinkedlist
 * @stack: head of linked list (node at the bottom of stack)
 * @line_number: bytecode line number
 * @n: integer
 */

void push(stack_t **stack, unsigned int line_number, const char *n)
{
	if (!stack)
		return;
	if (is_number(n) == -1)
	{
		printf("L%u: usage: push integer\n", line_number);
		free_dlist(stack);
		exit(EXIT_FAILURE);
	}
	else
	{
		if (add_end_node(stack, atoi(n)) == -1)
		{
			free_dlist(stack);
			exit(EXIT_FAILURE);
		}
	}
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
