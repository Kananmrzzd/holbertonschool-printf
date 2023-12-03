#include "main.h"
#include <unistd.h>

/**
 * _putstr - Print a string to standard output
 * @str: The string to be printed
 *
 * Return: The number of characters printed (excluding null byte)
 *         or -1 if an error occurs
 */
int _putstr(const char *str)
{
	int count = 0;

	if (str == NULL)
		return (-1);

	while (*str != '\0')
	{
		if (_putchar(*str) == -1)
			return (-1);

		count++;
		str++;
	}

	return (count);
}
