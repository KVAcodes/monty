#include "monty.h"

stack_t *top = NULL;

/**
 * main - The main function for the Monty Interpreter program.
 * @argc: The number of command line arguments.
 * @argv: A string array of the command line arguments.
 *
 * Return: It returns 0(EXIT_SUCCESS) on success,
 *	   Otherwise it returns 1(EXIT_FAILURE) on failure.
 */
int main(int argc, char **argv)
{
	FILE *monty_file;
	char buffer[128], *invalid_opcode;
	func_pointer opcode;
	unsigned int argument, line_count = 1;

	instruction_t map_to[] = {{"push", push}, {"pall", pall},
				{NULL, NULL}};
	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	monty_file = fopen(argv[1], "r");
	if (!monty_file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (fgets(buffer, sizeof(buffer), monty_file))
	{
		opcode = identify_opcode(map_to, buffer);
		if (opcode)
			argument = identify_opcode_argument(map_to, buffer, line_count);
		else
		{
			invalid_opcode = invalid_opcode_flag(buffer);
			if (invalid_opcode)
			{
				fprintf(stderr, "L%u: unknown instruction %s\n",
						line_count, invalid_opcode);
				exit(EXIT_FAILURE);
			}
			continue;
		}
		opcode(&top, argument);
		line_count++;
	}
	fclose(monty_file);
	free_stack();
	exit(EXIT_SUCCESS);
}
