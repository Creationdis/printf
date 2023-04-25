#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 *_printf - a function that produces output according to a format.
 *@format: A format is a character string.
 *Description: %[flags][width][.precision][length]specifier
 *Return: number of characters printed
 */
#include <stdarg.h>
#include <stdio.h>

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    if (format == NULL) {
        return -1;
    }

    va_start(args, format);

    for (int i = 0; format[i] != '\0'; i++) {
        if (format[i] == '%') {
            if (format[i + 1] == '\0') {
                return -1;
            }
            switch (format[i + 1]) {
                case 's': {
                    char *str = va_arg(args, char *);
                    for (int j = 0; str[j] != '\0'; j++) {
                        putchar(str[j]);
                        count++;
                    }
                    i++;
                    break;
                }
                case 'c': {
                    char c = va_arg(args, int);
                    putchar(c);
                    count++;
                    i++;
                    break;
                }
                case '%': {
                    putchar('%');
                    count++;
                    i++;
                    break;
                }
                default: {
                    putchar(format[i]);
                    count++;
                    break;
                }
            }
        } else {
            putchar(format[i]);
            count++;
        }
    }

    va_end(args);

    return count;
}
