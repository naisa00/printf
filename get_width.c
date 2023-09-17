#include "main.h"
/**
 * get_width - calculate width
 * @format: print argument
 * @i: list of argument to primt
 * @list: list the arguments
 * Return: width
 */
int get_width(const char *format, int *i, va_list lit)
{
	int d;
	int w = 0;

	for (d = *i + 1; format[d] != '\0'; d++)
	{
		if (is_digit(format[d]))
		{
			w *= 10;
			w += format[d] - '0';
		}
		else if (format[d] == '*')
		{
			d++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*i = d - 1;
	return (width);
}
