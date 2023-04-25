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

int main(void)
{
int len;
int len2;

len = _printf("Let's try to printf a simple sentence.\n");
len2 = printf("Let's try to printf a simple sentence.\n");
    
_printf("Character:[%c]\n", 'H');
printf("Character:[%c]\n", 'H');

_printf("String:[%s]\n", "I am a string !");
printf("String:[%s]\n", "I am a string !");

len = _printf("Percent:[%%]\n");
len2 = printf("Percent:[%%]\n");    
return (0);
}

