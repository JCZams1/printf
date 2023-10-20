#include "main.h"

/**
 * printableChar - determines the printability of a char.
 *
 * @x: The char to be determined.
 *
 * Return: Returns 1 if x is printable, 0 if not
 */
int printableChar(char x)
{
	if (x >= 32 && x < 127)
		return (1);

	return (0);
}

/**
 * hexacodeAppend - Appends ascii code into hexadecimal code for buffering.
 *
 * @buffer: a buffer Array of chars.
 * @a: Point at which appending starts.
 *
 * @ascii_code: All ASSCI CODES.
 * Return: Always returns 3
 */
int hexacodeAppend(char ascii_code, char buffer[], int a)
{
	char map_to[] = "0123456789ABCDEF";
	/* The hexa format code is always 2 digits long */
	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[a++] = '\\';
	buffer[a++] = 'x';

	buffer[a++] = map_to[ascii_code / 16];
	buffer[a] = map_to[ascii_code % 16];

	return (3);
}

/**
 * digit_det - determines if a char is a digit.
 *
 * @x: Character to be determined
 *
 * Return: Returns 1 if x is a digit, 0 if not
 */
int digit_det(char x)
{
	if (x >= '0' && x <= '9')
		return (1);

	return (0);
}

/**
 * size_num_allocate - Assign a number to the size specified
 *
 * @num: Number to be assigned.
 * @size: Number showing the type to be allocated.
 *
 * Return: Returns the allocated value of number
 */
long int size_num_allocate(long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((short)num);

	return ((int)num);
}

/**
 * size_allocate_unsgnd - Allocates a number to the specified size.
 *
 * @num: A Number to be allocated
 * @size: Size of the type to be allocated
 *
 * Return: Returns allocated value of number
 */
long int size_allocate_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
		return (num);
	else if (size == S_SHORT)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
