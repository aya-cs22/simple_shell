#include "main.h"

/**
 * main - Entry point
 * @argc: Number of arguments
 * @argv: Array of arguments
 * Return: 0 on success, -1 on failure
 */

int main(int argc, const char *argv[])
{
	(void)argc;
	(void)argv;

	if (isatty(STDIN_FILENO) == 1)
	{
		interacrive();
	}
	else
	{
		noninteractive();
	}
	return (0);
}
