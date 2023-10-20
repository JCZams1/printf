#include "main.h"

/**
 * widthFetch - This Calculates the width to be printed.
 *
 * @format: Formatted string assigned to print the arguments.
 * @a: Arguments List to be printed.
 *
 * @list: list of all arguments.
 *
 * Return: Returns the width.
 */
int widthFetch(const char *format, int *a, va_list list)
{
	int curr_a;
	int width = 0;

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		if (digit_det(format[curr_a]))
		{
			width *= 10;
			width += format[curr_a] - '0';
		}
		else if (format[curr_a] == '*')
		{
			curr_a++;
			width = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (width);
}
