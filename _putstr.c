#include "main.h"
#include <unistd.h>

/*_putstr - write to standart outpur
* @str: const char
* Return: count
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
