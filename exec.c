#include "main.h"

/**
 * execute_file - excutes a file
 * @command: a line command to execute
 * Return: 0 on success, -1 on failure
*/

int execute_file(char **command)
{
	int status;
	pid_t id;

	if (access((const char *)command[0], F_OK) != 0)
	{
		return (-1);

	}
	id = fork();
	if (id == 0)
	{
		if (execve(command[0], command, environ) == -1)
		{
			perror(command[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		waitpid(id, &status, 0);
		free(command[0]);
	}
	return (WEXITSTATUS(status));
}
