#include "main.h"
#include <stdio.h>
#include <stdarg.h>

/**
 * print_int - prints integers from a va_list
 * @list: va_list of integers to be printed
 * @buffer: Buffer array to handle print
 * Return: number of characters printed
 */
int print_int(va_list args)
 {
    int value = va_arg(args, int);
    int num = va_arg(list, int);
	char buffer[50];
	int len;
	int i;
	int field_width = 0;

	_itoa(num, buffer);
	len = _strlen(buffer);

	if (field_width > len)
	{
		for (i = 0; i < field_width - len; i++)
			_putchar(' ');
	}
	return (_puts(buffer));
}

 print_binary - Prints an unsigned number

 * @types: Lista of arguments

 * @buffer: Buffer array to handle print

 * @flags:  Calculates active flags

 * @width: get width.

 * @precision: Precision specification

 * @size: Size specifier

 * Return: Numbers of char printed.

 */

int print_binary(va_list types, char buffer[]),

{

        unsigned int n, m, i, sum;

        unsigned int a[30];

        int count;


        UNUSED(buffer);

        UNUSED(flags);

        UNUSED(width);

        UNUSED(precision);

        UNUSED(size);


        n = va_arg(types, unsigned int);

        m = 2147483648; /* (2 ^ 29) */

        a[0] = n / m;

        for (i = 1; i < 30; i++)

        {

                m /= 2;

                a[i] = (n / m) % 2;

        }

        for (i = 0, sum = 0, count = 0; i < 30; i++)

        {

                sum += a[i];

                if (sum || i == 29)

                {

                        char z = '0' + a[i];


                        write(1, &z, 1);

                        count++;

                }

        }

        return (count);

}
