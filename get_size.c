
#include "main.h"
/**
 * get_size - Calculates the size
 * @ptr: Formatted string
 * @i: List of arguments
 *
 * Return: Precision.
 */
int get_size(const char *ptr, int *i)
{
	int d = *i + 1;
	int size = 0;

	if (ptr[d] == 'l')
		size = S_LONG;
	else if (ptr[d] == 'h')
		size = S_SHORT;
	if (size == 0)
		*i = d - 1;
	else
		*i = d;

	return (size);
}
