#include <unistd.h>

/**
 * _putchar - print char
 * @c: char
 * Return: char
 */
char _putchar(char c)
{
	return (write(1, &c, 1));
}
