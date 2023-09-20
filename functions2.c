#include "main.h"

/**
 * _printf_ptr - prints value of pointer
 * @type: List a of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: Number of printed char
 */
int _printf_ptr(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	char extra_ch = 0, pad = ' ';
	int ind = BUFF_SIZE - 2, l = 2, pad_start = 1;
	unsigned long number_addres;
	char map[] = "0123456789abcdef";
	void *address = va_arg(type, void *);

	UNUSED(w);
	UNUSED(size);

	if (address == NULL)
		return (write(1, "(nil)", 5));
	buff[BUFF_SIZE - 1] = '\0';
	UNUSED(prec);
	number_addres = (unsigned long)address;

	while (number_addres > 0)
	{
		buff[ind--] = map[number_addres % 16];
		number_addres /= 16;
		l++;
	}
	if ((flag & F_ZERO) && !(flag & F_MINUS))
		pad = '0';
	if (flag & F_PLUS)
		extra_ch = '+', l++;
	else if (flag & F_SPACE)
		extra_ch = ' ', l++;

	ind++;
	return (write_ptr(buff, ind, l, w, flag, pad, extra_ch, pad_start));
}
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
		if (printable(arr[i]))
			buff[i + off] = arr[i];
		else
			off += append_ascci(arr[i], buff, i + off);
		i++;
	}
	buff[i + off] = '\0';
	return (write(1, buff, i + off));
}
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
 */
int print_rever(va_list type, char buff[], int flag, int w, int prec, int size)
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
 * _printf_rot13string - Print a string in rot13.
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
 */
int _printf_rot13string(va_list type, char buff[], int flag, int w, int prec, int size)
{
	char x;
	char *arr;
	unsigned int i, n;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	arr = va_arg(type, char *);
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
			if (in[n] == arr[i])
			{
				x = out[n];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[n])
		{
			x = arr[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}
