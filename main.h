#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include<stdlib.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

/* FLAGS */
#define F_MINUS 1
#define F_PLUS 2
#define F_ZERO 4
#define F_HASH 8
#define F_SPACE 16

/* SIZES */
#define S_LONG 2
#define S_SHORT 1
/**
 * struct fmt - Struct op
 *
 * @fmt: The format.
 * @fn: The function associated.
 */
struct fmt
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};
/**
 * typedef struct fmt fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *str, int *ptr,
va_list list, char buff[], int flag, int w, int prec, int size);

/* Funtions to print chars and strings */
int _printf_char();
int _printf_string(va_list type, int w, char buff[], int flag, int prec, int size);
int _printf_percent(va_list type, int w, int size, char buff[], int prec, int flag);

/* Functions to print numbers */
int _printf_integer(va_list type, char buff[], int flag, int w, int prec, int size);
int _printf_binary(va_list types, char buffer[], int flag, int w, int prec, int size);
int _printf_unsigned(va_list type, char buff[], int flag, int w, int prec, int size);
int _printf_oct(va_list type, char buff[], int flag, int w, int prec, int size);
int _printf_hexadecimal(va_list type, char buff[], int flag, int w, int prec, int size);
int _printf_hexa_upper(va_list type, char buff[], int flag, int w, int prec, int size);
int _printf_hexa(va_list type, char map[], char buff[], int flag, char flag_ch, int w, int prec, int size);
/* Function to print non printable characters */
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);

/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *ptr, int *i);
int get_width(const char *ptr, int *pointer, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);

/*Function to print string in reverse*/
int _printf_rever(va_list type, char buff[], int flag, int w, int prec, int size);

/*Function to print a string in rot 13*/
int _printf_rot13string(va_list type, char buff[], int flag, int w, int prec, int size);

/* width handler */
int handle_string(char ch, char buff[], int flag, int w, int prec, int size);
int write_num(int is_positive, int ind, char buff[], int flag, int w, int prec, int size);
int write_number(int ind, char buff[], int flag, int w, int prec, int l, char pad, char extra_ch);
int write_ptr(char buff[], int ind, int l, int w, int flag, char pad, char extra_ch, int padd_start)
{
	return (0);
}
int write_unsgnd(int is_negative, int ind, char buffer[], int flags, int width, int precision, int size)
{
	return (0);
}
int printable()
{
	return (0);
}
int append_ascci()
{
	return (0);
}
long int convert_size_number(long int num, int size)
{
	return (0);
}
long int convert_size_unsgnd(unsigned long int number, int size)
{
	return (0);
}
#endif
