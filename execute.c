#include "main.h"

/**
 * execute_command - Executes a command given as a string
 *
 * @line: Command to execute
 * @env: Environment variables
 *
 * Return: 0 on success, 127 on command not found, 1 on failure
 */
int execute_command(char *line, char **env)
{
    char *argv[100];
    char *argv_dup[100];
    pid_t pid;
    int argc;
    int status;
    char *path;
    char *path_copy;
    char *directory;
    char full_path[1000];
    char *line_copy;
    int i;

    if (line == NULL)
        return (1);

    line_copy = strdup(line);
    if (line_copy == NULL)
        return (1);

    argc = split_command(line_copy, argv);
    if (argc == 0)
    {
        free(line_copy);
        return (0);
    }

    /* Dupliquer les arguments avant de libérer line_copy */
    for (i = 0; i < argc; i++)
    {
        argv_dup[i] = strdup(argv[i]);
        if (argv_dup[i] == NULL)
        {
            for (int j = 0; j < i; j++)
                free(argv_dup[j]);
            free(line_copy);
            return (1);
        }
    }
    argv_dup[argc] = NULL;

    /* Libérer line_copy ici puisqu'on a dupliqué les arguments */
    free(line_copy);

    pid = fork();
    if (pid == -1)
    {
        for (i = 0; i < argc; i++)
            free(argv_dup[i]);
        return (1);
    }

    if (pid == 0)
    {
        if (strchr(argv_dup[0], '/') != NULL)
        {
            execve(argv_dup[0], argv_dup, env);
            fprintf(stderr, "./hsh: 1: %s: not found\n", argv_dup[0]);
            for (i = 0; i < argc; i++)
                free(argv_dup[i]);
            exit(127);
        }

        path = get_path(env);
        if (path && strlen(path) > 0)
        {
            path_copy = strdup(path);
            if (path_copy != NULL)
            {
                directory = strtok(path_copy, ":");

                while (directory)
                {
                    sprintf(full_path, "%s/%s", directory, argv_dup[0]);
                    execve(full_path, argv_dup, env);
                    directory = strtok(NULL, ":");
                }

                free(path_copy);
            }
        }

        fprintf(stderr, "./hsh: 1: %s: not found\n", argv_dup[0]);
        for (i = 0; i < argc; i++)
            free(argv_dup[i]);
        exit(127);
    }

    wait(&status);
    for (i = 0; i < argc; i++)
        free(argv_dup[i]);
    return (WEXITSTATUS(status));
}
