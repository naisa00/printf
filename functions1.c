#include "main.h"

/**
 * print_unsigned - Prints an unsigned number
 * @types: List a of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed.
 */
int print_unsigned(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
<<<<<<< HEAD
	unsigned long int num = va_arg(types, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';

	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
=======
	unsigned long int number = va_arg(type, unsigned long int);

	n = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (number > 0)
	{
		buff[i--] = (number % 10) + '0';
		number /= 10;
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_octal - Prints an unsigned number in octal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
<<<<<<< HEAD
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
=======
	unsigned long int number = va_arg(type, unsigned long int);
	unsigned long int init_num = number;

	UNUSED(w);
	number = convert_size_unsgnd(number, size);
	if (number == 0)
		buff[i--] = '0';
	buff[BUFF_SIZE - 1] = '\0';
	while (n > 0)
	{
		buff[i--] = (number % 8) + '0';
		number /= 8;
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
	}

	if (flags & F_HASH && init_num != 0)
		buffer[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}

/**
 * print_hexadecimal - Prints an unsigned number in hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
<<<<<<< HEAD
	return (print_hexa(types, "0123456789abcdef", buffer,
		flags, 'x', width, precision, size));
=======
	return (_printf_hexa(type, "0123456789abcdef", buff,
		flag, 'x', w, prec, size));
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
}

/**
 * print_hexa_upper - Prints an unsigned number in upper hexadecimal notation
 * @types: Lista of arguments
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * Return: Number of chars printed
 */
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	return (print_hexa(types, "0123456789ABCDEF", buffer,
		flags, 'X', width, precision, size));
}

/**
 * print_hexa - Prints a hexadecimal number in lower or upper
 * @types: Lista of arguments
 * @map_to: Array of values to map the number to
 * @buffer: Buffer array to handle print
 * @flags: Calculates active flags
 * @flag_ch: Calculates active flags
 * @width: get width
 * @precision: Precision specification
 * @size: Size specifier
 * @size: Size specification
 * Return: Number of chars printed
 */
int print_hexa(va_list types, char map_to[], char buffer[],
	int flags, char flag_ch, int width, int precision, int size)
{
	int i = BUFF_SIZE - 2;
<<<<<<< HEAD
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
=======
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
>>>>>>> 739ac1f932a073ec5c9ebdd59c6a3769d4e7f352
	}

	if (flags & F_HASH && init_num != 0)
	{
		buffer[i--] = flag_ch;
		buffer[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buffer, flags, width, precision, size));
}
