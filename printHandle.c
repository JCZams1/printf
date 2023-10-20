#include "main.h"
/**
 * printHandle - This Prints arguments according on its type.
 *
 * @fmt: Formatted string assigned to print all the arguments.
 * @list: Arguments lists to be printed.
 *
 * @ind: indices
 * @buffer: Buffer array assigned to handle print.
 *
 * @flags: This calculates all active flags.
 * @width: fetches width.
 *
 * @precision: Precision specific
 * @size: Size specified
 *
 * Return: Returns 1 or 2;
 */
int printHandle(const char *fmt, int *ind, va_list list, char buffer[],
	int flags, int width, int precision, int size)
{
	int i, unknow_len = 0, printed_chars = -1;
	fmt_t fmt_types[] = {
		{'c', charPrints}, {'s', stringPrints}, {'%', percentPrints},
		{'i', intPrints}, {'d', intPrints}, {'b', binaryPrints},
		{'u', unsignedNum}, {'o', num_octal}, {'x', num_hexa},
		{'X', hexa_upperNum}, {'p', pointerFunc}, {'S', nonPrintableAscii},
		{'r', str_reverse}, {'R', rot13String}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (fmt[*ind] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buffer, flags, width, precision, size));

	if (fmt_types[i].fmt == '\0')
	{
		if (fmt[*ind] == '\0')
			return (-1);
		unknow_len += write(1, "%%", 1);
		if (fmt[*ind - 1] == ' ')
			unknow_len += write(1, " ", 1);
		else if (width)
		{
			--(*ind);
			while (fmt[*ind] != ' ' && fmt[*ind] != '%')
				--(*ind);
			if (fmt[*ind] == ' ')
				--(*ind);
			return (1);
		}
		unknow_len += write(1, &fmt[*ind], 1);
		return (unknow_len);
	}
	return (printed_chars);
}
