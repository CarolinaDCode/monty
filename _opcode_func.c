#include "monty.h"
/**
 * _op_pall - pull a value to the stack
 * @stack: the head of the stack
 * @line_number: line number where the opcode is located
 */
void _op_pall(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;
	(void) line_number;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}

/**
 * _op_push - pull a value to the stack
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void _op_push(stack_t **head, unsigned int line_number)
{
	stack_t *new_node;
	stack_t *new_head = *head;
	(void) line_number;

	new_node = malloc(sizeof(stack_t));
	if (new_node == NULL)
	{
		printf("Error: malloc failed\n");
		value[1] = -1;
		return;
	}

	if (new_head == NULL)
	{
		new_node->next = NULL;
		new_node->prev = NULL;
		new_node->n = value[0];

		*head = new_node;
		return;
	}
	new_node->n = value[0];
	new_node->next = new_head;
	new_node->prev = NULL;
	new_head->prev = new_node;
	*head = new_node;
}

/**
 * _op_pint - prints the value at the top of the stack.
 * @stack: the head of the stack
 * @line_number: line number where the opcode is located
 */
void _op_pint(stack_t **stack, unsigned int line_number)
{
	stack_t *h = *stack;

	if (h != NULL)
	{
		printf("%d\n", h->n);
	}
	else
	{
		printf("L%d: can't pint, stack empty", line_number);
		value[1] = -1;
	}
}

/**
 * _op_pop - prints the value at the top of the stack.
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void _op_pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		printf("L%d: can't pop an empty stack\n", line_number);
		value[1] = -1;
		return;
	}
	temp = *head;
	if (temp->next == NULL)
	{
		free(temp);
		(*head) = NULL;
		return;
	}
	(*head) = (*head)->next;
	(*head)->prev = NULL;
	free(temp);
}

/**
 * _op_swap - intercambia los dos elementos superiores de la pila.
 * @head: the head (stack) of the stack
 * @line_number: line number where the opcode is located
 */
void _op_swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp_1, *temp_2;
	int num_value;

	if (*head == NULL || (*head)->next == NULL)
	{
		printf("L%d: can't swap, stack too short\n", line_number);
		value[1] = -1;
		return;
	}

	temp_1 = *head;
	temp_2 = temp_1->next;
	num_value = temp_1->n;
	temp_1->n = temp_2->n;
	temp_2->n = num_value;
}
