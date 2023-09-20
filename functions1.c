#include "main.h"

/**
 * _printf_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int _printf_unsigned(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(types, unsigned long int);

	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
	}
	i++;
	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}

/**
 * _printf_oct - Prints octal unsigned number
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: Number of printed char
 */
int _printf_oct(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_num = number;
	UNUSED(w);
	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buff[i--] = (number % 8) + '0';
		number /= 8;
	}
	if (flag & F_HASH && init_num != 0)
		buff[i--] = '0';
	i++;
	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}
/**
 * _printf_hexadecimal - Print unsigned hexadecimal number
 * @type: Lista of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
 */
int _printf_hexadecimal(va_list type, char buff[], int flag, int w, int prec, int size)
{
<<<<<<< HEAD
	return (_printf_hexa(type, "0123456789abcdef", buff, flag, 'x', w, prec, size));
=======
	return (print_hexa(types, "0123456789abcdef", buffer, flags, 'x', width, prec, size));
>>>>>>> 0061ef7b87d284a3d821d34f2e7d28164da72c8a
}

/**
 * _printf_hexa_upper - Prints unsigned hexadecimal number
 * @type: Lista of arguments
 * @buff: array
 * @flag:  Calculates active flags
 * @w: get width
 * @prec: Precision specification
 * @size: Size specifier
 * Return: printed char
 */
int _printf_hexa_upper(va_list type, char buff[], int flag, int w, int prec, int size)
{
<<<<<<< HEAD
	return (_printf_hexa(type, "0123456789ABCDEF", buff, flag, 'X', w, prec, size));
=======
<<<<<<< HEAD
<<<<<<< HEAD
	return (_printf_hexa(type, "0123456789ABCDEF", buff, flag, 'X', w, prec, size));
=======
=======
	return (print_hexa(type, "0123456789ABCDEF", buffer, flags, 'X', width, precision, size));
}
>>>>>>> 0061ef7b87d284a3d821d34f2e7d28164da72c8a

	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
>>>>>>> 04bf744f3efaa4963c697d367cf8f42a860ebe5d
>>>>>>> 07938260ac1d084693f82969be1882ea60179c0a
}


/**
 * _printf_hexa - print hexadecimal number in uppercase or lower
 * @type: Lista of arguments
 * @map: Array
 * @buff: Buffer array to handle print
 * @flag:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: printed char
 */
int _printf_hexa(va_list type, char map[], char buff[], int flag char flag_ch, int w, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buff[i--] = '0';

	buff[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map[num % 16];
		num /= 16;
	}

	if (flag & F_HASH && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}
