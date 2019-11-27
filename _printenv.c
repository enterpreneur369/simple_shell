#include "shell.h"
/**
 * _printenv - print enviroment
 *
 */
void _printenv(void)
{
	char **ep;
	int i = 0;

	ep = environ;
	while (ep[i] != NULL)
	{
		write(1, ep[i], _strlen(ep[i]));
		write(1, "\n", 1);
		i++;
		}
}
