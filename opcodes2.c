#include "monty.h"
/**
 * add - a function that two elements to the stack
 * @stack: pointer to the stack
 * @line_num: the line where the add function is called
 */
void add(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	(void) stack;

	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I can't add it, too short\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}

	temp1 = args->head;
	temp2 = temp1->next;

	temp2->n = temp1->n + temp2->n;
	delete_stack();

	args->stack_lenght -= 1;
}
/**
 * nop - a function
 * @stack: pointer to the stack
 * @line_num: the line where the nop function is called
 */
void nop(stack_t **stack, unsigned int line_num)
{
	(void) stack;
	(void) line_num;
}
/**
 * sub - a function that subtracts the top elements
 * @stack: pointer to the stack
 * @line_num: line where the sub function is called
 */
void sub(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I can't sub it, too short\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp1 = args->head;
	temp2 = temp1->next;

	temp2->n = temp2->n - temp1->n;
	delete_stack();

	args->stack_lenght -= 1;
}
/**
 * div_ - a function that divides the second top element of the satck
 * @stack: pointer to the stack
 * @line_num: the line where the function will be called
 */
void div_(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I can't div it, too short", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp1 = args->head;
	temp2 = temp1->next;

	if (temp1->n == 0)
	{
		dprintf(2, "L%d: dividing by Zero\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n / temp1->n;
	delete_stack();

	args->stack_lenght -= 1;
}
/**
 * mul - a function that multiplies the top of stack elements
 * @stack: pointer to the stack
 * @line_num: the line where mul function is called
 */
void mul(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;
	(void) stack;
	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I can't multiply it, too short", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp1 = args->head;
	temp2 = temp1->next;

	temp2->n = temp2->n * temp1->n;
	delete_stack();

	args->stack_lenght -= 1;
}
