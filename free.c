#include "shell.h"
/**
 * _free - function to free a double pointer
 * @string: Pointer to array to free in heap memory
 * Return: Nothing
 */
void _free(char **string)
{
	size_t i = 0;

	if(string == NULL)
		return;
	while (string[i] != NULL)
	{
		free(string[i]);
		i++;
	}
	if (string[i] == NULL)
		free(string[i]);
	free(string);
}
