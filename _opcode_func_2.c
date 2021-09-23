#include "monty.h"

/**
 * _op_add - adds the top two elements of the stack.
 * @head: head (stack) to the stack;
 * @line_number: line number where opcode is located
 */
void _op_add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		value[1] = -1;
		return;
	}

	temp = *head;

	(*head)->next->n += (*head)->n;

	*head = (*head)->next;

	(*head)->prev = NULL;
	free(temp);
}
/**
 * _op_nop - operation does nothing
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_nop(stack_t **head, unsigned int line_number)
{
	(void) head;
	(void) line_number;
}
