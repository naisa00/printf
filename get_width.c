#include "main.h"
/**
 * get_width - calculate width
 * @ptr: print argument
 * @i: pointer
 * @list: list the arguments
 *
 * Return: width
 */
int get_width(const char *ptr, int *pointer, va_list list)
{
	int d;
	int w = 0;

	for (d = *pointer + 1; ptr[d] != '\0'; d++)
	{
		if (is_digit(ptr[d]))
		{
			w *= 10;
			w += ptr[d] - '0';
		}
		else if (ptr[d] == '*')
		{
			d++;
			w = va_arg(list, int);
			break;
		}
		else
			break;
	}
	*pointer = d - 1;
	return (w);
}
