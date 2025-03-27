#include "main.h"

/**
 * print_char - Prints a character.
 * @args: The argument list.
 * Return: The number of characters printed (1).
 */
int print_char(va_list args)
{
    char c = va_arg(args, int);
    return (write(1, &c, 1));
}

/**
 * print_string - Prints a string.
 * @args: The argument list.
 * Return: The number of characters printed (length of string).
 */
int print_string(va_list args)
{
    char *str = va_arg(args, char *);
    int count = 0;

    /* If the string is NULL, print "(null)" instead */
    if (str == NULL)
        str = "(null)";

    /* Print the string */
    while (str[count])
    {
	write(1, &str[count], 1);
        count++;
    }

    return (count);
}

/**
 * print_percent - Prints the percent sign.
 * @args: The argument list.
 * Return: The number of characters printed (1).
 */
int print_percent(va_list args)
{
    (void)args;  /* Unused argument */
    return (write(1, "%", 1));
}

