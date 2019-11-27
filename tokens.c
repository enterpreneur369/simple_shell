#include "shell.h"
/**
 * tokens - divide the string into tokens
 * @string: input string buffer saved in getline
 * Return: Pointer to array of tokens
 */
char **tokens(char *string)
{
	char **savingtok;
	char *token;
	int i = 0, ntok = 0;
	char *tmp;

	tmp = _strdup(string);

	tmp = strtok(tmp, " \n\t");
	while (tmp != NULL)
	{
		ntok++;
		tmp = strtok(NULL, " \n\t");
	}

	savingtok = malloc((_strlen(string) * sizeof(char *)));
	token = _strdup(string);
	token = strtok(token, " \n\t");
	if (token == NULL)
	{
		_free(savingtok);
		return (NULL);
	}
	while (token != NULL)
	{
		savingtok[i] = _strdup(token);
		i++;
		token = strtok(NULL, " \n\t");
	}
		savingtok[ntok] = '\0';

		free(tmp);
		free(token);
	return (savingtok);
}
