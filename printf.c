#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _print_char - Prints a character to the standard output.
 * @args: The va_list containing the character argument
 * Return: Number of characters printed
 */
int _print_char(va_list args)
{
	int cnt = 0;
	char c = va_arg(args, int);
	_putchar(c);
	cnt++;
	return cnt;
}

/**
 * _print_string - Prints a string to the standard output.
 * @args: The va_list containing the string argument
 * Return: Number of characters printed
 */
int _print_string(va_list args)
{
	int cnt = 0;
	char *str = va_arg(args, char *);

	if (str == NULL)
	{
		_putstr("(null)");
		cnt += 6;
	}
	else
	{
		while (*str != '\0')
		{
			_putchar(*str);
			str++;
			cnt++;
		}
	}
	return cnt;
}

/**
 * _print_int - Prints an integer to the standard output.
 * @args: The va_list containing the integer argument
 * Return: Number of characters printed
 */
/**
int _print_int(va_list args)
{
	int cnt = 0;
	int num = va_arg(args, int);
	char buffer[20];

	int length = _printf(buffer, "%d", num);
	write(1, buffer, length);
	cnt += length;
	return cnt;
}
*/

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format specifiers
 * Return: count
 */
int _printf(const char *format, ...)
{
	int cnt = 0;

	va_list args;
	const char *ptr;

	if (format == NULL)
		return 0;

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;

			if (*ptr == '\0')
				return cnt;

			switch (*ptr)
			{
				case 'c':
					cnt += _print_char(args);
					break;
				case 's':
					cnt += _print_string(args);
					break;
				/**
				case 'd':
				case 'i':
					cnt += _print_int(args);
					break;
				*/
				case '%':
					_putchar('%');
					cnt++;
					break;
				default:
					_putchar(*ptr);
					cnt += 2;
					break;
			}
		}
		else
		{
			_putchar(*ptr);
			cnt++;
		}
	}

	va_end(args);

	return cnt;
}

