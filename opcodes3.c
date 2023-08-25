#include "monty.h"
/**
 * mod - a function that computes the rest of the division
 * @stack: pointer to the stack
 * @line_num: line number where the mod function is called
 */
void mod(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	(void) stack;
	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I can't mod, the stack is short\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp1 = args->head;
	temp2 = temp1->next;

	if (temp1->n == 0)
	{
		dprintf(2, "L%d: dividing by 0\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp2->n = temp2->n % temp1->n;
	delete_stack();

	args->stack_lenght -= 1;
}
/**
 * pchar - a function that prints the char at the top of the stack.
 * @stack: pointer to the stack
 * @line_num: the line where the pchar functon is called
 */
void pchar(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1;

	(void) stack;
	if (args->stack_lenght < 2)
	{
		dprintf(2, "L%d: I cant pchar, stack not long enough\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	temp1 = args->head;
	if (!(temp1->n >= 0 && temp1->n <= 127))
	{
		dprintf(2, "L%d: I cant pchar, value out of range\n", line_num);
		free_all_args();
		exit(EXIT_FAILURE);
	}
	printf("%c\n", temp1->n);
}
/**
 * pstr - a function that prints the string starting at the top of the stack
 * @stack: pointer to the stack
 * @line_num: the line where the pstr function is called from
 */
void pstr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1;

	(void) stack;
	(void) line_num;

	temp1 = args->head;

	while (temp1 != NULL)
	{
		if (!(temp1->n >= 0 && temp1->n <= 127))
		{
			break;
		}
		printf("%c", temp1->n);
		temp1 = temp1->next;
	}
	printf("\n");
}
/**
 * rotl - a function thaat rotate the stack to the top
 * @stack: pointer to the stack
 * @line_num: the line where the rotl function is called
 */
void rotl(stack_t **stack, unsigned int line_num)
{
	stack_t *temp1, *temp2;

	(void) stack;
	(void) line_num;

	if (args->stack_lenght < 2)
	{
		return;
	}
	temp1 = args->head;
	temp2 = temp1->next;

	args->head = temp2;
	while (temp2)
	{
		if (temp2->next == NULL)
		{
			temp2->next = temp1;
			temp1->next = NULL;
			temp1->prev = temp2;
			break;
		}
		temp2 = temp2->next;
	}
}
/**
 * rotr - a function that rotate the stack to the bottom
 * @stack: pointer to the stack
 * @line_num: the line where the rotr function is called
 */
void rotr(stack_t **stack, unsigned int line_num)
{
	stack_t *temp, *end;

	(void) stack;
	(void) line_num;
	if (args->stack_lenght < 2)
	{
		return;
	}
	temp = args->head;
	while (temp)
	{
		if (temp->next == NULL)
		{
			end = temp;
			break;
		}
		temp = temp->next;
	}
	end->prev->next = NULL;
	end->next = args->head;
	end->prev = NULL;

	args->head = end;
}
