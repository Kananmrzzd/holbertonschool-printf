#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing format specifiers
 */
int _printf(const char *format, ...)
{
	int cnt;

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
						while (*str != '\0')
						{
							_putchar(*str);
							str++;
							cnt++;
						}
					}
					break;
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

	return (cnt);
}

