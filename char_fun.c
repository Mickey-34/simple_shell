#include "shell.h"

/**
 * _putchar - writes the character c to stdout
 * displays a char to the screen
 * @c: The character to print
 *
 * Return: On success 1.
 * On error, -1 is returned, and errno is set appropriately.
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
/**
 * _strncpy - copie a string
 * @dest:char
 *  @src:char
 * @n:int
 * Return:char
 */

char *_strncpy(char *dest, char *src, int n)
{
int z;

z = 0;
	while (z < n && *(src + z))
	{
	*(dest + z) = *(src + z);
	z++;
	}
	while (z < n)
	{
	*(dest + z) = '\0';
	z++;
	}
	return (dest);
}

/**
 * _strlen - lenght of string
 * @s:char
 * Return:int
 */

int _strlen(char *s)
{
	int z;

		for (z = 0; s[z] != '\0'; z++)
		{
			continue;
		}
return (z);
}

/**
 * _atoi - convert to a int
 * @s:string
 * Return:int
 */
int _atoi(char *s)
{
int z, d, n, u;

	z = n = 0;
	u = 1;
	while ((s[z] < '0' || s[z] > '9') && (s[z] != '\0'))
	{
		if (s[z] == '-')
			u *= -1;
		z++;
	}
	d = z;
	while ((s[d] >= '0') && (s[d] <= '9'))
	{
		n = (n * 10) + u * ((s[d]) - '0');
		d++;
	}
	return (n);
}
/**
 * _puts - print a string
 * @str:pointer char
 * return:void
 */
void _puts(char *str)
{
	int z;

	for (z = 0; str[z] != '\0'; z++)
	{
		_putchar(str[z]);
	}
_putchar('\n');
return;
}
