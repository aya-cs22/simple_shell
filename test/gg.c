#include "main.h"
#include <sys/wait.h>

int main(int argc, const char *argv[])
{
    ssize_t charsread = 0;
    char *buffer = NULL;
    char **argvptr;
    size_t n = 0;
    (void)argc;

    argvptr = malloc(sizeof(char *) * 2);
    if (argvptr == NULL)
    {
        perror("ERROR:");
        return (-1);
    }

    while (1)
    {
        printf("#cisfun$: ");
        charsread = getline(&buffer, &n, stdin);
        if (charsread == -1)
        {
            perror("ERROR:");
            free(argvptr);
            free(buffer);
            return (-1);
        }

        if (buffer[charsread - 1] == '\n')
            buffer[charsread - 1] = '\0';

        argvptr[0] = malloc(sizeof(char) * (strlen(buffer) + 1));
        if (argvptr[0] == NULL)
        {
            perror("ERROR:");
            free(argvptr);
            free(buffer);
            return (-1);
        }

        strcpy(argvptr[0], buffer);
        argvptr[1] = NULL;

        pid_t child_pid = fork();

        if (child_pid == -1)
        {
            perror("fork");
            free(argvptr[0]);
            free(argvptr);
            free(buffer);
            return -1;
        }

        if (child_pid == 0)
        {
            // Child process
            if (execve(argvptr[0], argvptr, NULL) == -1)
            {
                perror("execve");
                free(argvptr[0]);
                free(argvptr);
                free(buffer);
                _exit(EXIT_FAILURE);
            }
        }
        else
        {
            // Parent process
            int status;
            waitpid(child_pid, &status, 0);
        }

        free(argvptr[0]);
    }

    free(buffer);
    free(argvptr);
    return 0;
}
