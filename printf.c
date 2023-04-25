#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *_printf - a function that produces output according to a format.
 *@format: A format is a character string.
 *Description: %[flags][width][.precision][length]specifier
 *Return: number of characters printed
 */

int _printf(const char *format, ...)
{
va_list args;
va_start(args, format);

int i = 0;

while (*format != '\0')
if (*format == '%')
format++;
switch (*format)
{
case 'c':
{
int c = va_arg(args, int);
putchar(c);
i++;
}
case 's':
{
char *s = va_arg(args, char *);
while (*s != '\0')
putchar(*s);
s++;
i++;
}
case '%':
{
putchar('%');
putchar(*format);
(i += 2);
}
{
putchar(*format);
i++;
format++;
}
}
va_end(args);
return (0);
}
