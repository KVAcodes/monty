#include "monty.h"

/**
 * handle_pint_stack_empty_error - Handles pint stack empty error.
 *
 * Return: Nothing(void).
 */
void handle_pint_stack_empty_error(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", global.line_count);
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_pop_stack_empty_error - Handles pop stack empty error.
 *
 * Return: Nothing(void).
 */
void handle_pop_stack_empty_error(void)
{
	fprintf(stderr, "L%d: can't pop an empty stack\n", global.line_count);
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
