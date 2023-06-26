#include "shell.h"
/**
 * check_delim - Checks If A Character Match Any Char
 * token usually breaks chars into pieces and pieces
 * @c: Character To Check
 * @str: String To Check
 * Return: 1 Succes, 0 Failed
 */
unsigned int check_delim(char c, const char *str)
{
	unsigned int z;

	for (z = 0; str[z] != '\0'; z++)
	{
		if (c == str[z])
			return (1);
	}
	return (0);
}

/**
 * _strtok - Token A String Into Token (strtrok)
 * @str: String
 * @delim: Delimiter
 * Return: Pointer To The Next Token Or NULL
 */
char *_strtok(char *str, const char *delim)
{
	static char *ts;
	static char *nt;
	unsigned int z;

	if (str != NULL)
		nt = str;
	ts = nt;
	if (ts == NULL)
		return (NULL);
	for (z = 0; ts[z] != '\0'; z++)
	{
		if (check_delim(ts[z], delim) == 0)
			break;
	}
	if (nt[z] == '\0' || nt[z] == '#')
	{
		nt = NULL;
		return (NULL);
	}
	ts = nt + z;
	nt = ts;
	for (z = 0; nt[z] != '\0'; z++)
	{
		if (check_delim(nt[z], delim) == 1)
			break;
	}
	if (nt[z] == '\0')
		nt = NULL;
	else
	{
		nt[z] = '\0';
		nt = nt + z + 1;
		if (*nt == '\0')
			nt = NULL;
	}
	return (ts);
}
