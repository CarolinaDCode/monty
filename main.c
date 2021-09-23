#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/*int value[2] = {0, 0};*/
/**
 * main - function main
 * @argc: argc
 * @argv: argv
 * Return: value
 */
int main(int argc, char **argv)
{
	vars_opc check = {1, NULL, NULL, NULL};
	stack_t *head = NULL;
	size_t size = 0;
	void (*getf)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr,"USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	check.fd = fopen(argv[1], "r");
	if (check.fd == NULL)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (getline(&(check.line), &size, check.fd) != -1)
	{
		if (strcmp(check.line, "\n") == 0)
			continue;

		check.list_items = _tokenizer_line(check.line, " \n\t");
		check_if_push(check, head);
		getf = get_func_opcode(check.list_items[0]);
		check_opcode(getf, check, head);
		(*getf)(&head, check.cont_line);
		_fail(check, head);

		check.cont_line++;
	}
	return (0);
}