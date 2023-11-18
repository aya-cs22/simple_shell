#include "main.h"
/**
 * tem_getline - reads a line from a file stream
 * Return: pointer to the buffer
 * NULL on failure or EOF
*/

char *tem_getline(void)
{
	ssize_t charsread = 0;
	char *buffer = NULL;
	size_t n = 0;

	charsread = getline(&buffer, &n, stdin);
		if (charsread == -1)
		{
			if (feof(stdin))
			{
				free(buffer);
				exit(EXIT_SUCCESS);
			}
			else if (ferror(stdin))
			{
				perror("ERROR reading line:");
				free(buffer);
				return (NULL);
			}
		}
		if (charsread > 0 && buffer[charsread - 1] == '\n')
			buffer[charsread - 1] = '\0';

		return (buffer);
}
