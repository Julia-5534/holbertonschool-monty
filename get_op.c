#include "monty.h"

/**
 * get_op_func - function to select correct operation function
 * @s: 1st bytecode input (opcode)
 * Return: pointer to correct operation function
 */

void (*get_op_func(char *s))(stack_t **stack, unsigned int line_number)
{
	instruction_t ops[] = {
		{"push", push},
		{"pall", pall},
		{"pint", pint},
		{"pop", pop},
		{"swap", swap},
		{"add", add},
		{"nop", nop},
		{NULL, NULL}
	};
	unsigned int i = 0;

	if (!s)
		return (NULL);
	while (ops[i].opcode != NULL && strcmp(s, ops[i].opcode) != 0)
		i++;

	return (ops[i].f);
}
