#include "monty.h"

/**
 * add_end_node - add node to front of doubly linked list
 * @stack: pointer to head of list
 * @n: node data
 * Return: 0 if success, -1 if failed
 */

int add_end_node(stack_t **stack, int n)
{
	stack_t *new;

	if (!stack)
		return (-1);

	/* malloc and set new node data */
	new = malloc(sizeof(struct stack_s));
	if (!new)
	{
		printf("Error: malloc failed");
		return (-1);
	}
	new->n = n;

	/* account for empty linked list */
	if (*stack == NULL)
	{
		*stack = new;
		new->next = NULL;
		new->prev = NULL;
	}
	else /* insert to front */
	{
		new->next = *stack;
		(*stack)->prev = new;
		*stack = new;
	}
	return (0);
}

/**
 * delete_end_node - deletes node at end of doubly linked list
 * @stack: pointer to head of doubly linked list
 */

void delete_end_node(stack_t **stack)
{
	stack_t *del = NULL;

	/* account for only one node in list */
	del = *stack;
	if ((*stack)->next == NULL)
	{
		*stack = NULL;
		free(del);
	}
	else /* else delete front, and link correctly */
	{
		*stack = (*stack)->next;
		(*stack)->prev = NULL;
		free(del);
	}
}

/**
 * free_dlist - frees a doubly linked list with only int data, no strings
 * @stack: pointer to head of list
 */

void free_dlist(stack_t **stack)
{
	/* return if empty list */
	if (!stack)
		return;

	while (*stack && (*stack)->next)
	{
		*stack = (*stack)->next;
		free((*stack)->prev);
	}
	free(*stack);
}
