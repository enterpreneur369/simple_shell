#include "shell.h"
/**
 * main - Holberton Shell
 * Return: 0 on success.
 */
int main(void)
{
	char *string;
	pid_t child;
	size_t MaxSize = 1024;
	int ret;
	char **toktok;
	char *exi = "exit";
	char *envi = "env";
	char *validate = "\n";

	signal(SIGINT, handler);
	while (ret != EOF)
	{
		string = malloc(MaxSize);
		if (string == NULL)
			exit(98);
		write(STDOUT_FILENO, "hsh$ ", 5);
		ret = getline(&string, &MaxSize, stdin);
		/* validating \n */
		if (strcmp(string, validate) == 0)
			continue;
		/* Validate Ctrl+D Keyword */
		if (ret < 0)
		{
			write(1, "\n", 1);
			exit(EXIT_FAILURE);
		}
		/* converting in tokens */
		toktok = tokens(string);
		/*fork the process */
		child = fork();
		if (child == -1)
		{
			perror("Error:");
			return (1);
		}
		if (child == 0)
		{
			if (toktok == NULL)
			{
				free (string);
				exit(EXIT_SUCCESS);
			}
			if (strcmp(toktok[0], envi) == 0)
				_printenv();
			else if (strcmp(toktok[0], exi) == 0)
			{
				_free(toktok);
				exit(EXIT_SUCCESS);
			}
			else
			{
				_path(toktok);
			}
			exit(EXIT_SUCCESS);
		}
		else
		{
			wait(NULL);
			if (strcmp(toktok[0], exi) == 0)
			{
				_free(toktok);
				exit(EXIT_SUCCESS);
			}
		}
		free(string);
		_free(toktok);
	}
	return (0);
}