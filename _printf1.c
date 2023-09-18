#include "main.h"
/**
 * _printf - printf function
 * @format: format
 * Return: printed chars
 */
int _printf(const char *format, ...)
{
	va_list args;
	va_start(args, format);

	int num;
	char letter, *str;

	int count = _printf("Number: %d\nLetter: %c\nString: %s\n", num, letter, str);
	count = vprintf(format, args);

	va_end(args);

	return (count);
}
