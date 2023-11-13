#include "main.h"
/**
 * execute_file - excutes a file
 * @command: command to execute
 * Return: 0 on success, -1 on failure
 */
int execute_file(char *buffer)
{
	int status;
	pid_t id;
	char **argvptr = malloc(sizeof(char *) * 2);

	if (argvptr == NULL)
	{
		perror("ERROR:");
		return (-1); }
	argvptr[0] = strdup(command);
	argvptr[1] = NULL;
	if (argvptr[0] == NULL)
	{
		perror("ERROR:");
		free(argvptr);
		free(command);
		return (-1); }
	id = fork();
	if (id == -1)
	{
		perror("FORK:");
		free(argvptr[0]);
		free(argvptr);
		free(command);
		return (-1); }
	if (id == 0)
	{
		if (execve(argvptr[0], argvptr, NULL) == -1)
		{
			perror("ERROR:");
			free(argvptr[0]);
			free(argvptr);
			free(command);
			_exit(EXIT_FAILURE); } }
	wait(&status);
	free(argvptr[0]);
	free(argvptr);
	free(command);
	return (0);
}
