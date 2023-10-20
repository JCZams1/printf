#include "main.h"

/****** Pointer Function ******/
/**
 * pointerFunc - Prints pointer variable
 *
 * @list: Arguments
 *
 * @buffer: Buffer
 *
 * @calc:  Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size
 *
 * Return: Number of chars printed.
 */
int pointerFunc(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	char moreC = 0, val = ' ';
	int index = BUFF_SIZE - 2, len = 2, beg_val = 1; /* length=2, for '0x' */
	unsigned long addrNum;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(list, void *);

	UNUSED(width);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precSpec);

	addrNum = (unsigned long)addrs;

	while (addrNum > 0)
	{
		buffer[index--] = map_to[addrNum % 16];
		addrNum /= 16;
		len++;
	}

	if ((calc & F_ZERO) && !(calc & F_MINUS))
		val = '0';
	if (calc & F_PLUS)
		moreC = '+', len++;
	else if (calc & F_SPACE)
		moreC = ' ', len++;

	index++;

	/*return (write(1, &buffer[i], BUFF_SIZE - i - 1));*/
	return (pointWriter(buffer, index, len,
		width, calc, val, moreC, beg_val));
}

/****** Print ASCII Codes NON PRINTABLE ******/
/**
 * nonPrintableAscii - Prints ascii codes in hexa of non printable chars
 *
 * @list: Arguments
 *
 * @buffer: Buffer
 *
 * @calc:  Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size
 *
 * Return: chars printed
 */
int nonPrintableAscii(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	int i = 0, diff = 0;
	char *str = va_arg(list, char *);

	UNUSED(calc);
	UNUSED(width);
	UNUSED(precSpec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (printableChar(str[i]))
			buffer[i + diff] = str[i];
		else
			diff += hexacodeAppend(str[i], buffer, i + diff);

		i++;
	}

	buffer[i + diff] = '\0';

	return (write(1, buffer, i + diff));
}

/****** Print Reverse String ******/
/**
 * str_reverse - Prints reverse string.
 *
 * @list: Arguments
 *
 * @buffer: Buffer array to handle print
 *
 * @calc:  Calculate flags
 *
 * @width: calculate width
 *
 * @precSpec: Precision
 *
 * @size: Size
 *
 * Return: chars printed
 */

int str_reverse(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	char *str;
	int i, counter = 0;

	UNUSED(buffer);
	UNUSED(calc);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(list, char *);

	if (str == NULL)
	{
		UNUSED(precSpec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		counter++;
	}
	return (counter);
}
/****** Print String in Rot13 *****/
/**
 * rot13String - Print a string in rot13.
 *
 * @list: arguments
 *
 * @buffer: Buffer
 *
 * @calc:  Calculates active flags
 *
 * @width: get width
 *
 * @precSpec: Precision
 *
 * @size: Size
 *
 * Return: Numbers of chars printed
 */
int rot13String(va_list list, char buffer[],
	int calc, int width, int precSpec, int size)
{
	char r13;
	char *str;
	unsigned int i, j;
	int counter = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(list, char *);
	UNUSED(buffer);
	UNUSED(calc);
	UNUSED(width);
	UNUSED(precSpec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				r13 = out[j];
				write(1, &r13, 1);
				counter++;
				break;
			}
		}
		if (!in[j])
		{
			r13 = str[i];
			write(1, &r13, 1);
			counter++;
		}
	}
	return (counter);
}
