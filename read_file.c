#include "monty.h"

/**
 * read_file - parses the monty file
 * @stack: It's the stack
 * Return: void
 */

void read_file(stack_t **stack)
{
	unsigned int line_number = 1;
	char *line = NULL;
	char *execute;
	ssize_t read_line;
	size_t length = 0;

	while ((read_line = getline(&line, &length, efs.fp)) != -1)
	{
		execute = strtok(line, DELIMS);

		efs.line = line;
												if (execute)
			get_op(stack, execute, line_number);
		
												line_number++;
	}
}
