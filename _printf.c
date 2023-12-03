#include <stdarg.h>
#include <unistd.h>
#include "main.h"
#include <limits.h>
/**
 * _print_char - Print a character
 * @args: Argument list
 * Return: Number of characters printed
 */
int _print_char(va_list args)
{
	_putchar(va_arg(args, int));
	return (1);
}
/**
 * _print_string - Print a string
 * @args: Argument list
 * Return: Number of characters printed
 */
int _print_string(va_list args)
{
	char *str = va_arg(args, char *);
	int cnt = 0;

	if (str == NULL)
		str = "(null)";

	for (; *str != '\0'; str++, cnt++)
		_putchar(*str);

	return (cnt);
}
/**
 * _print_int - Print an integer
 * @args: Argument list
 * Return: Number of characters printed
 */
int _print_int(va_list args)
{
	int n = va_arg(args, int);
	int div = 1;
	int cnt = 0;
	int temp;

	if (n == INT_MIN)
	{
		_putchar('-');
		_putchar('2');
		n = 147483648;
		cnt += 2;
	}
	else if (n < 0)
	{
		_putchar('-');
		n *= -1;
		cnt++;
	}

	for (temp = n; temp > 9; temp /= 10)
		div *= 10;

	for (; div > 0; div /= 10, cnt++)
		_putchar('0' + (n / div) % 10);

	return (cnt);
}
/**
 * handle_format - Handle different format specifiers
 * @format_ptr: Pointer to the current format specifier
 * @args: Argument list
 * Return: Number of characters printed
 */
int handle_format(const char **format_ptr, va_list args)
{
	switch (**format_ptr)
	{
		case 'c':
			return (_print_char(args));
		case 's':
			return (_print_string(args));
		case 'd':
		case 'i':
			return (_print_int(args));
		case '%':
			_putchar('%');
			return (1);
		default:
			_putchar('%');
			_putchar(**format_ptr);
			return (2);
	}
}
/**
 * _printf - Custom printf function
 * @format: Format string
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int cnt = 0;
	va_list args;

	if (format == NULL)
		return (-1);

	va_start(args, format);

	for (; *format != '\0'; format++)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
			{
				break;
			}
			cnt += handle_format(&format, args);
		}
		else
		{
			_putchar(*format);
			cnt++;
		}
	}

	va_end(args);

	return (cnt);
}
