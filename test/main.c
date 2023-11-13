#include "main.h"

int main (int argc, char **argv[])
{
        ssize_t charsread = 0;
        char *buffer = NULL;
        char *buffercpy = NULL;
        size_t n = 0;
        char *token = NULL;
        int tokens_count = 0, i = 0;
        (void)argc;

        while(1)
        {
        printf("#cisfun$: ");
        charsread = getline(&buffer, &n, stdin);
        if (charsread == -1)
        {
            exit(-1);
        }
        buffercpy = malloc(sizeof(char) * charsread);
        if (buffercpy == NULL)
        {
            perror("ERROR");
            return (-1);
        }
        strcpy(buffercpy, buffer);
        token = strtok(buffer, " ");
        while (token != NULL)
        {
            tokens_count++;
            token = strtok(NULL, " ");
        }
        tokens_count++;
        argv = malloc(sizeof(char *) * tokens_count);
        token = strtok(buffercpy, " ");
        while (token != NULL)
        {
            argv[i]= malloc(sizeof(char) * (strlen(token) + 1));
            strcpy(*argv[i], token);
            token = strtok(NULL, " ");
            i++;
        }
        argv[i] = NULL;
        free(argv);
        free(buffercpy);
        free(buffer);
    }
    return (0);
}
