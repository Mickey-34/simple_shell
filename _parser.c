#include "shell.h"

/**
 * parse_cmd - Parse Line Of Input
 *
 * @input:User Input To Parse
 * Return: Array Of Char
 */
char **parse_cmd(char *input)
{
	char **tokens;
	char *token;
	int z, buffsize = BUFSIZE;

	if (input == NULL)
		return (NULL);
	tokens = malloc(sizeof(char *) * buffsize);
	if (!tokens)
	{
		perror("hsh");
		return (NULL);
	}

	token = _strtok(input, "\n ");
	for (z = 0; token; z++)
	{
		tokens[z] = token;
		token = _strtok(NULL, "\n ");
	}
	tokens[z] = NULL;

	return (tokens);
}
