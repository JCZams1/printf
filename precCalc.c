#include "main.h"

/**
 * precisionFetch - This Calculates all the precision for printings.
 *
 * @format: String formatted in which to print the arguments
 *
 * @a: Arguments list to be printed.
 *
 * @list: list of arguments.
 *
 *
 * Return: Returns the  Precision.
 */
int precisionFetch(const char *format, int *a, va_list list)
{
	int curr_a = *a + 1;
	int precision = -1;

	if (format[curr_a] != '.')
		return (precision);

	precision = 0;

	for (curr_a += 1; format[curr_a] != '\0'; curr_a++)
	{
		if (digit_det(format[curr_a]))
		{
			precision *= 10;
			precision += format[curr_a] - '0';
		}
		else if (format[curr_a] == '*')
		{
			curr_a++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*a = curr_a - 1;

	return (precision);
}
