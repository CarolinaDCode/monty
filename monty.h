#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include <stdarg.h>

/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
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
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;


/**
 * struct vars_check - opcode and its function
 * @cont_line: cont_line
 * @list_items: list_items
 * @line: line
 * @fd: fd
 * Description: after
 */
typedef struct vars_check
{
	int cont_line;
	char **list_items;
	char *line;
	FILE *fd;
} vars_opc;

extern int value[];

/*HELP FUNCTIONS*/
char **_tokenizer_line(char *buffer, char *delimiter);
void free_stack(stack_t *head);

/*VALIDATING ERRORS*/
void check_opcode(void(*get_op)(), vars_opc check, stack_t *head);
void check_if_push(vars_opc check, stack_t *head);
void _fail(vars_opc check, stack_t *head);
int _is_number(char *ptr);

void (*get_func_opcode(char *s))(stack_t **stack, unsigned int line_number);

/*OPERATIONS*/
void _op_pall(stack_t **stack, unsigned int line_number);
void _op_push(stack_t **head, unsigned int line_number);
void _op_pint(stack_t **stack, unsigned int line_number);
void _op_pop(stack_t **head, unsigned int line_number);
void _op_swap(stack_t **head, unsigned int line_number);
void _op_add(stack_t **head, unsigned int line_number);
void _op_nop(stack_t **head, unsigned int line_number);
void _op_sub(stack_t **head, unsigned int line_number);
void _op_div(stack_t **head, unsigned int line_number);
void _op_mul(stack_t **head, unsigned int line_number);
void _op_mod(stack_t **head, unsigned int line_number);
void _op_pchar(stack_t **head, unsigned int line_number);
void _op_pstr(stack_t **head, unsigned int line_number);
void _op_rotl(stack_t **head, unsigned int line_number);

#endif
