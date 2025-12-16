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
	pid_t pid;
	int i;

	if (line == NULL)
		return (1);

	i = split_command(line, argv);

	if (i == 0)
		return (0);

	pid = fork();

	if (pid == -1)
		return (1);

	if (pid == 0)
	{
		execve(argv[0], argv, NULL);
		fprintf(stderr, "Error: command does not exist -> %s\n", argv[0]);
		exit(-1);
	}

	wait(NULL);

	return (0);
}
