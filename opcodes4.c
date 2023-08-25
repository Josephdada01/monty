#include "monty.h"
/**
 * stack - a function that sets data to the stack(LIFO)
 * @stack: the pointer to the stack
 * @line_num: the line the stack function will be called
 */
void stack(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	args->stack = 1;
}
/**
 * queue - a functon that sets data to the queque
 * @stack: the pointer to the stack
 * @line_num: the line the queue function will be called
 */
void queue(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	args->stack = 0;
}
/**
 * comment_ - a function that check if tokens start with #
 * Return: 0 || 1 on success
 */
int comment_(void)
{
	if (args->tokens && args->tokens[0] && args->tokens[0][0] == '#')
	{
		return (1);
	}
	return (0);
}
