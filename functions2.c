#include "main.h"

/**
<<<<<<< HEAD
 * print_pointer - Prints the value of a pointer variable
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
=======
 * _printf_ptr - prints value of pointer
 * @type: List a of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: Number of printed char
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
 */
int _printf_ptr(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	char extra_ch = 0, padd = ' ';
	int ind = BUFF_SIZE - 2, l = 2, padd_start = 1;
	unsigned long number_addres;
	char map[] = "0123456789abcdef";
	void *address = va_arg(type, void *);

	UNUSED(w);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);
	number_address = (unsigned long)address;

	while (number_address > 0)
	{
		buff[ind--] = map[number_address % 16];
		number_address /= 16;
		l++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		padd = '0';
	if (flag & F_PLUS)
		extra_ch = '+', l++;
	else if (flag & F_SPACE)
		extra_ch = ' ', l++;

	ind++;
	return (write_pointer(buff, ind, l,
		w, flag, padd, extra_ch, padd_start));
}
<<<<<<< HEAD

/**
 * print_non_printable - Prints ascii codes in hexa of non printable chars
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
=======
/**
 * _printf_ascii - Prints ascii codes
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
 */
int _printf_ascii(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int i = 0, off = 0;
	char *arr = va_arg(type, char *);

	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);
	if (arr == NULL)
		return (write(1, "(null)", 6));
	while (arr[i] != '\0')
	{
		if (is_printable(arr[i]))
			buff[i + off] = arr[i];
		else
			off += append_hexa_code(arr[i], buff, i + off);
		i++;
	}
	buff[i + off] = '\0';
	return (write(1, buff, i + off));
}
<<<<<<< HEAD

/**
 * print_reverse - Prints reverse string.
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
=======
/**
 * _printf_rever - Prints reverse string.
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
 */
int print_rever(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	char *arr;
	int i, counter = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(size);
	arr = va_arg(type, char *);
	if (arr == NULL)
	{
		UNUSED(prec);
		arr = ")Null(";
	}
	for (i = 0; arr[i]; i++)
		;
	for (i = i - 1; i >= 0; i--)
	{
		char c = arr[i];

		write(1, &c, 1);
		counter++;
	}
	return (counter);
}
/**
 * print_rot13string - Print a string in rot13.
<<<<<<< HEAD
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Numbers of chars printed
=======
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
 */
int print_rot13string(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	char x;
	char *arr;
	unsigned int i, n;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	arr = va_arg(types, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);
	if (arr == NULL)
		arr = "(AHYY)";
	for (i = 0; arr[i]; i++)
	{
		for (n = 0; in[n]; n++)
		{
			if (in_[n] == arr[i])
			{
				x = out_[n];
				write(1, &x, 1);
				counter++;
				break;
			}
		}
		if (!in[n])
		{
			x = arr[i];
			write(1, &x, 1);
			counter++;
		}
	}
	return (counter);
}
