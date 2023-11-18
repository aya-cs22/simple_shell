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

	if (access(command, F_OK) != 0)
	{
		return (-1);

	}
	id = fork();
	if (id == 0)
	{
		if (execve(command, argv, NULL) == -1)
		{
			perror(argv[0]);
			free(command);
			exit(100);
		}
	}
	waitpid(id, &status, 0);
	free(command);
	return (WEXITSTATUS(status));
}
