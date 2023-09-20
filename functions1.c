#include "main.h"

/**
 * print_unsigned - Program that prints an unsigned number
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: specification
 * @size: specifier
 * Return: Number of characters printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);

<<<<<<< HEAD
	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
=======
	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
>>>>>>> 04bf744f3efaa4963c697d367cf8f42a860ebe5d
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * _printf_oct - Program that prints octal unsigned number
 * @type: List a of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: Number of characters printed
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
 * _printf_unsigned_hexa - Program that prints int hexadecimal unsigned number
 * @type: List a of arguments
 * @buff: array
 * @flag: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: number of char that is printed
 */
int _printf_unsigned_hexa(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	return (_printf_hexa(type, "0123456789abcdef", buff, flag, 'x', w, prec, size));
}

/**
 * _printf_hexa_upper - prints unsigned hexadecimal in uppercase
=======
 * print_octal - Prints an unsigned number in octal notation
>>>>>>> 04bf744f3efaa4963c697d367cf8f42a860ebe5d
 * @types: Lista of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: specification
 * @size:  specifier
 * Return: Number of characters printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
<<<<<<< HEAD
	return (_printf_hexa(type, "0123456789ABCDEF", buff, flag, 'X', w, prec, size));
=======

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
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: specification
 * @size: specifier
 * Return: Number of characters printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
}

/**
 * print_hexa_upper - Program that prints ints an unsigned number in upper hexadecimal notation
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of characters printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Program that prints ints a hexadecimal number in lower or upper
 * @types: List a of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision:  specification
 * @size:  specifier
 * @size:  specification
 * Return: Number of characters printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
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
		buffer[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_cha;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
