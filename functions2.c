#include "main.h"
/**
 * print_pointer - Program that prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision:  specification
 * @size:  specifier
 * Return: Number of characters printed.
 */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char extra_c = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, length = 2, pad_start = 1; /* length=2, for '0x' */
	unsigned long num_address;
	char map_to[] = "0123456789abcdef";
	void *address = va_arg(types, void *);

	UNUSED(width);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));

	buffer[BUFF_SIZE - 1] = '\0';
	UNUSED(precision);

	num_address = (unsigned long)address;

	while (num_address > 0)
	{
		buffer[ind--] = map_to[num_address % 16];
		num_address /= 16;
		length++;
	}

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		pad = '0';
	if (flags & F_PLUS)
		extra_c = '+', length++;
	else if (flags & F_SPACE)
		extra_c = ' ', length++;

	ind++;

	/*return (write(1, &buffer[j], BUFF_SIZE - j - 1));*/
	return (write_pointer(buffer, ind, length,
		width, flags, pad, extra_c, pad_start));
}

/**
 * print_non_pr - Program that prints ascii codes in hexa of non printable chars
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision:  specification
 * @size:  specifier
 * Return: Number of characters printed
 */
int print_non_pr(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int j = 0, offset = 0;
	char *str = va_arg(types, char *);

	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[j] != '\0')
	{
		if (is_printable(str[j))
			buffer[j + offset] = str[j];
		else
			offset += append_hexa_code(str[j], buffer, j + offset);

		j++;
	}

	buffer[j + offset] = '\0';

	return (write(1, buffer, j + offset));
}

/**
 * print_rev - Program that prints reverse string.
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision:  specification
 * @size:  specifier
 * Return: Numbers of characters printed
 */

int print_rev(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char *str;
	int j, count = 0;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(size);

	str = va_arg(types, char *);

	if (str == NULL)
	{
		UNUSED(precision);

		str = ")Null(";
	}
	for (j= 0; str[j]; j++)
		;

	for ( j = j- 1; j >= 0; j--)
	{
		char z = str[j];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13- Program that print a string in rot13.
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision:  specification
 * @size: specifier
 * Return: Numbers of characters printed
 */
int print_rot13(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	char x;
	char *str;
	unsigned int j, q;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(types, char *);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[j]; j++)
	{
		for (q = 0; in[q]; q++)
		{
			if (in[q] == str[j])
			{
				x = out[q];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[q])
		{
			x = str[j];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
