#include "monty.h"
/**
 * delete_stack - delete node at the top
 * Return: void
 */
void delete_stack(void)
{
	stack_t *tmp;

	tmp = args->head;
	args->head = tmp->next;
	free(tmp);
}
