#include "shell.h"
/**
 * tokens - divide the string into tokens
 *
 *
 *
 */
char **tokens(char *string)
{
	char **savingtok;
	char *token;
	int i = 0, ntok = 0;
	char *tmp;

	tmp = strdup(string);
	tmp = strtok(tmp, " \n\t");
	while (tmp != NULL)
	{
		ntok++;
		tmp = strtok(NULL, " \n\t");
	}

	savingtok = malloc((ntok * sizeof(char *)) + 1);
	token = strdup(string);
	token = strtok(token, " \n\t");
	while (token != NULL)
		{
			savingtok[i] = strdup(token);
			i++;
			token = strtok(NULL, " \n\t");
		}
		savingtok[ntok + 1] = NULL;

		free(tmp);
		free(token);
	return (savingtok);
}