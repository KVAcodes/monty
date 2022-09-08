#include "monty.h"

/**
 * identify_opcode - Returns the function for the corresponding
 * 		opcode found in the buffer.
 * @map: An array of instruction_t objects containing opcodes
 * 	and the their corresponding functions.
 * @buffer: An array of characters gotten from the monty_file
 * 	possibly containing opcode and its arguments..
 *
 * Return: The function corresponding to the opcode found in buffer,
 * 	Otherwise returns NULL if no opcode is found in buffer.
 */
func_pointer identify_opcode(instruction_t * map, char *buffer)
{
	unsigned int count;

	count = 0;
	while (map[count].opcode)
	{
		if (strstr(buffer, map[count].opcode))
			return (map[count].f);
		count++;
	}
	return (NULL);
}


/**
 * identify_opcode_argument - Returns the first integer argument
 * 			to the opcode found
 * @map: An array of instruction_t objects containing opcodes
 * 	and the their corresponding functions.
 * @buffer: An array of characters gotten from the monty_file.
 *
 * Return: The first integer argument found if not dealing with 
 * 	the (pall) opcode, Otherwise 0 if dealing with the (pall).
 */
int identify_opcode_argument(instruction_t * map, char *buffer)
{
	unsigned int count;
	char *ptr, *tmp;

	count = 0;
	while (map[count].opcode)
	{
		ptr = strstr(buffer, map[count].opcode);
		if (ptr)
		{
			if (map[count].opcodes == "pall")
				return (0);
			break;
		}
		count++;
	}
	while (ptr)
	{
		ptr++;
		if (*ptr >= '0' && *ptr <= '9')
		{
			tmp = ptr;
			while (*ptr >= '0' && *ptr <= '9')
				ptr++;
			*ptr = '\0';
			break;
		}
	}
	return(atoi(tmp));
}
