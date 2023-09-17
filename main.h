#ifndef MAIN_H
#define MAIN_H
#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>
#include <limits.h>
#include<stdlib.h>

#define BUF_FLUSH -1
#define UNUSED(x) (void)(x)
#define OUTPUT_BUFF_SIZE 1024
#define NULL_STRING "(null)"

#define PARMS_INT {0, 0, 0, 0, 0, 0, 0, 0, 0, 0}

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
 
 *struct paramters - parameters struct

 *@unsign: flag if unsigned value

 *@plus_flags: on if plus-flag specified
 *@space_flag: on if hashtag_flag specified
 *@hashtag_flag: on if _flag specified
 *@zero_flag: on if _flag specified
 *minus_flag:on if _flag specified
 *
 * @width: field width specified
 * @precision: fiel precision specified
 *
 * @h_modifier: on if h_modifier is specified
 * @l_modifier: on if l_modifier is specified
 *
 */
typedef struct parameters
{ 
	unsigned int insign          :1;

	unsigned int plus_flag       :1;
	unsigned int space_flag      :1;
	unsigned int hashtag_flag    :1;
	unsigned int zero_flag       :1;
	unsigned int minus_flag      :1;


	unsigned int width;
	unsigned int precision


	unsigned int h_modifier      :1;
        unsigned int l_modifier	     :1;
} params_t;



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
 *
 * @fmt: The format.
 * @fm_t: The function associated.
 */
typedef struct fmt fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);





/**
 * struct specifier - Struct token
 *
 * @specifier: format token
 * @f: The function associated
*/
typedef struct specifier
{
	char *specifier;
	int (*f)(va_list, params_t *);
} specifier_t;

/****************** FUNCTIONS ******************/

/* Print functions .c */
int print_char(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[],
int flags, int width, int precision, int size);
int print_S(va_list ap,params_t *params);
int print_non_printable(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[],
        int flags, int width, int precision, int size);

/* print_number */
int _isdigit(int c);
int _strlen(char *s);
int print_number(char *str, params_t *params);
int print_number_right_shift(char *str, params_t *params);
int print_number_left_shift(char *str, params_t *params);
 
/*params.c*/
void int_params(params_t *params, va_list ap);

/*string_field.c*/
char *get_precision(char *p, params_t *params, va_list ap);

/* convert_number .c */
int print_octal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[],
	int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[],
	int flags, int width, int precision, int size);

int print_hexa(va_list types, char map_to[],
char buffer[], int flags, char flag_ch, int width, int precision, int size);

/* simple _pointers.c */
int print_from_to(char *start, char *stop, char *except);
int print_rot13string(va_list types, char buffer[],
        int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[],
        int flags, int width, int precision, int size);


/* _put.c */
int _puts(char *str);
int _putchar(int c);

/*number.c*/
char *convert(long int num, int base, int flags, params_t *params);
int print_address(va_list ap, params_t *params);
int print_unsigned(va_list types, char buffer[],
        int flags, int width, int precision, int size)

/* Funciotns to handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int (*get_specifier(char *s)(va_list ap,params_t *params); 
int get_print_func(char *s,va_list ap,params_t *params);
int get _modifier(char *s,params_t *params);
char *get_width(char *s, params_t *params, va_list ap);

/* width handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsgnd(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/****************** UTILS ******************/
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);
/* _printf.c */
int _printf(const char *format, ...);
#endif /* MAIN_H */
