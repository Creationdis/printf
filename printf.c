#include <stdio.h>
#include <stdarg.h>
#include "main.h"

/**
 * _printf - a function that produces output according to a format.
 * @format: The format string is composed of zero or more directives.
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
    int count = 0, width = 0, precision = -1;
    va_list args;
    va_start(args, format);

    while (*format != '\0')
    {
        if (*format == '%')
        {
            format++;
            if (*format >= '0' && *format <= '9')
                width = get_width(&format);
            if (*format == '.')
                precision = get_precision(&format);
            switch (*format)
            {
                case 'c':
                    count += putchar(va_arg(args, int));
                    break;
                case 's':
                    count += print_string(va_arg(args, char *), width, precision);
                    break;
                case 'd':
                case 'i':
                    count += print_integer(va_arg(args, int), width, precision);
                    break;
                case 'u':
                    count += print_unsigned(va_arg(args, unsigned int), width, precision);
                    break;
                case 'o':
                    count += print_octal(va_arg(args, unsigned int), width, precision);
                    break;
                case 'x':
                case 'X':
                    count += print_hexadecimal(va_arg(args, unsigned int), width, precision, (*format == 'X'));
                    break;
                case 'f':
                    count += dtoa(va_arg(args, double), precision);
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
        }
        else
        {
            putchar(*format);
            count++;
            format++;
        }
    }
    va_end(args);
    return (count);
}

