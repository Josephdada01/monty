#include "monty.h"
/**
 * free_symbol - a function that free alocated memory for the symbols/tokens
 */
void free_symbol(void)
{
	int i = 0;

	if (args->tokens == NULL)
	{
		return;
	}
	while (args->tokens[i])
	{
		free(args->tokens[i]);
		i++;
	}
	free(args->tokens);
	args->tokens = NULL;
}
/**
 * free_all_args - a function that allocates memory for all arguments
 */
void free_all_args(void)
{
	enclose_stream();
	free_symbol();
	free_args();
}
/**
 * free_stack - a function that free the node in a stack list
 * @head: the first node of a distinct link
 * Return: void
 */
void free_stack(stack_t *head)
{
	if (head == NULL)
	{
		return;
	}
	if (head->next != NULL)
	{
		free_stack(head->next);
	}
	free(head);
}
/**
 * free_head - a function that frees memory allocated for the head and
 * set it to NULL
 */
void free_head(void)
{
	if (args->head)
	{
		free_stack(args->head);
	}
	args->head = NULL;
}
/**
 * free_args - free memory for arguments to pointer
 */
void free_args(void)
{
	if (args == NULL)
	{
		return;
	}
	if (args->instruction)
	{
		free(args->instruction);
		args->instruction = NULL;
	}
	free_head();

	if (args->line)
	{
		free(args->line);
		args->line = NULL;
	}
	free(args);
}
