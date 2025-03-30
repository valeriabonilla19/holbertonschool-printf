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
if (str == NULL)
str = "(null)";
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
(void)args;
return (write(1, "%", 1));
}
/**
* print_integer - Prints an integer.
* @args: The argument list.
* Return: The number of characters printed.
*/
int print_integer(va_list args)
{
int num = va_arg(args, int);
int count = 0;
char buffer[12];
int i = 0;
if (num == -2147483648)
return (write(1, "-2147483648", 11));
if (num < 0)
{
count += write(1, "-", 1);
num = -num;
}
do {
buffer[i++] = (num % 10) + '0';
num /= 10;
} while (num > 0);
while (i--)
count += write(1, &buffer[i], 1);
return (count);
}
