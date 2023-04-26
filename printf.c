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
			int printed = handle_conversion_specifier(&p, args);
			if (printed < 0)
				return (-1);
			count += printed;
		}
		else
		{
			putchar(*p);
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
 *
 * Return: The number of characters printed for this specifier, or -1 on failure.
 */
int handle_conversion_specifier(const char **p, va_list args)
{
	int count = 0;

	/* Skip over the initial '%' */
	(*p)++;

	switch (**p)
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
		putchar(**p);
		count += 2;
		break;
	}

	return (count);
}

