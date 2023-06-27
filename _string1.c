#include "shell.h"

/**
 * _strcat - concatenate two strings
 * @dest: char pointer the dest of the copied str
 * @src: const char pointer the source of str
 * Return: the dest
 */
char *_strcat(char *dest, const char *src)
{
	int z;
	int d;

	for (z = 0; dest[z] != '\0'; z++)
		;

	for (d = 0; src[d] != '\0'; d++)
	{
		dest[z] = src[d];
		z++;
	}

	dest[z] = '\0';
	return (dest);
}
/**
 * *_strcpy - Copies the string pointed to by src.
 * @dest: Type char pointer the dest of the copied str
 * @src: Type char pointer the source of str
 * Return: the dest.
 */
char *_strcpy(char *dest, char *src)
{

	size_t a;

	for (a = 0; src[a] != '\0'; a++)
	{
		dest[a] = src[a];
	}
	dest[a] = '\0';

	return (dest);
}
/**
 * _strcmp - Function that compares two strings.
 * @s1: type str compared
 * @s2: type str compared
 * Return: Always 0.
 */
int _strcmp(char *s1, char *s2)
{
	int z;

	for (z = 0; s1[z] == s2[z] && s1[z]; z++)
		;

	if (s1[z] > s2[z])
		return (1);
	if (s1[z] < s2[z])
		return (-1);
	return (0);
}
/**
 * _strchr - locates a character in a string,
 * @s: string.
 * @c: character.
 * Return: the pointer to the first occurrence of the character c.
 */
char *_strchr(char *s, char c)
{
	unsigned int z = 0;

	for (; *(s + z) != '\0'; z++)
		if (*(s + z) == c)
			return (s + z);
	if (*(s + z) == c)
		return (s + z);
	return ('\0');
}
/**
 * _strspn - gets the length of a prefix substring.
 * @s: initial segment.
 * @accept: accepted bytes.
 * Return: the number of accepted bytes.
 */
int _strspn(char *s, char *accept)
{
	int z, d, bool;

	for (z = 0; *(s + z) != '\0'; z++)
	{
		bool = 1;
		for (d = 0; *(accept + d) != '\0'; d++)
		{
			if (*(s + z) == *(accept + d))
			{
				bool = 0;
				break;
			}
		}
		if (bool == 1)
			break;
	}
	return (z);
}
