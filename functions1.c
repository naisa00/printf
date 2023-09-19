#include "main.h"
/**
 * _printf_unsigned - Prints unsigned number
 * @type: List a of arguments
 * @buff: array
 * @flag:  Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: number of printed char
 */

int _printf_unsigned(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int number = va_arg(type, unsigned long int);

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
 * _printf_unsigned_hexa - Print hexadecimal unsigned number
 * @type: Lista of arguments
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
 * @types: Lista of arguments
 * @buff: array
 * @flag:  Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: the printed char
 */
int _printf_hexa_upper(va_list type, char buff[],
	int flag, int w, int prec, int size)
{
	return (_printf_hexa(type, "0123456789ABCDEF", buff, flag, 'X', w, prec, size));
}

/**
 * _printf_hexa - Prints hexadecimal in uppercase or lowercase
 * @type: Lista of arguments
 * @map: array
 * @buff: array
 * @flag:  Calculates active flags
 * @flag_char: Calculates active flags
 * @w: width
 * @prec: Precision
 * @size: Size
 *
 * Return: Number of chars printed

 */
int _printf_hexa(va_list type, char map[], char buff[],
	int flag, char flag_char, int w, int prec, int size)
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
		buff[i--] = map[number % 16];
		number /= 16;
	}
	if (flag & F_HASH && init_num != 0)
	{
		buff[i--] = flag_char;
		buff[i--] = '0';
	}
	i++;
        return (write_unsgnd(0, i, buff, flag, w, prec, size));
}
