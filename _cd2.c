#include "shell.h"

/**
 * cd_shell - changes current directory
 *
 * @datash: data relevant
 * Return: 1 on success
 */
int cd_shell(data_shell *datash)
{
	char *dir;
	int isroot, isroot2, isddash;

	dir = datash->args[1];

	if (dir != NULL)
	{
		isroot = _strcmp("$HOME", dir);
		isroot2 = _strcmp("~", dir);
		isddash = _strcmp("--", dir);
	}

	if (dir == NULL || !isroot || !isroot2 || !isddash)
	{
		cd_to_home(datash);
		return (1);
	}

	if (_strcmp("-", dir) == 0)
	{
		cd_previous(datash);
		return (1);
	}

	if (_strcmp(".", dir) == 0 || _strcmp("..", dir) == 0)
	{
		cd_dot(datash);
		return (1);
	}

	cd_to(datash);

	return (1);
}
