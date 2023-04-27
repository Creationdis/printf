#include "main.h"
#include <ctype.h>

/**
 * print_rot13 - Encodes a string using the ROT13 cipher
 * @args: The va_list containing the string to encode
 * @flags: A pointer to the struct containing the format flags
 *
 * Return: The number of characters printed
 */
int print_rot13(va_list args, flags_t *flags)
{
    int i, j, len = 0;
    char *str = va_arg(args, char*);
    char alphabet[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
    char rot13[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

    if (str == NULL)
        str = "(null)";

    for (i = 0; str[i]; i++)
    {
        if (isalpha(str[i]))
        {
            for (j = 0; alphabet[j]; j++)
            {
                if (str[i] == alphabet[j])
                {
                    len += _putchar(rot13[j]);
                    break;
                }
            }
        }
        else
        {
            len += _putchar(str[i]);
        }
    }

    return (len);
}

