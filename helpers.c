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
    int length = 0;

    if (str == NULL)
        str = "(null)";

    /* Calculate length first */
    while (str[length])
        length++;

    /* Write entire string at once */
    write(1, str, length);

    return (length);
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


/**
 * print_integer - Prints an integer.
 * @args: The argument list.
 * Return: The number of characters printed.
 */
int print_integer(va_list args)
{
    int num;  /* Variable to store the integer */
    int count = 0;  /* To count the number of characters printed */
    char buffer[10];  /* Buffer to store digits of the number */
    int i = 0;  /* Index for the buffer */
    int j;  /* Loop variable for reversing the digits */

    num = va_arg(args, int);  /* Get the integer argument */

    /* Handle the case when the number is zero */
    if (num == 0)
    {
        return write(1, "0", 1);
    }

    /* Handle negative numbers */
    if (num < 0)
    {
        write(1, "-", 1);
        num = -num;
        count++;
    }

    /* Convert the integer to a string (store in reverse order) */
    while (num > 0)
    {
        buffer[i] = (num % 10) + '0';
        num = num / 10;
        i++;
    }

    /* Print the digits in correct order (reverse the string) */
    for (j = i - 1; j >= 0; j--)
    {
        write(1, &buffer[j], 1);
        count++;
    }

    return count;
}

