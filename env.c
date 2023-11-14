#include "main.h"

/**
 * _getenv - prints the environment to putput
 * Return: void
*/

void _getenv(void)
{
	int i = 0;
	char **env = environ;

	while (env[i] != NULL)
	{
		write(STDOUT_FILENO, env[i], strlen(env[i]));
		write(STDOUT_FILENO, "\n", 1);
		i++;
	}
}
