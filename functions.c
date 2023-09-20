#include "main.h"

/**
 * _printf_char - Prints a char
 * @w: width
 * @size: size
 * @type: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @prec: Precision
 *
 * Return: Number of chars that is printed
 */
int _printf_char(va_list type, int w, int size, char buff[], int flag, int prec)
{
	char ch = va_arg(type, int);

	return (handle_string(c, buffer, flags, width, precision, size));
}
/**
 * _printf_string - Prints a string
 * @w: width
 * @type: List of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @size: Size
 * @prec: Precision
 *
 * Return: printed char
 */
int _printf_string(va_list type, int w, char buff[], int flag, int prec, int size)
{
	int l = 0, i;
	char *arr = va_arg(type, char *);

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);
	if (arr == NULL)
	{
		arr = "(null)";
		if (prec >= 6)
		{
			arr = " ";
		}
	}

	while (arr[l] != '\0')
		l++;

	if (prec >= 0 && prec < l)
		l = prec;

	if (w > l)
	{
		if (flag & F_MINUS)
		{
			write(1, &arr[0], l);
			for (i = w - l; i > 0; i--)
				write(1, " ", 1);
			return (w);
		}
		else
		{
			for (i = w - l; i > 0; i--)
				write(1, " ", 1);
			write(1, &arr[0], l);
			return (w);
		}
	}

	return (write(1, arr, l));
}

/**
 * _printf_percent - Prints a sign of percent
 * @type: Lista of arguments
 * @w: width
 * @size: size
 * @buff: array
 * @prec: precision
 * @flag:  Calculates active flags
 *
 * Return: printed char
 */
int _printf_percent(va_list type, int w, int size, char buff[], int prec, int flag)
{
	UNUSED(type);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);
	return (write(1, "%%", 1));
}

/**
 * _printf_integer - Print integer
 * @type: Lista of arguments
 * @buff: array
 * @flag:  Calculates active flags
 * @w: width.
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
 */
int _printf_integer(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int d = BUFF_SIZE - 2;
	int negative = 0;
	long int i = va_arg(type, long int);
	unsigned long int n;

	num = convert_size_number(num, size);

	if (num == 0)
		buff[d--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)num;
	if (num < 0)
	{
		n = (unsigned long int)((-1) * num);
		negative = 1;
	}
	while (num > 0)
	{
		buff[d--] = (n % 10) + '0';
		n /= 10;
	}

	d++;
	num++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));

/**
 * _printf_binary - Prints a binary number
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width.
 * @prec: Precision
 * @size: Size
 *
 * Return: the number of char that is printed
 */
int _printf_binary(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	unsigned int x, y, z, add;
	unsigned int i[32];
	int count;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	x= va_arg(type, unsigned int);
	y = 2147483648; /* (2 ^ 31) */
	i[0] = x / y;
	for (z = 1; z < 32; z++)
	{
		y /= 2;
		i[z] = (x / y) % 2;
	}
	for (z = 0, add = 0, count = 0; z < 32; z++)
	{
		add += i[z];
		if (add || z == 31)
		{
			char a = '0' + i[z];

			write(1, &a, 1);
			count++;
		}
	}
	return (count);
}
