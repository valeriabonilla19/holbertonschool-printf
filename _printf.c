#include "main.h"

/**
* _printf - Custom printf function.
* @format: The format string.
* Return: The number of characters printed.
*/
int _printf(const char *format, ...)
{
va_list args;
int i = 0, count = 0;

if (!format)
return (-1);

va_start(args, format);

while (format[i])
{
if (format[i] == '%' && format[i + 1])
{
i++;
switch (format[i])
{
case 'c':
count += print_char(args);
break;
case 's':
count += print_string(args);
break;
case '%':
count += print_percent(args);
break;
case 'd':
case 'i':
count += print_integer(args);
break;
case 'b':
count += print_binary(args);
break;
case 'u':
count += print_unsigned(args);
break;
case 'o':
count += print_octal(args);
break;
case 'x':
count += print_hex_lower(args);
break;
case 'X':
count += print_hex_upper(args);
break;
default:
count += write(1, &format[i - 1], 2);
break;
}
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
