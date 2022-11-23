#include "monty.h"

/**
 * read_line - intrepets the line
 * @line: string containnig the line
 * @line_number:number of line
 * @stack: pointer to the stack head
 * Return: void
 */

void read_line(char *line, unsigned int line_number, stack_t **stack)
{
	char *function_name;
	int inoperative;
	char *p;
	int flag = 0;

	function_name = strtok(line, " \t\n");
	if (function_name != NULL)
	{
		input = strtok(NULL, " \t\n");
		inoperative = valid(function_name);
		p = input;
		flag = is_string_number(p);
		if (strcmp(function_name, "push") == 0 && (!input || flag == 1))
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else if (inoperative != VALID)
		{
			print_error(line, line_number);
			free_stack(stack);
			stack = NULL;
			free(line);
			line = NULL;
			exit(EXIT_FAILURE);
		}
		else
			parse_me(function_name, line_number, stack);
	}
}

/**
 * is_string_number - checks if string is a number
 * @string: string
 * Return: 1 or 0
 */

int is_string_number(char *string)
{
	while (string != NULL && *string != '\0')
	{
		if (*string == '-')
		{
			if (isdigit(*(string + 1)) == 0 && string--)
				return (1);
		}
		else if (*string != '-' && isdigit(*string) == 0)
			return (1);
		string++;
	}
	return (0);
}

/**
 * valid - checks if the syntax is valid
 * @function_name: name of the function that can be "push"
 * Return: 0 (function is unknown) on failure and 1 on success
 */

int valid(char *function_name)
{
	char name[][10] = {"push", "pall", "pint", "pop", "nop", "swap", "add", ""};
	unsigned int i;

	for (i = 0; name[i][0] != '\0'; i++)
	{
		if (strcmp(name[i], function_name) == 0)
			return (1);
	}
	return (0);
}

/**
 * print_error - print error
 * @line:string containing the line
 * @line_number: number of the line
 * Return: void, nothingness
 */

void print_error(char *line, unsigned int line_number)
{
	(void)line;

	fprintf(stderr, "L%d: unknown instruction %s\n", line_number, line);
}

/**
 * free_stack - print error
 * @stack: pointer to stack head
 * Return: void, nothingness
 */

void free_stack(stack_t **stack)
{
	stack_t *ptr, *tmp;

	ptr = *stack;
	while (ptr)
	{
		tmp = ptr;
		ptr = ptr->next;
		free(tmp);
		tmp = NULL;
	}
}
