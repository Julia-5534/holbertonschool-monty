#include "monty.h"

/**
 * parse_me - execute the fuction
 * @function_name: name of the function
 * @line_number: line number of the instruction
 * @stack: ponter to pinter to the stack head
 * Return: void
 */

void parse_me(char *function_name, unsigned int line_number, stack_t **stack)
{
	instruction_t inst[] = {{"pall", pall},
		{"pop", pop},
		{"pint", pint},
		{"nop", nop},
		{"push", push},
		{"swap", swap},
		{"add", add},
		{NULL, NULL}};

	unsigned int i;

	for (i = 0; inst[i].opcode != NULL; i++)
	{
		if (strcmp(inst[i].opcode, function_name) == 0)
		{
			inst[i].f(stack, line_number);
		}
	}
}
