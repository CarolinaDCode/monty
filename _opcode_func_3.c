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
