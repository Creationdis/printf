#ifndef MAIN_H_
#define MAIN_H_

#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <limits.h>

#define UNUSED(x) (void)(x)
#define BUFF_SIZE 1024

typedef struct {
    char *specifier;
    void (*handler)(va_list);
} code_format;

/* print name of function */

int putchar (int c);
int _printf(const char *format, ...);
void handle_percent(va_list args); {
    printf("%%");
}

void handle_char(va_list args); {
    char c = va_arg(args, int);
    printf("%c", c);
}

void handle_string(va_list args); {
    char *s = va_arg(args, char*);
    printf("%s", s);
}

void handle_decimal(va_list args); {
    int d = va_arg(args, int);
    printf("%d", d);
}

void handle_integer(va_list args); {
    int i = va_arg(args, int);
    printf("%d", i);
}

int print_binary(va_list args);
int print_unsigned (va_list args);
int print_octal(va_list args);
int print_hexadecimal(va_list args);
int print_Hexa_upper(va_list args);
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
