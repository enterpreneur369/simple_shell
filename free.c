#include "shell.h"
/**
 * _free - function to free a double pointer
 *
 *
 */
void _free(char **string)
{
	size_t i = 0;

	if(string == NULL)
		perror("error");
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	if (string[i] == NULL)
		free(string[i]);
	free(string);
}
