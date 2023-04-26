#include "main.h"

/**
 * _printf - prints a formatted string to the standard output.
 *
 * @format: A pointer to a string that contains format specifiers.
 *
 * Description:
 * This function produces output according to a format.
 * The format string is composed of zero or more directives:
 * ordinary characters (not %), which are copied unchanged to the output stream;
 * and conversion specifications, each of which results in fetching zero or more
 * subsequent arguments. Each conversion specification is introduced by the
 * % character.
 *
 * Return: The number of characters printed (excluding the null byte used to
 * end output to strings).
 * If an output error is encountered, a negative value is returned.
 */

int _printf(const char *format, ...)
{
    va_list args;
    const char *p = format;
    int count = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (*p != '\0')
    {
        if (*p == '%')
        {
            p++;
            flags_t flags = {0};
            while (*p != '\0' && is_flag(*p))
            {
                set_flag(*p, &flags);
                p++;
            }
            handle_conversion_specifier(&p, args, &flags, &count);
        }
        else
        {
            _putchar(*p);
            count++;
        }
        p++;
    }

    va_end(args);

    return (count);
}


/**
 * handle_conversion_specifier - Handles a conversion specifier.
 *
 * @p: A pointer to a pointer to a character in the format string.
 * @args: A va_list of arguments to print.
 * @flags: A pointer to a struct containing the flag settings.
 *
 * Return: The number of characters printed for this specifier, or -1 on failure.
 */

int handle_conversion_specifier(const char **p, va_list args, flags_t *flags, int *count)
{
    int printed = 0;
    switch (**p)
    {
        case 'c':
            printed = print_char(args, flags);
            break;
        case 's':
            printed = print_string(args, flags);
            break;
        case '%':
            printed = print_percent(args, flags);
            break;
        case 'd':
        case 'i':
            printed = print_int(args, flags);
            break;
        case 'b':
            printed = print_binary(args, flags);
            break;
        case 'u':
            printed = print_unsigned(args, flags);
            break;
        case 'o':
            printed = print_octal(args, flags);
            break;
        case 'x':
            printed = print_hexadecimal(args, flags);
            break;
        case 'X':
            printed = print_hexa_upper(args, flags);
            break;
        case 'S':
            printed = print_S(args, flags);
            break;
        case 'p':
            printed = print_address(args, flags);
            break;
        case 'r':
            printed = print_rev(args, flags);
            break;
        case 'R':
            printed = print_rot13(args, flags);
            break;
        default:
            _putchar('%');
            _putchar(**p);
            *count += 2;
            break;
    }
    return printed;
}

