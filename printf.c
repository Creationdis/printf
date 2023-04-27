#include "main.h"
#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include <stddef.h>
#include <limits.h>

/**
 * _putchar - Writes a character to stdout
 * @c: The character to print
 *
 * Return: 1 if successful, -1 if failed
 */
int _putchar(char c)
{
    return (write(1, &c, 1));
}


/**
 * _printf - Prints a formatted string to stdout
 * @format: The format string
 *
 * Return: The number of characters printed
 */
int _printf(const char *format, ...)
{
    va_list args;
    int len = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);
    len = handle_conversion_specifier(&format, args);
    va_end(args);

    return (len);
}


/**
 * handle_conversion_specifier - Handles conversion specifiers in a format string
 * @p: A pointer to a pointer to the current position in the format string
 * @args: The va_list containing the arguments for the format string
 *
 * Return: The number of characters printed
 */
int handle_conversion_specifier(const char **p, va_list args)
{
    int len = 0;
    flags_t flags = {0};

    while (**p != '\0')
    {
        if (**p != '%')
        {
            len += _putchar(**p);
            (*p)++;
            continue;
        }

        (*p)++;
        while (**p == ' ')
        {
            flags.space = 1;
            (*p)++;
        }

        while (**p == '+' || **p == '-')
        {
            if (**p == '+')
                flags.plus = 1;
            else if (**p == '-')
                flags.minus = 1;
            (*p)++;
        }

        if (**p == '0')
        {
            flags.zero = 1;
            (*p)++;
        }

        if (**p == '#')
        {
            flags.hashtag = 1;
            (*p)++;
        }

        if (**p == '*')
        {
            flags.width = va_arg(args, int);
            (*p)++;
        }
        else
        {
            flags.width = atoi(*p);
            while (**p >= '0' && **p <= '9')
                (*p)++;
        }

        if (**p == '.')
        {
            (*p)++;
            if (**p == '*')
            {
                flags.precision = va_arg(args, int);
                (*p)++;
            }
            else
            {
                flags.precision = atoi(*p);
                while (**p >= '0' && **p <= '9')
                    (*p)++;
            }
        }

        if (**p == 'h' || **p == 'l')
        {
            if (**p == 'h')
                flags.h++;
            else if (**p == 'l')
                flags.l++;
            (*p)++;
        }

        if (**p == 'c' || **p == 's' || **p == 'd' || **p == 'i' ||
            **p == 'b' || **p == 'u' || **p == 'o' || **p == 'x' ||
            **p == 'X' || **p == 'S' || **p == 'p' || **p == 'r' ||
            **p == 'R')
        {
            len += print_char(**p, &flags, args);
            (*p)++;
            break;
        }

        (*p)++;
    }

    return (len);
}



