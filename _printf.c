#include "main.h"

void _printf_buff(char buff[], int *buffind);

/**
 * _printf - Print function
 * @format: format.
 *
 * Return: the char that is printed
 */
int _printf(const char *format, ...)
{
	int i, print = 0, _printf_chars = 0;
	int flag, w, prec, size, buffind = 0;
	va_list list;
	char buff[BUFF_SIZE];

	if (format == NULL)
		return (-1);
	va_start(list, format);
	for (i = 0; format && format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buff[buffind++] = format[i];
			if (buffind == BUFF_SIZE)
				_printf_buff(buff, &buffind);
			_printf_chars++;
		}
		else
		{
			_printf_buff(buff, &buffind);
			flag = get_flags(format, &i);
			w = get_width(format, &i, list);
			prec = get_precision(format, &i, list);
			size = get_size(format, &i);
			++i;
			print = handle_print(format, &i, list, buff,
				flag, w, prec, size);
			if (print == -1)
				return (-1);
			_printf_chars += print;
		}
	}

	_printf_buff(buff, &buffind);
	va_end(list);
	return (_printf_chars);
}

/**
 * _printf_buff - Print the content of buffer
 * @buff: Array
 * @buffind: Index
 */
void _printf_buffer(char buff[], int *buffind)
{
	if (*buffind > 0)
		write(1, &buff[0], *buffind);
	*buffind = 0;
}
