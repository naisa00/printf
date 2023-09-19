#include "main.h"
/**
 * print - check if char is printable
 * @ch: char
 * 
 * Return: 1 or 0;
 */
int print(char ch)
{
	if (ch >= 32 && ch < 127)
	{
		return (1);
	}
	return (0);
}
/**
 * append_ascci - sign ascci in hexadecimal code 
 * @buff: array
 * @ind: index
 * @asci: assci code
 *
 * Return: 3
 */
int append_ascci(char asci, char buff[], int ind)
{
	char map[] = "0123456789ABCDEF";

	if (asci < 0)
	{
		asci *= -1;
	}

	buff[ind++] = '\\';
	buff[ind++] = 'x';
	buff[ind++] = map[asci/16];
	buff[ind] = map[asci % 16] ;
	return (3);
}

/**
 * is_digit - check if a char is a digit
 * @ch: char
 *
 * Return: 1 or 0
 */
int is_digit(char ch)
{
	if (ch > '0' && ch <= '9')
	{
		return (1);
	}
	return (0);
}

/**
 * convert_size_number - sign number to the size
 * @num: number to be signed
 * @size: number including the type to be signed
 *
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
 * convert_size_unsgnd - signed a number to the size
 * @num: number to be signed
 * @size: number including the type to be signed
 *
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
