#include "monty.h"
#include <string.h>
/**
 *_tokenizer_line - item separating function
 *@buffer: string to separate
 *@delimiter: separator
 *Return: pointer to buffer
 */
char **_tokenizer_line(char *buffer, char *delimiter)
{
	char **token = NULL;
	int i = 0;

	if (buffer == NULL)
		return (NULL);

	token = malloc(sizeof(char *) * 10);
	if (token == NULL)
	{
		fprintf(stderr, "Error: malloc failed");
		exit(EXIT_FAILURE);
	}
	while ((token[i] = strtok(buffer, delimiter)) != NULL)
	{
		i++;
		buffer = NULL;
	}
	return (token);
}

/**
 * free_stack - function that frees a dlistint_t list.
 * @head: head
 */

void free_stack(stack_t *head)
{
	stack_t *temp;

	if (head == NULL)
		return;

	while (head != NULL)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}
