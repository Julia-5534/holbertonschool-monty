#include "monty.h"

/**
 * main - monty program
 * @argc: number of arguments
 * @argv: argument value (filename)
 * Return: Always 0 (Success)
 */

int main(int argc, char **argv)
{
	FILE *fp;
	size_t size;
	char *line;
	stack_t *stack = NULL;
	unsigned int line_number = 1;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	line = NULL;
	size = 0;
	fp = fopen(argv[1], "r");
	if (fp == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}										while (getline(&line, &size, fp) != -1)
	{
		read_line(line, line_number, &stack);
		line_number++;
	}										free_stack(&stack);
	free(line);
	line = NULL;
	fclose(fp);
	return (0);
}
