#include "monty.h"
#define UNUSED(x) (void)(x)

/**
 * push - Pushes an element to the top(beginning) of the stack_t list.
 * @top_pointer: Address of the global variable top.
 * @number: Integer to be pushed to stack.
 *
 * Return: Nothing(void).
 */
void push(stack_t **top_pointer, unsigned int number)
{
	stack_t *new_node = malloc(sizeof(stack_t));

	if (!new_node)
	{
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	new_node->prev = NULL;
	new_node->next = NULL;
	new_node->n = number;

	if (!(*top_pointer))
	{
		*top_pointer = new_node;
		return;
	}
	new_node->next = *top_pointer;
	(*top_pointer)->prev = new_node;
	*top_pointer = new_node;
}

/**
 * pall - Prints all the values on the stack_t list, starting from
 * the top of the stack.
 * @top_pointer: Address of the global variable top.
 * @argument: Unused.
 *
 * Return: Nothing(void).
 */
void pall(stack_t **top_pointer, unsigned int argument)
{
	stack_t *ptr = *top_pointer;

	UNUSED(argument);
	if (!(ptr))
		return;
	while (ptr)
	{
		printf("%u\n", ptr->n);
		ptr = ptr->next;
	}
}
