#include "main.h"

/**
* _printf - Function that mimics the printf behavior.
* @format: The format string.
* Return: The number of characters printed (excluding the null byte).
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;
int (*func)(va_list);

va_start(args, format);

while (format && format[i])
{
if (format[i] == '%' && format[i + 1] != '\0')
{
i++;
if (format[i] == 'c')
func = print_char;
else if (format[i] == 's')
func = print_string;
else if (format[i] == '%')
func = print_percent;
else
func = NULL;

if (func)
count += func(args);
else
count += write(1, &format[i - 1], 1);
}
else
{
count += write(1, &format[i], 1);
}
i++;
}

va_end(args);
return (count);
}

