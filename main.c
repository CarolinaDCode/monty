#define  _GNU_SOURCE
#include <stdio.h>
#include "monty.h"

/**
 * main - function main
 * @argc: argc
 * @argv: argv
 * Return: value
 */
int main(int argc, char **argv)
{
	vars_opc check = {0, NULL, NULL, NULL};
	stack_t *head = NULL;
	size_t size = 0;
	void (*getf)(stack_t **stack, unsigned int line_number);

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
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
		check.cont_line++;
		/*if (strcmp(check.line, "\n") == 0)
		  continue;*/

		check.list_items = _tokenizer_line(check.line, " \n\t");
		if (check.list_items[0] == NULL)
			continue;
		check_if_push(check, head);
		getf = get_func_opcode(check.list_items[0]);
		check_opcode(getf, check, head);
		(*getf)(&head, check.cont_line);
		_fail(check, head);

	}
	free(check.line);
	fclose(check.fd);
	free_stack(head);
	return (0);
}
