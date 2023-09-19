#include "main.h"
/**
 * handle_print - Prints argument
 * @str: Formatted string
 * @list: List of arguments
 * @ptr: ind
 * @buff: array
 * @flag: Calculates active flags
 * @w: width.
 * @prec: Precision
 * @size: Size
 * Return: 1 or 2;
 */
int handle_print(const char *str, int *ptr, va_list list, char buff[], int flag, int w, int prec, int size)
{
	int i, unknow_length = 0, _printf_char = -1;
	fmt_t fmt_types[] = {
		{'c', print_char}, {'s', print_string}, {'%', print_percent},
		{'i', print_int}, {'d', print_int}, {'b', print_binary},
		{'u', print_unsigned}, {'o', print_octal}, {'x', print_hexadecimal},
		{'X', print_hexa_upper}, {'p', print_pointer}, {'S', print_non_printable},
		{'r', print_reverse}, {'R', print_rot13string}, {'\0', NULL}
	};
	for (i = 0; fmt_types[i].fmt != '\0'; i++)
		if (str[*ptr] == fmt_types[i].fmt)
			return (fmt_types[i].fn(list, buff, flag, w, prec, size));
	if (fmt_types[i].fmt == '\0')
	{
		if (str[*ptr] == '\0')
			return (-1);
		unknow_length += write(1, "%%", 1);
		if (str[*ptr - 1] == ' ')
			unknow_length += write(1, " ", 1);
		else if (w)
		{
			--(*ptr);
			while (str[*ptr] != ' ' && str[*ptr] != '%')
				--(*ptr);
			if (str[*ptr] == ' ')
				--(*ptr);
			return (1);
		}
		unknow_length += write(1, &str[*ptr], 1);
		return (unknow_length);
	}
	return (_printf_char);
}
