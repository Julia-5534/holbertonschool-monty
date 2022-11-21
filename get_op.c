#include "monty.h"

/**
 * get_op - identifies which function corresponds to the string input
 * @s: char input to match valid opcode
 * Return: pointer to matched function, or NULL
 */

void (*get_op(char *s))(stack_t **stack, unsigned int line_num)
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
