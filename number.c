#include "monty.h"
#include <ctype.h>

/**
 * is_integer - checks if the charactes in astring are integers
 * @num: the integer
 * Return: 0 if integer
 *         -1 if not
 */

int is_integer(const char *num)
{
	int i = 0;

	if (*num == '-')
		i = 1;
	for (; *(num + i) != '\0'; i++)
	{
		if (isdigit(*(num + i)) == 0)
			return (-1);
	}
	return (0);
}
