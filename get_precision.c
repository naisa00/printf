#include "main.h"

/**
 * get_precision - Calculates the precision for printing
 * @format: Formatted string in which to print the arguments
 * @i: List of arguments to be printed.
 * @list: list of arguments.
 *
 * Return: Precision.
 */
int get_precision(const char *format, int *i, va_list list)
{
	int n = *i + 1;
	int precision = -1;

	if (format[n] != '.')
		return (precision);

	precision = 0;

	for (n += 1; format[n] != '\0'; n++)
	{
		if (is_digit(format[n]))
		{
			precision *= 10;
			precision += format[n] - '0';
		}
		else if (format[n] == '*')
		{
			n++;
			precision = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*i = n - 1;

	return (precision);
}
