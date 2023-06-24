#include "shell.h"
/**
 * history - Fill File By User Input
 * history usually provided by user
 * @input: User Input
 * Return: -1 Fail 0 Succes
 */
int history(char *input)
{
	char *filename = ".simple_shell_history";
	ssize_t fd, w;
	int n = 0;

	if (!filename)
		return (-1);
	fd = open(filename, O_CREAT | O_RDWR | O_APPEND, 00600);
	if (fd < 0)
		return (-1);
	if (input)
	{
		while (input[n])
			n++;
		w = write(fd, input, n);
		if (w < 0)
			return (-1);
	}
	return (1);
}
/**
 * free_env - Free Enviroment Variable Array
 * @env:  Environment variables.
 * Return: Void
 */
void free_env(char **env)
{
	int z;

	for (z = 0; env[z]; z++)
	{
		free(env[z]);
	}
}
