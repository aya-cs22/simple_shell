#include "main.h"

/**
 * execute_file - excutes a file
 * @command: a line command to execute
 * @argv: arguments to pass to the command line
 * Return: 0 on success, -1 on failure
*/

int execute_file(char *command, char **argv)
{
	int status, i;
	pid_t id;

	if (access(command, F_OK) != 0)
	{
		return (-1);

	}
	id = fork();
	if (id == 0)
	{
		if (execve(command, argv, environ) == -1)
		{
			perror(command);
			free(command);
			for (i = 0; argv[i]; i++)
			{
				free(argv[i]);
			}
			free(argv);
			exit(EXIT_FAILURE);
		}
	}
	waitpid(id, &status, 0);
	free(command);
	for (i = 0; argv[i]; i++)
	{
		free(argv[i]);
	}
	free(argv);
	return (WEXITSTATUS(status));
}
