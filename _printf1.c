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

	 int count = vprintf(stdout, format, args);
	 count = _printf("Number: %d\nLetter: %c\nString: %s\n", num, letter, str);

	va_end(args);

	return (count);
}
