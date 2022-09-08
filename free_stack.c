#include "monty.h"

/**
 * free_stack - Frees the stack_t list.
 *
 * Return: Nothing
 */
void free_stack(void)
{
	stack_t *tmp = top;

	while (top)
	{
		tmp = top->next;
		free(top);
		top = tmp;
	}
}
