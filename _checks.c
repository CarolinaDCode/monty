#include "monty.h"

int value[2] = {0, 0};
/**
 * check_opcode - function
 * @get_op: get_op
 * @check: check
 * @head: head
 */
void check_opcode(void(*get_op)(), vars_opc check, stack_t *head)
{
	if (get_op == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n",
		       check.cont_line, check.list_items[0]);
		free(check.line);
		fclose(check.fd);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
	free(check.list_items);
}

/**
 * _is_number - function
 * @ptr: ptr
 * Return: value
 */
int _is_number(char *ptr)
{
	int i;

	if (ptr != NULL && ptr[0] == '-')
		ptr++;

	for (i = 0; ptr[i] != '\0'; i++)
	{
		if (!isdigit(ptr[i]))
			return (0);
	}
	return (1);
}

/**
 * check_if_push - function
 * @check: check
 * @head: head
 */
void check_if_push(vars_opc check, stack_t *head)
{
	if (strcmp(check.list_items[0], "push") == 0)
	{
		if (check.list_items[1][0] != '\0'
		    && _is_number(check.list_items[1]))
		{
			value[0] = atoi(check.list_items[1]);
		}
		else
		{
			fprintf(stderr, "L%d: usage: push integer\n",
				check.cont_line);
			free(check.line);
			fclose(check.fd);
			free_stack(head);
			exit(EXIT_FAILURE);
		}
	}
}

/**
 *  _fail - function
 * @check: check
 * @head: head
 */
void _fail(vars_opc check, stack_t *head)
{
	if (value[1] == -1)
	{
		free(check.line);
		fclose(check.fd);
		free_stack(head);
		exit(EXIT_FAILURE);
	}
}
