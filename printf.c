#include <stdio.h>
#include <stdlib.h>
#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
  * find_function - finds the conversion function for a format specifier
  * @format: the format specifier to find the conversion function for
  * Return: a pointer to the conversion function, or NULL if not found
  */
int (*find_function(const char *format))(va_list)
{
	unsigned int i = 0;

	code_format formats[] = {
		{"%", handle_percent},
		{"c", handle_char},
		{"s", handle_string},
		{"d", handle_decimal},
		{"i", handle_integer},
		{NULL, NULL}
	};

	while (formats[i].specifier)
	{
		if (formats[i].specifier[0] == format[0])
			return (formats[i].function);
		i++;
	}
	return (NULL);
}
/**
  * _printf - function that produces output according to a format.
  * @format: format (c, s, %, d, i)
  * Return: the number of characters printed 
  */
int my_printf(const char *format, ...)
{
    va_list args;
    int (*conversion_func)(va_list);
    unsigned int i = 0, num_chars_printed = 0;

    if (format == NULL)
        return (-1);

    va_start(args, format);

    while (format[i])
    {
        while (format[i] != '%' && format[i])
        {
            putchar(format[i]);
            num_chars_printed++;
            i++;
        }

        if (format[i] == '\0')
            return (num_chars_printed);

        conversion_func = find_conversion_function(&format[i + 1]);

        if (conversion_func != NULL)
        {
            num_chars_printed += conversion_func(args);
            i += 2;
            continue;
        }

        if (!format[i + 1])
            return (-1);

        putchar(format[i]);
        num_chars_printed++;

        if (format[i + 1] == '%')
            i += 2;
        else
            i++;
    }

    va_end(args);

    return (num_chars_printed);
}

