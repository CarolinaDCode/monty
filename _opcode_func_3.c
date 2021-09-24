#include "monty.h"

/**
 * _op_mod - divides the second top element
 * of the stack by the top element of the stack.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_mod(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't mod, stack too short\n", line_number);
		value[1] = -1;
		return;
	}

	if ((*head)->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		value[1] = -1;
		return;
	}
	temp = *head;
	(*head)->next->n %= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _op_pchar - prints the char at the top of the stack,
 * followed by a new line.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_pchar(stack_t **head, unsigned int line_number)
{
	int c;
	c = (*head)->n;
	if (*head != NULL)
	{
		if (c < 0 || c > 127)
		{
			fprintf(stderr,"L%d: can't pchar, value out of range\n",
				line_number);
			value[1] = -1;
			return;
		}

	}
	else
	{
		fprintf(stderr,"L%u: can't pchar, stack empty\n", line_number);
		value[1] = -1;
		return;
	}
	putchar(c);
	putchar('\n');
}

/**
 * _op_pstr - prints the string starting at the top of the stack,
 * followed by a new line.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_pstr(stack_t **head, unsigned int line_number)
{
	(void) line_number;
	while (*head != NULL && ((*head)->n > 0 && (*head)->n <= 127))
	{
		putchar((*head)->n);
		*head = (*head)->next;
	}
	putchar('\n');
}

/**
 * _op_rotl - rotates the stack to the top.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_rotl(stack_t **head, unsigned int line_number)
{
	stack_t *temp_1, *nodo_1, *nodo_2;

	(void) line_number;
	if(*head != NULL && (*head)->next != NULL)
	{
		temp_1 = nodo_1 = *head;
		nodo_2 = temp_1->next;

		while (temp_1->next != NULL)
			temp_1 = temp_1->next;

		temp_1->next = nodo_1;
		nodo_1->prev = temp_1;
		nodo_1->next = NULL;
		nodo_2->prev = NULL;
		*head = nodo_2;
	}
}


/**
 * _op_rotr - rotates the stack to the top.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_rotr(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
