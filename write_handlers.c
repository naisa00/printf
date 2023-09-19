#include "main.h"
/**
 * handle_string - prints string
 * @ch: char
 * @buff: array
 * @flags: calculate active flag
 * @w: width
 * @prec: precision
 * @size: size
 *
 * Return: printed char
 */
int handle_string (char ch, char buff[],
		int flag, int w, int prec, int size)
{
	int i = 0;
	char pad = ' ';

	UNUSED(prec);
	UNUSED(size);
	if (flag & F_ZERO)
	{
		pad = '0';
	}
	buff[i++] = ch;
	buff[i] = '\0';

	if (w > 1)
	{
		buff[BUFF_SIZE - 1] = '\0';
		for (i = 0; i < w - 1; i++)
			buff[BUFF_SIZE - i - 2] = pad;
		if (flag & F_MINUS)
			return (write(1, &buff[0], 1) + write(1, &buff[BUFF_SIZE - i - 1], w - 1));
		else
			return (write(1, &buff[BUFF_SIZE - i - 1], w - 1) + write(1, &buff[0], 1));
	}
	return (write(1, &buff[0], 1));
}
/**
 * write_num - print string
 * @is_negative: lista of arguments
 * @i: char
 * @buffer: array
 * @flag: calculate active flag
 * @w:width
 * @prec: precision
 * @size: size
 *
 * @Return: printed char
 */
int write_num(int is_negative, int i, char buff[], int flag, int w, int prec, int size)
{
	int l = BUFF_SIZE - i - 1;
	char pad = ' ', extra_ch = 0;
	
	UNUSED(size);

	if((flag & F_ZERO) && !(flag & F_MINUS))
	{
		pad = '0';
	}
	if (is_negative)
	{
		extra_ch = '-';
	}
	else if (flag & F_PLUS)
	{
		extra_ch = '+';
	}
	else if (flag & F_SPACE)
	{
		extra_ch = ' ';
	}
	return (write_num(i, buff, flag, w, prec, l, pad, extra_ch));
}

/**
 * write_number - print string
 * @ind: index
 * @buff: buffer
 * @flag: flags
 * @w: width
 * @prec: precision
 * @l: length
 * @pad: pading char
 * @extra_ch: extra char
 * @is_negative: list of arguments
 *
 * Return: printed char
 */
int write_number(int ind, char buff[], int flag, int w, int prec, int l, int is_negative , char pad, char extra_ch)
{
	int i, pad_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0' && w == 0)
	{
		return (0);
	}
	if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
	{
		buff[ind] = pad = ' ';
	}
	if (prec > 0 && prec < l)
	{
		pad = ' ';
	}
	while (prec > l)
		buff[--ind] = '0', l++;
	if (extra_ch != 0)
	{
		l++;
	}
	if (w > l)
	{
		for (i = 1; i < w - l + 1; i++)
			buff [i] = pad;
		buff[i] = '\0';
		if (flag & F_MINUS && pad == ' ')
		{
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buff[ind], l) + write(1, &buff[1], i - 1));
		}
		else if (!(flag & F_MINUS) && pad == ' ')
		{
			if (extra_ch)
				buff[--ind] = extra_ch;
			return (write(1, &buffer[1], i - 1) + write(1, &buff[ind], l));
		}
		else if (!(flag & F_MINUS) && pad == '0')
		{
			if (extra_ch)
				buff[--pad_start] = extra_ch;
			return (write(1, &buff[pad_start], i - pad_start) + write(1, &buff[ind], l - (1 - pad_start)));
		}
	}
	/**
	 * write_unsgnd- write unsigned number
	 * @is_negative: check if num is negative
	 * @ind: index
	 * @buff: array
	 * @flag: flags checker
	 * @w: width
	 * @prec: precision
	 * @size: size
	 *
	 * Return: Number of char that is written
	 */
	int write_unsgnd(int is_negative, int ind,
	char buff[],int flag, int w, int prec, int size)
	{
		int l = BUFF_SIZE - ind - 1, i = 0;
		char pad = ' ';

		UNUSED(is_negative);
		UNUSED(size); 

		if (prec == 0 && ind == BUFF_SIZE - 2 && buff[ind] == '0')
			return (0);
		if (prec > 0 && prec < l)
			pad = ' ';
		while (prec > l)
		{
			buff[--ind] = '0';
			l++;
		}
		if ((flag & F_ZERO) && !(flag & F_MINUS))
		{
			pad = '0';
		}
		if (w > l)
		{
			for (i = 0; i < w - l; i++)
				buff[i] = pad;
			buff[i] = '\0';
			if (flag & F_MINUS)
			{
				return (write(1, &buff[ind], l) + write(1, &buff[0], i));
			}
			else
				return (write(1, &buff[0], i) + write(1, &buff[ind], l));
		}
	}
	return (write(1, &buff[ind], l));
}

/**
 * write_ptr - write address of memory
 * @buff: Array
 * @ind: index
 * @l: length
 * @w: width
 * @flag: flags checker
 * @pad: representing the padding
 * @extra_ch: representing extra char
 * @pad_start: index
 *
 * Return: written char
 */
int write_ptr(char buff[], int ind, int l, int w, int flag, char pad, char extra_ch, int pad_start)
{
	int i;

	if (w > l)
	{
		for (i = 3; i < w - l + 3; i++)
			buff[i] = pad;
		buff[i] = '\0';
		if (flag & F_MINUS && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_ch)
			{
				buff[--ind] = extra_ch;
			}
			return (write(1, &buff[ind], l) + write(1, &buff[3], i - 3));
		}
		else if (!(flag & F_MINUS) && pad == ' ')
		{
			buff[--ind] = 'x';
			buff[--ind] = '0';
			if (extra_ch)
			{
				buff[--ind] = extra_ch;
			}
			return (write(1, &buff[3], i - 3) + write(1, &buff[ind], l));
		}
		else if (!(flag & F_MINUS) && pad == '0')
		{
			if (extra_ch)
			{
				buff[--pad_start] = extra_ch;
			}
			buff[1] = '0';
			buff[2] = 'x';
			return (write(1, &buff[pad_start], i - pad_start) + write(1, &buff[ind], l - (1 - pad_start) - 2));
		}
	}
	buff[--ind] = 'x';
	buff[--ind] = '0';
	if (extra_ch)
	{
		buff[--ind] = extra_ch;
	}
	return (write(1, &buff[ind], BUFF_SIZE - ind - 1));
}
