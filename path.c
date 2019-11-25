#include "shell.h"
extern char **environ;
/**
 *
 *
 *
 */
char *_getenv(const char *name)
{
    int i = 0;
    char *ret;

    while (environ[i] != NULL)
    {
        ret = strtok(environ[i], "=");
        if(strcmp(ret, (char *)name) == 0)
        {
            ret = strtok(NULL, "\0");
            break;
        }
        i++;
    }
    return(ret);

}

char *_which(char *str1, char *str2)
{
    int len1, len2, i = 0, b = 0;
    char *newstr;

    len1 = strlen(str1);
    len2 = strlen(str2);

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
		    argv[0] = malloc(strlen(str) + 1);
		    strcpy(argv[0], str);
		    break;
        }
        path = strtok(NULL, ":");
        i++;
    }
    execve(argv[0], argv, NULL);
    return (0);
}