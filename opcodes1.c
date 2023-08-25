#include "monty.h"
/**
 * pop - a function that remove that remove top element of the stack
 * @stack: pointer to the stack
 * @line_num: the line number where the pop function is called
 */
void pop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	if (args->head == NULL)
	{
		dprintf(2, "L%d: can not pop an empty stack\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	delet_stack();
	args->stack_lenght -= 1;
}
/**
 * push - a function that pushes an integer onto the stack
 * @stack: pointer to the stack
 * @line_num: the line number where the pop function is called
 */
void push(stack_t **stack, unsigned int line_num)
{
	if (args->n_tokens <= 1 || !(is_number(args->tokens[1])))
	{
		free_args();
		dprintf(2, "L%d: Usage: push int\n", line_num);
		exit(EXIT_FAILURE);
	}
	*stack = malloc(sizeof(stack_t));
	if (*stack == NULL)
	{
		malloc_flop();
	}
	(*stack)->next = (*stack)->prev = NULL;
	(*stack)->n = (int) atoi(args->tokens[1]);
	if (args->head == NULL)
	{
		args->head = *stack;
	}
	else
	{
		if (args->stack)
		{
			(*stack)->next = args->head;
			args->head->prev = *stack;
			args->head = *stack;
		}
		else
		{
			stack_t *tmp = args->head;

			while (tmp->next)
			{
				tmp = tmp->next;
			}
			tmp->next = *stack;
			(*stack)->prev = tmp;
		}
	}
	args->stack_lenght += 1;
}
/**
 * pall - prints all the elements in the stack
 * @stack: pointer to the stack
 * @line_num: the line number where the pall function is called
 */
void pall(stack_t **stack, unsigned int line_num)
{
	stack_t *temp;

	if (args->head == NULL)
	{
		return;
	}
	(void) line_num;
	(void) stack;

	temp = args->head;
	while (temp != NULL)
	{
		printf("%d\n", temp->n);
		temp = temp->next;
	}
}
/**
 * pint - a function that prints value at the top of the stack
 * @stack: pointer to the stack
 * @line_num: the line number where the pint function is called
 */
void pint(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	if (args->head == NULL)
	{
		dprintf(2, "L%d: can not pint, stack is empty\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	printf("%d\n", args->head->n);
}
/**
 * stack - a function that sets data format to a stack
 * @stack: a pointer to the stack
 * @line_num: the line where the mul function is called
 */
void stack(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
	args->stack = 1;
}
