#ifndef MONTY_H
#define MONTY_H

/*Standard Library*/
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <limits.h>
#include <unistd.h>
#include <fcntl.h>
#include <ctype.h>
#include <string.h>

/*Macros*/
#define NOT __attribute__
#define USED ((unused))

/*Structs*/
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
void dsh_read_line(char **buf);
void freestuff(stack_t **stack);
void *malloc(NOT USED size_t size);

/*monty.c*/
void monty_init(int ac, char *av[]);

/*strings.c*/
void squeeze_spaces(char *str_d);

/*ops.c*/
void push(stack_t **stack, unsigned int line_number);
void pall(stack_t **stack, unsigned int line_number);
void pint(stack_t **stack, unsigned int line_number);
void nop(stack_t **stack, unsigned int line_number);
void add(stack_t **stack, unsigned int line_number);

/*ops2.c*/
void pop(stack_t **stack, unsigned int line_number);
void swap(stack_t **stack, unsigned int line_number);

/*get_op.c*/
void (*get_op(char *s))(stack_t **stack, unsigned int line_num);

/*execscript.c*/
void exec_script(stack_t **stack);

/*Globals*/
extern char *buf;
extern FILE *monty;
extern monty_data data;
char *buf;
FILE *monty;
monty_data data;

#endif
