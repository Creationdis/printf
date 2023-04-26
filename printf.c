#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 *_printf - a function that produces output according to a format.
 *@format: The format string is composed of zero or more directives.
 *Return: number of characteres printed
 */

int _printf(const char *format, ...)
{
int count = 0;
va_list args;
va_start(args, format);

while (*format != '\0')
{
if (*format == '%')
{
format++;
switch (*format)
{
case 'c':
count += putchar(va_arg(args, int));
break;
case 's':
count += printf("%s", va_arg(args, char *));
break;
case '%':
count += putchar('%');
break;
default:
putchar('%');
putchar(*format);
count += 2;
break;
}
} else
{
putchar(*format);
count++;
}
format++;
}
va_end(args);
return (count);

}
