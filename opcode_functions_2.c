#include "monty.h"

/**
 * add - Adds the top two elements of the stack.
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void add(stack_t **top_pointer, unsigned int argument)
{
	int sum;

	if ((!(*top_pointer)) || (!((*top_pointer)->next)))
		handle_insufficient_add_error();
	sum = ((*top_pointer)->n) + ((*top_pointer)->next->n);
	pop(top_pointer, argument);
	(*top_pointer)->n = sum;
}

