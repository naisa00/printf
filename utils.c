#include "main.h"
/**
 * is_printable - check if char is printable
 * @c: char
 * Return: 1 or 0;
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
	{
		return (1);
	}
	return (0);
}
/**
 * append_hexa_code - sign ascci in hexadecimal code in buffer
 * @buffer: array
 * @i: index
 * @ascii_code: assci code
 * Return: 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
	{
		ascii_code *= -1;
	}

	buffer[i++] = '\\';
	buffer[i++] = 'x';
	buffer[i++] = map_to[ascii_code/16];
	buffer[i] = map_to[ascii_code % 16] ;

	return (3);
}

/**
 * is_digit - check if a char is a digit
 * @c: char
 * Return: 1 or 0
 */
int is_digit(char c)
{
	if (c > '0' && c <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - sign number to the specified size
 * @num: number to be signed
 * @size: number including the type to be signed
 * Return: signed value of num
 */
long int convert_size_number(long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((short)num);
	}
	return ((int)num);
}

/**
 * convert_size_unsgnd - signed a number to the specified size
 * @num: number to be signed
 * @size: number including the type to be signed
 * Return: signed value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == S_LONG)
	{
		return (num);
	}
	else if (size == S_SHORT)
	{
		return ((unsigned short)num);
	}
	return ((unsigned int)num);
}
