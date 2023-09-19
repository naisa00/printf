#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include<stdlib.h>
#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

#define CONVERT_LOWERCASE 1
#define CONVERT_UNSIGNED 2



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
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);
/* Funtions to print chars and strings */
int _printf_ch(int w, int size, va_list type, char buff[],
	int flag, int prec);
int _printf_str(va_list type, int w, char buff[],
	int flag, int prec, int size);
int _printf_percent(va_list type, int w, int size, char buff[], int prec, int flag);

/* Functions to print numbers */
int _printf_integer(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_binary(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_unsigned(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_oct(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_unsigned_hexa(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_hexa_upper(va_list type, char buff[],
	int flag, int w, int prec, int size);
int _printf_hexa(va_list type, char map[],
char buff[], int flag, char flag_char, int w, int prec, int size);

/* Function to print non printable characters */
int _printf_ascii(va_list type, char buff[],
	int flag, int w, int prec, int size);
/* Funcion to print memory address */
int print_pointer(va_list types, char buffer[],
	int flags, int width, int precision, int size);

/* Funciotns to handle other specifiers */
int get_flags(const char *ptr, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *ptr, int *i);
/*Function to print string in reverse*/
int print_rever(va_list type, char buff[],
	int flag, int w, int prec, int size);
/*Function to print a string in rot 13*/
int print_rot13string(va_list type, char buff[],
	int flag, int w, int prec, int size);
/* width handler */
int handle_write_char(char ch, char buff[],
	int flag, int w, int prec, int size);
int write_number(int positive, int ind, char buff[],
	int flag, int w, int prec, int size);
int write_num(int ind, char bff[], int flag, int w, int precision,
	int l, char padd, char extra_c);
int write_pointer(char buff[], int ind, int l,
	int w, int flag, char padd, char extra_c, int padd_start);
int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);
/** UTILS **/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);
long int convert_size_number(long int number, int size);
long int convert_size_unsgnd(unsigned long int number, int size);
#endif
