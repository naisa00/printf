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
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	num = convert_size_unsgnd(num, size);
	if (num == 0)
		buffer [j--] = '0';
	buffer [BUFF_SIZE - 1] = '\0';
	while (num > 0)

	{
		buffer[j--] = (num % 10) + '0';
		num /= 10;
	}

	j++;

	return (write_unsgnd(0, j, buffer, flags, width, precision, size));
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
	int j = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(w);
	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[j--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buff[j--] = (number % 8) + '0';
		number /= 8;
	}
	if (flag & F_HASH && init_num != 0)
		buff[j--] = '0';
	j++;
	return (write_unsgnd(0, j, buff, flag, w, prec, size));
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
int _printf_unsigned_hexa(va_list type, char buffer[],
	int flags, int width, int prec, int size)
{
	return (_printf_hexa(type, "0123456789abcdef", buffer, flags, 'x', width, prec, size));
}

/**
 * printf_hexa_upper - program that prints unsigned hexadecimal in uppercase
 * @types: List a of arguments
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @width: get width
 *
 * @precision: specification
 * @size:  specifier
 * Return: Number of characters printed

*/

int printf_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (printf_hexa(type, "0123456789ABCDEF", buffer, flags, 'X', width, prec, size));
}


/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal number
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
 * printf_hexa - Program that prints ints a hexadecimal number in lower or upper
 * @types: List a of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Handle print for buffer array
 * @flags:  Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: percision specification
 * @size:  specifier
 * @size: size specification
 * Return: Number of characters printed
 */
int printf_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int j = BUFF_SIZE - 2;
	unsigned long int num = va_arg(types, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(width);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[j--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[j--] = map_to[num % 16];
		num /= 16;
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[j--] = flag_ch;
		buffer[j--] = '0';
	}

	j++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
