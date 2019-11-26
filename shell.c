#include "shell.h"
/**
 * main - Holberton Shell
 * Return: 0 on success.
 */
int main(void)
{
	struct stat st;
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
			if (strcmp(toktok[0], envi) == 0)
				_printenv();
			if (strcmp(toktok[0], exi) == 0)
			{
				_free(toktok);
				exit(EXIT_SUCCESS);
			}
			if (stat(toktok[0], &st) == 0)
			{
				if (execve(toktok[0], toktok, NULL) == -1)
					perror("Error:");
			}
			else if (stat(toktok[0], &st) == -1)
			{
				if (_path(toktok) == -1)
				{
					write(1, "hsh: ", 5);
					write(1, "1: ", 3);
					write(1, string, strlen(string));
					write(1, ": ", 2);
					write(1, "not found\n", 10);
				}
			}
			free(string);
			_free(toktok);
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
		free (string);
		_free(toktok);
	}
	return (0);
}
