#include "shell.h"

/**
 * rev_string - reverses a string.
 * @s: input string.
 * Return: no return.
 */
void rev_string(char *s)
{
	int count = 0, z, d;
	char *str, temp;

	while (count >= 0)
	{
		if (s[count] == '\0')
			break;
		count++;
	}
	str = s;

	for (z = 0; z < (count - 1); z++)
	{
		for (d = z + 1; d > 0; d--)
		{
			temp = *(str + d);
			*(str + d) = *(str + (d - 1));
			*(str + (d - 1)) = temp;
		}
	}
}
