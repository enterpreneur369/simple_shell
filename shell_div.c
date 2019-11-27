#include "shell.h"
/**
 * ctrl_d - function that validate ctrl+d key
 * @ret: return getline
 * @string: buffer of line writed
 * Return: int exit status
 */
int ctrl_d(int ret, char *string)
{
	if (ret < 0)
	{
		write(1, "\n", 1);
		free(string);
		exit(EXIT_FAILURE);
	}
	else
		return (1);
}

/**
 * fork_process - function that loop and validate the main process
 * @child: id of child generated
 * @string: buffer of line writed
 * @toktok: pointer to array to tokenize lines
 * Return: int
 */
int fork_process(pid_t child, char *string, char **toktok)
{
	if (child == -1)
	{
		perror("Error:");
		return (1);
	}
	if (child == 0)
	{
		toktok = tokens(string);
		_path(toktok);
		free(string);
		_free(toktok);
		exit(EXIT_SUCCESS);
	}
	else
	{
		wait(NULL);
		free(string);
	}
	return (0);
}
