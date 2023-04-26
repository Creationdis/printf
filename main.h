#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define BUFF_SIZE 1024

typedef struct flags {
    unsigned int plus;
    unsigned int space;
    unsigned int hashtag;
    unsigned int h;
    unsigned int l;
    unsigned int width;
    unsigned int precision;
    unsigned int zero;
    unsigned int minus;
} flags_t;

int _putchar(char c);
int _printf(const char *format, ...);
int handle_conversion_specifier(const char **p, va_list args, flags_t *flags);
int print_char(va_list args, flags_t *flags);
int print_string(va_list args, flags_t *flags);
int print_percent(va_list args, flags_t *flags);
int print_int(va_list args, flags_t *flags);
int print_binary(va_list args, flags_t *flags);
int print_unsigned(va_list args, flags_t *flags);
int print_octal(va_list args, flags_t *flags);
int print_hexadecimal(va_list args, flags_t *flags);
int print_hexa_upper(va_list args, flags_t *flags);
int print_S(va_list args, flags_t *flags);
int print_address(va_list args, flags_t *flags);
int print_rev(va_list args, flags_t *flags);
int print_rot13(va_list args, flags_t *flags);

#endif /* MAIN_H */

