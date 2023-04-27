#include <stdarg.h>
#include <stdio.h>
#include "main.h"

/**
 * printf_int - Handle the following conversion specifiers
 * @args: argument to print
 * Return: number of characters printed
 */

typedef struct {
    // Placeholder for future flag options
} flags_t;

int print_int(va_list args, flags_t *flags) {
    int value = va_arg(args, int);
    return printf("%d", value);
}

int main() {
    int value = 42;
    flags_t flags;
    print_int(value, &flags); 
    return (0);
}

