#include "monty.h"

/**
 * monty_init - handles some error checking and opens the script if possible.
 * @ac: number of arguments provided
 * @av: arguments provided by argv
 */

void monty_init(int ac, char *av[])
{
	FILE *temp = NULL;
	/*Check for correct usage.*/
	if (ac != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	/*Try to open the file */
	data.script = temp = fopen(av[1], "r");
	/*Check whether we actually opened it.*/
	if (!data.script)
	{
		fprintf(stderr, "Error: Can't open file %s\n", av[1]);
		exit(EXIT_FAILURE);
	}
}
