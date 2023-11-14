#include "main.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, -1 on failure
 */
int main(int argc, const char *argv[])
{
		char *buffer = NULL;
		char **bufptr = NULL;
		(void)argc;
		(void)argv;

		while (1)
		{
		write(STDOUT_FILENO, "#cisfun$: ", 11);
		buffer = tem_getline();
		bufptr = tmp_strtok(buffer);
		if (execute_file(bufptr[0], bufptr) == -1)
		{
			perror("ERROR:");
			return (-1); } }
		free(buffer);
		return (0);
}
