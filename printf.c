#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - print
 * @format: Format specifiers
 * Return: Number of characters printed (excluding null byte)
 */
int _printf(const char *format, ...)
{
	int cnt = 0;

	va_list args;
	const char *ptr;

	if (format == NULL)
		return (0);

	va_start(args, format);

	for (ptr = format; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;

			if (*ptr == '\0')
				return (0);

			if (*ptr == '\0')
				break;

			switch (*ptr)
			{
				case 'c':
					_putchar(va_arg(args, int));
					cnt++;
					break;
				case 's':
					{
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
					}
					break;
				case '%':
					_putchar('%');
					cnt++;
					break;
				default:
					_putchar('%');
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

