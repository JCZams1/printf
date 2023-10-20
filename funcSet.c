#include "main.h"

/************************* PRINT CHAR *************************/

/**
 * charPrints - Prints character
 *
 * @types: All arguments
 *
 * @buffer: A Buffer array that handles print.
 *
 * @flags:  Calculates all active flags.
 *
 * @width: gwts Width.
 *
 * @precision: Precision specific
 *
 * @size: Size specific
 *
 * Return: Number of all characters printed
 */
int charPrints(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char b = va_arg(types, int);

	return (char_handleWrite(b, buffer, flags, width, precision, size));
}
/************************* PRINT A STRING *************************/
/**
 * stringPrints - Prints string.
 *
 * @types: Arguments.
 *
 * @buffer: Buffer array that handles print.
 *
 * @flags:  Calculates all active flags.
 *
 * @width: fetch width.
 *
 * @precision: Precision specific.
 *
 * @size: Size specific.
 *
 * Return: Number of printed characters
 */
int stringPrints(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int length = 0, j;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "      ";
	}

	while (str[length] != '\0')
		length++;

	if (precision >= 0 && precision < length)
		length = precision;

	if (width > length)
	{
		if (flags & F_MINUS)
		{
			write(1, &str[0], length);
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			return (width);
		}
		else
		{
			for (j = width - length; j > 0; j--)
				write(1, " ", 1);
			write(1, &str[0], length);
			return (width);
		}
	}

	return (write(1, str, length));
}
/************************* PRINT PERCENT SIGN *************************/
/**
 * percentPrints - It P8rints a percentage  sign.
 *
 * @types: Arguments
 *
 * @buffer: Buffer array this handle print.
 *
 * @flags:  Calcs all active flags.
 *
 * @width: fetch  width.
 *
 * @precision: Precision specifica
 *
 * @size: Size specifier
 *
 * Return: Number of all printed characterd
 */
int percentPrints(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/************************* PRINT INT *************************/
/**
 * intPrints - Prints an int
 *
 * @types: All arguments.
 *
 * @buffer: Buffer array that handles print.
 *
 * @flags: This Calculates all active flags.
 *
 * @width: fetches width.
 * @precision: Precision specific.
 *
 * @size: Size identifier
 * Return: Number of all characters printed.
 */
int intPrints(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	int is_negative = 0;
	long int m = va_arg(types, long int);
	unsigned long int num;

	m = size_num_allocate(m, size);

	if (m == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)m;

	if (m < 0)
	{
		num = (unsigned long int)((-1) * m);
		is_negative = 1;
	}

	while (num > 0)
	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (numWrite(is_negative, j, buffer, flags, width, precision, size));
}

/************************* PRINT BINARY *************************/
/**
 * binaryPrints - Prints an unsgnd number.
 *
 * @types: All arguments
 * @buffer: Buffer array that handles print.
 *
 * @flags: This Calculates all active flags
 * @width: fetches width
 *
 * @precision: Precision specific
 * @size: Size specific
 *
 * Return: Returns the Numbers of all char printed.
 */
int binaryPrints(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int x, y, j, sum;
	unsigned int c[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	x = va_arg(types, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	c[0] = x / y;
	for (j = 1; j < 32; j++)
	{
		y /= 2;
		c[j] = (x / y) % 2;
	}
	for (j = 0, sum = 0, count = 0; j < 32; j++)
	{
		sum += c[j];
		if (sum || j == 31)
		{
			char s = '0' + c[j];

			write(1, &s, 1);
			count++;
		}
	}
	return (count);
}
