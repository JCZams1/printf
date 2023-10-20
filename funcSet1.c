#include "main.h"

/***** Print Unsigned Number ******/
/**
 * unsignedNum - Prints an unsigned number
 *
 * @list: Arguments
 *
 * @buffer: Buffer to print
 *
 * @calc: Calculates flags
 *
 * @width: calculate width
 *
 * @precSpec: Precision
 *
 * @size: Size specifier
 *
 * Return: Number of chars printed.
 */
int unsignedNum(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);

	num = size_allocate_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (writeNum_unsgnd(0, i, buffer, calc, width, precSpec, size));
}

/***** Print Unsigned Number (octal) *****/
/**
 * num_octal - Prints an unsigned number in octal
 *
 * @list: Arguments
 *
 * @buffer: Buffer to print
 *
 * @calc:  Calculates flags
 *
 * @width: calculate width
 *
 * @precSpec: Precision
 *
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int num_octal(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int val = num;

	UNUSED(width);

	num = size_allocate_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
	buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (calc & F_HASH && val != 0)
		buffer[i--] = '0';

	i++;

	return (writeNum_unsgnd(0, i, buffer, calc, width, precSpec, size));
}

/***** Print Unsigned Number (Hexadecimal) *****/
/**
 * num_hexa - Prints an unsigned number in hexadecimal
 *
 * @list: Arguments
 *
 * @buffer: Buffer to print
 *
 * @calc:  Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int num_hexa(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	return (hexaUL(list, "0123456789abcdef", buffer,
		calc, 'x', width, precSpec, size));
}

/****** Print Unsigned Number - Upper hexadecimal ******/
/**
 * hexa_upperNum - Prints an unsigned number in upper hexadecimal
 *
 * @list: Arguments
 *
 * @buffer: Buffer to print
 *
 * @calc:  Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size specifier
 *
 * Return: Number of chars printed
 */
int hexa_upperNum(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	return (hexaUL(list, "0123456789ABCDEF", buffer,
		calc, 'X', width, precSpec, size));
}

/***** Print Upper/Lower Hexadecimal *****/
/**
 * hexaUL - Prints a hexadecimal number in lower or upper
 *
 * @list: Arguments
 *
 * @map_to: Array of values to map the number to
 *
 * @buffer: Buffer array to handle print
 *
 * @calc:  Calculates active flags
 *
 * @calc_ch: Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size
 *
 * Return: Number of chars printed
 */
int hexaUL(va_list list, char map_to[], char buffer[],
	int calc, char calc_ch, int width, int precSpec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(list, unsigned long int);
	unsigned long int val = num;

	UNUSED(width);

	num = size_allocate_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (calc & F_HASH && val != 0)
	{
		buffer[i--] = calc_ch;
		buffer[i--] = '0';
	}

	i++;

	return (writeNum_unsgnd(0, i, buffer, calc, width, precSpec, size));
}
