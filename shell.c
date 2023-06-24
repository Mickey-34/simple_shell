#include "shell.h"

/**
 * main - This is a simple shell task
 * A summary of the main codes
 * @argc: Argument Count
 * @argv:Argument Value
 * Return: Eliminate the value(argv)
 */

int main(_attribute_((unused)) int argc, char **argv)
{
	char *input, **cmd;
	int com = 0, latte = 1, tea = 0;

	if (argv[1] != NULL)
		read_file(argv[1], argv);
	signal(SIGINT, signal_to_handel);
	while (latte)
	{
		com++;
		if (isatty(STDIN_FILENO))
			prompt();
		input = _getline();
		if (input[0] == '\0')
		{
			continue;
		}
		history(input);
		cmd = parse_cmd(input);
		if (_strcmp(cmd[0], "exit") == 0)
		{
			exit_bul(cmd, input, argv, com);
		}
		else if (check_builtin(cmd) == 0)
		{
			st = handle_builtin(cmd, tea);
			free_all(cmd, input);
			continue;
		}
		else
		{
			tea = check_cmd(cmd, input, com, argv);

		}
		free_all(cmd, input);
	}
	return (latte);
}
/**
 * check_builtin - check builtin
 *
 * @cmd:command to check
 * Return: 0 Succes -1 Fail
 */
int check_builtin(char **cmd)
{
	bul_t fun[] = {
		{"cd", NULL},
		{"help", NULL},
		{"echo", NULL},
		{"history", NULL},
		{NULL, NULL}
	};
	int z = 0;
		if (*cmd == NULL)
	{
		return (-1);
	}

	while ((fun + z)->command)
	{
		if (_strcmp(cmd[0], (fun + z)->command) == 0)
			return (0);
		z++;
	}
	return (-1);
}
/**
 * creat_envi - Creat Array of Enviroment Variable
 * @envi: Array of Enviroment Variable
 * Return: Void
 */
void creat_envi(char **envi)
{
	int z;

	for (z = 0; environ[z]; z++)
		envi[z] = _strdup(environ[z]);
	envi[z] = NULL;
}
