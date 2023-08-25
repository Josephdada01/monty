#include "monty.h"
/**
 * enclose_stream - a function that closes the file stream
 */
void enclose_stream(void)
{
	if (args->stream == NULL)
	{
		return;
	}
	fclose(args->stream);
	args->stream = NULL;
}
/**
 * run_command - a function that runs specified instruction by args
 */
void run_command(void)
{
	stack_t *stack = NULL;

	if (args->n_tokens == 0)
	{
		return;
	}
	args->instruction->f(&stack, args->line_num);
}
/**
 * is_number - a function check if a string rep a valid int
 * @str: the string to check
 * Return: 1 if the string is valid
 */
int is_number(char *str)
{
	int i = 0;

	while (str[i])
	{
		if (i == 0 && str[i] == '-' && str[i + 1])
		{
			i++;
			continue;
		}
		if (str[i] < '0' || str[i] > '9')
		{
			return (0);
		}
		i++;
	}
	return (1);
}
