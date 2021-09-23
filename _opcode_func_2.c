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

/**
 * _op_sub - subtracts the top element of the stack from
 * from the second top element of the stack.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_sub(stack_t **head, unsigned int line_number)
{
        stack_t *temp;

	if (*head == NULL || (*head)->next == NULL)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		value[1] = -1;
		return;
	}

	temp = *head;
	(*head)->next->n -= (*head)->n;
	*head = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _op_div - divides the second top element
 * of the stack by the top element of the stack.
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_div(stack_t **head, unsigned int line_number)
{
        stack_t *temp;

        if (*head == NULL || (*head)->next == NULL)
        {
                fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
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
        (*head)->next->n /= (*head)->n;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
}


/**
 * _op_mul - multiplies the second top element
 * multiplies the second top element
 * @head: head (stack) to the stack
 * @line_number: line number where opcode is located
 */
void _op_mul(stack_t **head, unsigned int line_number)
{
        stack_t *temp;

        if (*head == NULL || (*head)->next == NULL)
        {
                fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
                value[1] = -1;
                return;
        }

        temp = *head;
        (*head)->next->n *= (*head)->n;
        *head = (*head)->next;
        (*head)->prev = NULL;
        free(temp);
}
