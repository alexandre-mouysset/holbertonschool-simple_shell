#include "main.h"

/**
 * execute_command - Executes a command given as a string
 *
 * @line: Command to execute
 *
 * Return: 0 on success, 1 on failure
 */
int execute_command(char *line)
{
	char *argv[100];
	char *token;
	pid_t pid;
	int i = 0;

	if (line == NULL)
		return (1);

	token = strtok(line, " \t");

	while (token && i < 99)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	if (i == 0)
		return (0);

	pid = fork();

	if (pid == -1)
		return (1);

	else if (pid == 0)
	{
		execve(argv[0], argv, NULL);

		fprintf(stderr, "Error: command does not exist -> %s\n", argv[0]);
		exit(-1);
	}

	else
		wait(NULL);

	return (0);
}
