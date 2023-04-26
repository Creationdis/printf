#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024



/* print name of function */

int _putchar(char c);
int _printf(const char *format, ...);
int handle_conversion_specifier(const char **p, va_list args);
int print_char(va_list args);
int print_string(va_list args);
int print_percent(va_list args);
int print_int(va_list args);
int print_binary(va_list args);
int print_unsigned(va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_hexa_upper(va_list args);
int print_S(va_list args);
int print_address(va_list args);
int print_rev(va_list args);
int print_rot13(va_list args);

/* flag   Width   .precision */

unsigned int plus_flag;
unsigned int space_flag;
unsigned int hashtag_flag;
unsigned int h;
unsigned int l;
unsigned int width;
unsigned int precision;
unsigned int zero_flag;
unsigned int minus_flag;

#endif /* MAIN_H */
