#include "shell.h"
/**
 * _getenv - function that gets all PATH line
 * @name: environment variable to find
 * Return: Array of PATH line
 */
char *_getenv(const char *name)
{
	int i = 0;
	char *ret;

	while (environ[i] != NULL)
	{
		ret = strtok(environ[i], "=");
		if (_strcmp(ret, (char *)name) == 0)
		{
			ret = strtok(NULL, "\0");
			break;
		}
		i++;
	}
	return (ret);
}

/**
 * _which - function that locate a command in PATH envir
 * @str1: path where will find the command
 * @str2: Command to find
 * Return: Array of complete path of the command
 */
char *_which(char *str1, char *str2)
{
	int len1, len2, i = 0, b = 0;
	char *newstr;

	len1 = _strlen(str1);
	len2 = _strlen(str2);

	newstr = malloc((len1 + len2) + 2);
	while (str1[i] != '\0')
	{
		newstr[i] = str1[i];
		i++;
	}
	newstr[i] = '/';
	i++;
	while (str2[b] != '\0')
	{
		newstr[i] = str2[b];
		i++;
		b++;
	}
	newstr[i] = '\0';
	return (newstr);
	free(newstr);
}

/**
 * _path - Function that find the path of shell programs
 * in PATH env variable
 * @argv: input token arguments
 * Return: 0 on success,
 * -1 if command doesn't found
 */
int _path(char **argv)
{
	char *path;
	char *str;
	struct stat st;
	unsigned int i;

	path = _getenv("PATH");
	path = strtok(path, ":");
	i = 0;
	while (path != NULL)
	{
		str = _which(path, argv[0]);
		if (stat(str, &st) == 0)
		{
			argv[0] = malloc(_strlen(str) + 1);
			_strcpy(argv[0], str);
			break;
		}
		path = strtok(NULL, ":");
		i++;
	}
	execve(argv[0], argv, NULL);
	write(2, "not found\n", 10);
	free(path);
	free(str);
	_free(argv);
	return (0);
}
