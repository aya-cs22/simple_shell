#include "main.h"

/**
 * execute_file - excutes a file
 * @command: a line command to execute
 * @argv: arguments to pass to the command line
 * Return: 0 on success, -1 on failure
*/

int execute_file(char *command, char **argv)
{
	int status;
	pid_t id;


	id = fork();
	if (id == -1)
	{
		perror("FORK:");
		free(command);
		return (-1);
	}
	if (id == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror("ERROR:");
			_exit(EXIT_FAILURE);
		}
	}
	wait(&status);
	free(command);
	return (0);
}
