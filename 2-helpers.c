#include "main.h"
/**
* print_unsigned - Prints an unsigned integer.
* @args: The argument list.
* Return: The number of characters printed.
*/
int print_unsigned(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[11];
int i = 0, count = 0;
if (num == 0)
return (write(1, "0", 1));
while (num > 0)
{
buffer[i++] = (num % 10) + '0';
num /= 10;
}
while (i--)
count += write(1, &buffer[i], 1);

return (count);
}
/**
* print_octal - Prints an unsigned int in octal.
* @args: The argument list.
* Return: The number of characters printed.
*/
int print_octal(va_list args)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[12];
int i = 0, count = 0;
if (num == 0)
return (write(1, "0", 1));
while (num > 0)
{
buffer[i++] = (num % 8) + '0';
num /= 8;
}
while (i--)
count += write(1, &buffer[i], 1);

return (count);
}
/**
* print_hex - Prints an unsigned int in hexadecimal (lowercase or uppercase).
* @args: The argument list.
* @uppercase: 1 for uppercase (%X), 0 for lowercase (%x).
* Return: The number of characters printed.
*/
int print_hex(va_list args, int uppercase)
{
unsigned int num = va_arg(args, unsigned int);
char buffer[9];
char *hex_chars = uppercase ? "0123456789ABCDEF" : "0123456789abcdef";
int i = 0, count = 0;
if (num == 0)
return (write(1, "0", 1));
while (num > 0)
{
buffer[i++] = hex_chars[num % 16];
num /= 16;
}
while (i--)
count += write(1, &buffer[i], 1);

return (count);
}
/**
* print_hex_lower - Prints an unsigned int in lowercase hexadecimal (%x).
* @args: The argument list.
* Return: The number of characters printed.
*/
int print_hex_lower(va_list args)
{
return (print_hex(args, 0));
}

/**
* print_hex_upper - Prints an unsigned int in uppercase hexadecimal (%X).
* @args: The argument list.
* Return: The number of characters printed.
*/
int print_hex_upper(va_list args)
{
return (print_hex(args, 1));
}
