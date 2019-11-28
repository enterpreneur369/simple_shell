#include "shell.h"
/**
 * main - Holberton Shell
 * @ac: counter of argumments to receive
 * @av: pointer to args to receive
 * Return: 0 on success.
 */
int main(int ac, char **av)
{
	char *string = NULL;
	pid_t child;
	size_t MaxSize = 1024;
	int ret = 0, errors = 1;
	char **toktok = NULL;
	char *exi = "exit\n";
	char *envi = "env\n";
	char *validate = "\n";
	(void)ac;

	signal(SIGINT, handler);
	while (1)
	{
		if (isatty(0) == 1)
			write(STDOUT_FILENO, "hsh$ ", 5);
		ret = getline(&string, &MaxSize, stdin);
		/* validating \n */
		ctrl_d(ret, string);
		if (_strcmp(string, envi) == 0)
		{
			_printenv();
		}
		if (_strcmp(string, exi) == 0)
		{
			exit(EXIT_SUCCESS);
		}
		if (_strcmp(string, validate) == 0)
			continue;

		child = fork();
		if (fork_process(child, string, toktok) == -1)
		{
			validate_input(&string, av[0], errors);
			exit(EXIT_FAILURE);
		}
		errors++;
	}
	return (0);
}
