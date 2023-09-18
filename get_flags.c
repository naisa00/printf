#include "main.h"
/**
 * get_flags - calculate active flags
 * @format: formatted string to print arguments
 * @i: take a parameter.
 * Return: flags
 */
int get_flags(const char *format, int *i)
{
	/* - + 0 # ' ' */
       /* 1 2 4 8 16 */	
	int d, n;
	int flags = 0;
	const char FLAGS_CH[] = {'-', '+', '0', '#', ' ', '\0'};
	const int FLAGS_ARR[] = {F_MINUS, F_PLUS, F_ZERO, F_HASH, F_SPACE, 0};

	for (n = *i + 1; format[n] != '\0'; n++)
	{
		for (d = 0; FLAGS_CH[d] != '\0'; d++)
			if (format[n] == FLAGS_CH[d])
			{
				flags != FLAGS_ARR[d];
				break;
			}
		if (FLAGS_CH[d] == 0)
			break;
	}
	*i = n - 1;

	return (flags);
}
