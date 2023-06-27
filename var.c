#include "shell.h"

/**
 * check_env - checks if the typed variable is an env variable
 *
 * @h: head of linked list
 * @in: input string
 * @data: data structure
 * Return: no return
 */
void check_env(r_var **h, char *in, data_shell *data)
{
	int man, chr, d, van;
	char **_envr;

	_envr = data->_environ;
	for (man = 0; _envr[man]; man++)
	{
		for (d = 1, chr = 0; _envr[man][chr]; chr++)
		{
			if (_envr[man][chr] == '=')
			{
				van = _strlen(_envr[man] + chr + 1);
				add_rvar_node(h, d, _envr[man] + chr + 1, van);
				return;
			}

			if (in[d] == _envr[man][chr])
				d++;
			else
				break;
		}
	}

	for (d = 0; in[d]; d++)
	{
		if (in[d] == ' ' || in[d] == '\t' || in[d] == ';' || in[d] == '\n')
			break;
	}

	add_rvar_node(h, d, NULL, 0);
}

/**
 * check_vars - check if the typed variable is $$ or $?
 *
 * @h: head of the linked list
 * @in: input string
 * @st: last status of the Shell
 * @data: data structure
 * Return: no return
 */
int check_vars(r_var **h, char *in, char *st, data_shell *data)
{
	int z, lst, lpd;

	lst = _strlen(st);
	lpd = _strlen(data->pid);

	for (z = 0; in[z]; z++)
	{
		if (in[z] == '$')
		{
			if (in[z + 1] == '?')
				add_rvar_node(h, 2, st, lst), z++;
			else if (in[z + 1] == '$')
				add_rvar_node(h, 2, data->pid, lpd), z++;
			else if (in[z + 1] == '\n')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[z + 1] == '\0')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[z + 1] == ' ')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[z + 1] == '\t')
				add_rvar_node(h, 0, NULL, 0);
			else if (in[z + 1] == ';')
				add_rvar_node(h, 0, NULL, 0);
			else
				check_env(h, in + z, data);
		}
	}

	return (z);
}

/**
 * replaced_input - replaces string into variables
 *
 * @head: head of the linked list
 * @input: input string
 * @new_input: new input string (replaced)
 * @nlen: new length
 * Return: replaced string
 */
char *replaced_input(r_var **head, char *input, char *new_input, int nlen)
{
	r_var *indx;
	int z, d, k;

	indx = *head;
	for (d = z = 0; z < nlen; z++)
	{
		if (input[d] == '$')
		{
			if (!(indx->len_var) && !(indx->len_val))
			{
				new_input[z] = input[d];
				z++;
			}
			else if (indx->len_var && !(indx->len_val))
			{
				for (k = 0; k < indx->len_var; k++)
					d++;
				z--;
			}
			else
			{
				for (k = 0; k < indx->len_val; k++)
				{
					new_input[z] = indx->val[k];
					z++;
				}
				d += (indx->len_var);
				z--;
			}
			indx = indx->next;
		}
		else
		{
			new_input[z] = input[d];
			d++;
		}
	}

	return (new_input);
}

/**
 * rep_var - calls functions to replace string into vars
 *
 * @input: input string
 * @datash: data structure
 * Return: replaced string
 */
char *rep_var(char *input, data_shell *datash)
{
	r_var *head, *indx;
	char *status, *new_input;
	int olen, nlen;

	status = aux_itoa(datash->status);
	head = NULL;

	olen = check_vars(&head, input, status, datash);

	if (head == NULL)
	{
		free(status);
		return (input);
	}

	indx = head;
	nlen = 0;

	while (indx != NULL)
	{
		nlen += (indx->len_val - indx->len_var);
		indx = indx->next;
	}

	nlen += olen;

	new_input = malloc(sizeof(char) * (nlen + 1));
	new_input[nlen] = '\0';

	new_input = replaced_input(&head, input, new_input, nlen);

	free(input);
	free(status);
	free_rvar_list(&head);

	return (new_input);
}
