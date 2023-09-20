#include "main.h"

/**
 * _printf_ch - Prints a char
 * @w: width
 * @size: size
 * @type: List a of arguments
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @prec: Precision
 *
 * Return: Number of chars that is printed
 */
int _printf_ch(va_list type, int w, int size, char buff[],
	int flag, int prec)
{
	char ch = va_arg(type, int);

<<<<<<< HEAD
	return (handle_string(c, buffer, flags, width, precision, size));
=======
	return (handle_write_char(ch, buff, flag, w, prec, size));
>>>>>>> 07938260ac1d084693f82969be1882ea60179c0a
}
/**
 * _printf_str - Prints a string
 * @w: width
 * @type: List of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @size: Size
 * @prec: Precision
 *
 * Return: Number of char that is printed
 */
int _printf_str(va_list type, int w, char buff[],
	int flag, int prec, int size)
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
 * Return: Number of chars printed
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
 * Return: Number of chars printed
 */
int _printf_integer(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int d = BUFF_SIZE - 2;
	int negative = 0;
	long int i = va_arg(type, long int);
	unsigned long int n;

	i = convert_size_number(i, size);

	if (i == 0)
		buff[d--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	n = (unsigned long int)i;
	if (i < 0)
	{
		n = (unsigned long int)((-1) * i);
		negative = 1;
	}
	while (n > 0)
	{
		buff[d--] = (n % 10) + '0';
		n /= 10;
	}

	d++;

<<<<<<< HEAD
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
=======
	return (write_number(negative, d, buff, flag, w, prec, size));
>>>>>>> 07938260ac1d084693f82969be1882ea60179c0a
}
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
