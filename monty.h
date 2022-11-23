#ifndef MONTY_H
#define MONTY_H

/* strtok Delimiters */
#define DELIMS "\n \r\t"
#define  _GNU_SOURCE

/*LIBRARIES*/
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <stddef.h>
#include <string.h>
#include <ctype.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

/*STRUCTS*/
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;

/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;

/**
 * struct free_struct - opcode and its function
 * @line: line buffer
 * @fp: file pointer
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct free_struct
{
	char *line;
	FILE *fp;
} early_free_struct;

extern early_free_struct efs;

/**
 * struct monty_d - stores multiply-used data elements for monty scripts
 * @buf: line pulled from @script
 * @script: input file from av[1]
 * Description: stores the most used elements globally
 */
typedef struct monty_d
{
	char *buf;
	FILE *script;
} monty_data;

/*PROTOTYPES*/
/*ops.c*/
int _isdigit(char *token);
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void pop(stack_t **stack, unsigned int line_number);

/*ops2.c*/
void swap(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);

/*get_op.c*/
void check_command(stack_t **stack, char *op, unsigned int line_number);

/*dlists.c*/
int add_end_node(stack_t **stack, int n);
void delete_end_node(stack_t **stack);
void free_dlist(stack_t **stack);

/*early_free.c*/
void early_free(stack_t **head);

/*monty_init.c*/
void monty_init(int ac, char *av[]);

/*monty_exit.c*/
void monty_exit(stack_t **stack);

/*read_file.c*/
void read_file(stack_t **stack);

/*Globals*/
extern char *buf;
extern FILE *monty;
extern monty_data data;
char *buf;
FILE *monty;
monty_data data;

#endif
