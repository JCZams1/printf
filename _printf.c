#include "main.h"

void print_buffer(char buffer[], int *buff_ind);

/**
 * _printf - Executes Printf functions.
 *
 * @format: All formats used.
 *
 * Return: Returns Printed characters.
 */
int _printf(const char *format, ...)
{
	int a, printed = 0, printed_chars = 0;
	int flags, width, precision, size, buff_ind = 0;
	va_list list;
	char buffer[BUFF_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (a = 0; format && format[a] != '\0'; a++)
	{
		if (format[a] != '%')
		{
			buffer[buff_ind++] = format[a];
			if (buff_ind == BUFF_SIZE)
				print_buffer(buffer, &buff_ind);
			/* write(1, &format[i], 1);*/
			printed_chars++;
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			flags = fetch_flags(format, &a);
			width = widthFetch(format, &a, list);
			precision = precisionFetch(format, &a, list);
			size = sizeFetch(format, &a);
			++a;
			printed = printHandle(format, &a, list, buffer,
				flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}

	print_buffer(buffer, &buff_ind);

	va_end(list);

	return (printed_chars);
}

/**
 * print_buffer - This Prints all contents of the buffer if it exist.
 *
 * @buffer: Chars Array.
 *
 * @buff_ind: Index where to add next char,it also represents the length.
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
