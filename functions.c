#include "shell.h"
/**
 * *_strcmp - compare two strings
 * @s1: string 1
 * @s2: string 2
 * Return: void
 */
int _strcmp(char *s1, char *s2)
{
	int i = 0;

	while (s1[i] == s2[i])
	{
		if (s1[i] == '\0' && s2[i] == '\0')
		{
			break;
		}
		i++;
	}
	return (s1[i] - s2[i]);
}
/**
 * *_strcpy - copies string pointed to srd
 * @dest: dest array
 * @src: src array
 * Return: pointer to dest
 */
char *_strcpy(char *dest, char *src)
{
	int i;

	for (i = 0; src[i] != '\0'; i++)
	{
		dest[i] = src[i];
	}
	dest[i] = '\0';
	return (dest);
}
/**
 * _strlen - swap value of two intergers
 * @s: string
 * Return: void
 */
int _strlen(char *s)
{
	int c = 0;

	while (s[c] != '\0')
	{
		c++;
	}
	return (c);
}
char *_strdup(char *str)
{
	char *a;

	if (str == '\0')
	{
		return (NULL);
	}
	a = malloc(_strlen(str) * sizeof(char) + 1);
	if (a == '\0')
	{
		return (NULL);
	}
	_strcpy(a, str);
	return (a);
}