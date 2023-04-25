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

int count = 0;
char ch;

while ((ch = *format++) != '\0') 
{
if (ch == '%') 
{
ch = *format++;
switch (ch) 
{
case 'c': 
{
char c = (char) va_arg(args, int);
putchar(c);
count++;
break;
}
case 's': 
{
char *str = va_arg(args, char *);
while (*str != '\0') 
{
putchar(*str++);
count++;
}
break;
}
case '%': 
{
putchar('%');
count++;
break;
}
default: 
{
putchar('%');
putchar(ch);
count += 2;
break;
}
}
} 
else 
{
putchar(ch);
count++;
}
}

va_end(args);
return(count);
}

