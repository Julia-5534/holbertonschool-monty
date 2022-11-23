#include "monty.h"

/**
 * check_command - checks the parsed commands against function pointers
 * @op: operation to perofrm
 * @line_number: line number
 * @stack: it's the stack
 */

void check_command(stack_t **stack, char *op, unsigned int line_number)
{
	int i;
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

	for (i = 0; ops[i].opcode; i++)
		if (strcmp(op, ops[i].opcode) == 0)
		{
			ops[i].f(stack, line_number);
				return;
		}
	if (op[0] != '#')
	{
		fprintf(stderr, "L%u: unknown instruction %s\n", line_number, op);
		early_free(stack);
		exit(EXIT_FAILURE);
	}
}
