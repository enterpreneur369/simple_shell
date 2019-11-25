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
	char *string;
	pid_t child;
	size_t MaxSize = 1024;
	int ret, check;
	char **toktok;

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
			if (execve(toktok[0], toktok, NULL) == -1)
			
		}
		else
		{
			wait(NULL);
		}
		free (string);
	}
	return(0);
}
