#include "monty.h"

/**
 * handle_stack_empty_error - Handles stack empty error.
 *
 * Return: Nothing(void).
 */
void handle_stack_empty_error(void)
{
	fprintf(stderr, "L%d: can't pint, stack empty\n", global.line_count);
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}
