#include "shell.h"
/**
 * main -
 *
 *
 *
 *
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

	while (ret != EOF)
	{
		string = malloc(MaxSize);
		if (string == NULL)
			exit(98);
		write(STDOUT_FILENO,"hsh$ ", 5);
		ret = getline(&string, &MaxSize, stdin);
		/* converting in tokens */
		toktok = tokens(string);
		/*fork the process */
		child = fork();
		if (child == 0)
		{
			if (strcmp(toktok[0],exi) == 0)
			{
				free(toktok);
				exit(EXIT_SUCCESS);
			}
			if (stat(toktok[0], &st) == 0)
			{
				execve(toktok[0], toktok, NULL);
			}
			else if (stat(toktok[0], &st) == -1);
			{
				_path(toktok);
			}
		}
		else
		{
			wait(NULL);
				if (strcmp(toktok[0],exi) == 0)
			{
				free(toktok);
				exit(EXIT_SUCCESS);
			}
		}
		free (string);
	}
	return(0);
}
