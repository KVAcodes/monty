#include "monty.h"

/**
 * handle_insufficient_div_error - Handles div's less than two
 *				   elements error.
 *
 * Return: Nothing(void).
 */
void handle_insufficient_div_error(void)
{
	fprintf(stderr, "L%d: can't div, stack too short\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

/**
 * handle_topofstackis0_div_error - Handles error that comes about when
 *				    top of stack is 0 to avoid division by 0.
 *
 * Return: Nothing(void).
 */
void handle_topofstackis0_div_error(void)
{
	fprintf(stderr, "L%d: division by zero\n", global.line_count);
	free_stack();
	fclose(global.monty_file);
	exit(EXIT_FAILURE);
}

