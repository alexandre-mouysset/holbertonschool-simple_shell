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
    pid_t pid;
    int argc;
    int status;
    char *path;
    char *path_copy;
    char *directory;
    char full_path[1000];
    char *line_copy;

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

    pid = fork();
    if (pid == -1)
    {
        free(line_copy);
        return (1);
    }

    if (pid == 0)
    {
        if (strchr(argv[0], '/') != NULL)
        {
            execve(argv[0], argv, env);
            fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
            free(line_copy);
            exit(127);
        }

        path = get_path(env);
        if (path)
        {
            path_copy = strdup(path);
            if (path_copy != NULL)
            {
                directory = strtok(path_copy, ":");

                while (directory)
                {
                    sprintf(full_path, "%s/%s", directory, argv[0]);
                    execve(full_path, argv, env);
                    directory = strtok(NULL, ":");
                }

                free(path_copy);
            }
        }

        fprintf(stderr, "./hsh: 1: %s: not found\n", argv[0]);
        free(line_copy);
        exit(127);
    }

    wait(&status);
    free(line_copy);
    return (WEXITSTATUS(status));
}
