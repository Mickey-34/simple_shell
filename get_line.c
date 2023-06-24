#include "shell.h"

/**
* _getline - Reads input provided from the user
* getline for this particular shell
* Return: Input
*/
char *_getline()
{
int z, buffsize = BUFSIZE, rd;
char a = 0;
char *buff = malloc(buffsize);

	if (buff == NULL)
	{
		free(buff);
		return (NULL);
	}

	for (z = 0; a != EOF && z != '\n'; z++)
	{
		fflush(stdin);
		rd = read(STDIN_FILENO, &a, 1);
		if (rd == 0)
		{
			free(buff);
			exit(EXIT_SUCCESS);
		}
		buff[z] = a;
		if (buff[0] == '\n')
		{
			free(buff);
			return ("\0");
		}
		if (z >= buffsize)
		{
			buff = _realloc(buff, buffsize, buffsize + 1);
			if (buff == NULL)
			{
				return (NULL);
			}
		}
	}
	buff[z] = '\0';
	hashtag_handle(buff);
	return (buff);
}

/**
 * hashtag_handle - remove everything after #
 * @buff: input;
 * Return:void
 */
void hashtag_handle(char *buff)
{
	int z;

		for (z = 0; buff[z] != '\0'; z++)
		{
			if (buff[z] == '#')
			{
			buff[z] = '\0';
			break;
			}
	}
}
