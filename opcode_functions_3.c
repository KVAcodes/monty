#include "monty.h"

/**
 * _mod - computes the remainder of the division of the second top
 *	  of the stack by the top element of the stack.
 * @top_pointer: The address of the global variable global.top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void _mod(stack_t **top_pointer, unsigned int argument)
{
	int modulo;

	if ((!(*top_pointer)) || (!((*top_pointer)->next)))
		handle_insufficient_mod_error();
	if ((*top_pointer)->n == 0)
		handle_topofstackis0_div_error();
	modulo = ((*top_pointer)->next->n) % ((*top_pointer)->n);
	pop(top_pointer, argument);
	(*top_pointer)->n = modulo;
}
