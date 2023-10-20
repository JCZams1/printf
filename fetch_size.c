#include "main.h"

/**
 * sizeFetch - This calculates the sizes to put the arguments.
 *
 * @format: Formatted string assigned to print the arguments.
 *
 * @a: List of all the arguments to be printed.
 *
 * Return: Returns all precision.
 *
 */
int sizeFetch(const char *format, int *a)
{
	int curr_a = *a + 1;
	int size = 0;

	if (format[curr_a] == 'l')
		size = S_LONG;
	else if (format[curr_a] == 'h')
		size = S_SHORT;

	if (size == 0)
		*a = curr_a - 1;
	else
		*a = curr_a;

	return (size);
}
