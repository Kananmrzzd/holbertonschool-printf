#include <unistd.h>

/**
 * _putchar - print char
 * @c: char
 * Return: char
 */
char _purchar(char c)
{
	return (write(1, &c, 1));
}
