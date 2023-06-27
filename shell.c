#include "shell.h"

/**
 * without_comment - deletes comments from the input
 * removes comments
 *
 * @in: input string
 * Return: input without comments
 */
char *without_comment(char *in)
{
	int z, f;

	f = 0;
	for (z = 0; in[z]; z++)
	{
		if (in[z] == '#')
		{
			if (z == 0)
			{
				free(in);
				return (NULL);
			}

			if (in[z - 1] == ' ' || in[z - 1] == '\t' || in[z - 1] == ';')
				f = z;
		}
	}

	if (f != 0)
	{
		in = _realloc(in, z, f + 1);
		in[f] = '\0';
	}

	return (in);
}

/**
 * shell_loop - Loop of shell
 * @datash: data relevant (av, input, args)
 *
 * Return: no return.
 */
void shell_loop(data_shell *datash)
{
	int v, i_eof;
	char *input;

	v = 1;
	while (v == 1)
	{
		write(STDIN_FILENO, "$ ", 4);
		input = read_line(&i_eof);
		if (i_eof != -1)
		{
			input = without_comment(input);
			if (input == NULL)
				continue;

			if (check_syntax_error(datash, input) == 1)
			{
				datash->status = 2;
				free(input);
				continue;
			}
			input = rep_var(input, datash);
			v = split_commands(datash, input);
			datash->counter += 1;
			free(input);
		}
		else
		{
			v = 0;
			free(input);
		}
	}
}
