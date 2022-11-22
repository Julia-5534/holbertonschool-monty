#include "monty.h"

early_free_struct efs;

/**
 * main - interperter for Monty files
 * @argc: argument count
 * @argv: arguments passed
 * Return: EXIT_SUCCESS if successful or EXIT_FAILURE if not
 */

int main(int argc, char *argv[])
{
	stack_t *stack = NULL;

	monty_init(argc, argv);

	read_file(&stack);

	monty_exit(&stack);

	return (EXIT_SUCCESS);
}
