#include "shell.h"
/**
 * main - Holberton Shell
 * Return: 0 on success.
 */
int main(void)
{
	char *string = NULL;
	pid_t child;
	size_t MaxSize = 1024;
	int ret;
	char **toktok = NULL;
	char *exi = "exit\n";
	char *envi = "env\n";
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
		if (_strcmp(string, validate) == 0)
			continue;
		/* Validate Ctrl+D Keyword */
		if (ret < 0)
		{
			write(1, "\n", 1);
			free(string);
			exit(EXIT_FAILURE);
		}
		if (_strcmp(string, envi) == 0)
		{
			_printenv();
			free(string);
		}
		else if (_strcmp(string, exi) == 0)
		{
			free(string);
			exit(EXIT_SUCCESS);
		}
		/*fork the process */
		child = fork();
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
			free (string);
		}
	}
	return (0);
}