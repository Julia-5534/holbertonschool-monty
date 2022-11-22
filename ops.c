#include "monty.h"

/**
 * _isdigit - Checks if a string contains only numbers
 * @token: The string to check
 * Return: 1 if is a number, 0 if not a number
 */

int _isdigit(char *token)
{
	int i = 0;

	if (token[0] == '-')
		i++;

	while (token[i])
	{
		if (token[i] < '0' || token[i] > '9')
			return (0);
		i++;
	}
	return (1);
}

/**
 * push - pushes a node to the top of the stack
 * @line_number: The executing line of the monty file
 * @stack: The head node of our stack
 * Return: void
 */

void push(stack_t **stack, unsigned int line_number)
{
	char *num;
	stack_t *pushed_node;

	num = strtok(NULL, DELIMS);

	if (num == NULL || _isdigit(num) == 0)
	{
		fprintf(stderr, "L%u: usage: push integer\n", line_number);
		early_free(stack);
		exit(EXIT_FAILURE);
	}

	pushed_node = malloc(sizeof(stack_t));
	if (pushed_node == NULL)
	{
		fprintf(stderr, "Error: malloc failed\n");
		early_free(stack);
		exit(EXIT_FAILURE);
	}

	pushed_node->n = atoi(num);
	pushed_node->prev = NULL;
	pushed_node->next = *stack;

	if (*stack != NULL)
		(*stack)->prev = pushed_node;
	
	*stack = pushed_node;
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
