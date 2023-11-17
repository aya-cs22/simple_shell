#include "main.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, -1 on failure
 */

int main(int argc, const char *argv[])
{
	char *buffer = NULL, **bufptr = NULL, *fullpath = NULL;
	int status = 0, i, temp = 0;
	(void)argc;
	(void)argv;

	while (1)
	{
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, "#cisfun$: ", 10);
		buffer = tem_getline();
		if (buffer == NULL)
		{
			free(buffer);
			return (status);
			exit(0); }
		bufptr = tmp_strtok(buffer);
		if (!bufptr)
			continue;
		if (strncmp(bufptr[0], "exit", 4) == 0)
		{
			free(buffer), free(bufptr);
			bufptr = NULL;
			if ((status != temp) && (status != 0))
				temp = status;
			exit(temp);	}
		if (strcmp(bufptr[0], "env") == 0)
			_getenv();
		fullpath = getpath(bufptr[0]);
			if (fullpath == NULL)
			fullpath = bufptr[0];
		bufptr[0] = fullpath;
		if (execute_file(bufptr) == -1)
			perror(getenv("_"));
		free(fullpath);
		for (i = 0; bufptr[i] != NULL; i++)
			free(bufptr[i]);
		free(bufptr);
		if (fullpath != bufptr[0])
			free(fullpath); }
	return (status);
}
