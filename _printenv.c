#include "shell.h"
/**
 * _printenv - function that loop and print env variable
 * Return: Nothing
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
