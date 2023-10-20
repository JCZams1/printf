#include "main.h"

/**
 * fetch_flags - This Calculates all active flags.
 *
 * @format: String format.
 *
 * @a: takes in a value.
 * Return: Returns Flags:
 */
int fetch_flags(const char *format, int *a)
{
	/* - + 0 # ' ' */
	/* 1 2 4 8  16 */
	int d, curr_a;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (curr_a = *a + 1; format[curr_a] != '\0'; curr_a++)
	{
		for (d = 0; FLAGS_CH[d] != '\0'; d++)
			if (format[curr_a] == FLAGS_CH[d])
			{
				flags |= FLAGS_ARR[d];
				break;
			}

		if (FLAGS_CH[d] == 0)
			break;
	}

	*a = curr_a - 1;

	return (flags);
}
