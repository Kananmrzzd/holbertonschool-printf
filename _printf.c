#include <stdarg.h>
#include <unistd.h>
#include "main.h"

/**
 * _printf - Custom printf function with limited functionality
 * @format: Format string containing format specifiers
 */
int _printf(const char *format, ...)
{
	va_list args;
	const char *ptr;

	if (format == NULL)
		return;

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
					break;
				case 's':
					{
						char *str = va_arg(args, char *);
						while (*str != '\0')
						{
							_putchar(*str);
							str++;
						}
					}
					break;
				case '%':
					_putchar('%');
					break;
				default:
					_putchar('%');
					_putchar(*ptr);
					break;
			}
		}
		else
		{
			_putchar(*ptr);
		}
	}

	va_end(args);

	return (0);
}
