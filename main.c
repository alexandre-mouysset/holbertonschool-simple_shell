#include "main.h"

/**
 * main - Simple shell that reads and executes commands
 * @argc: Argument count (unused)
 * @argv: Argument vector (unused)
 * @envp: Environment variables
 *
 * Return: 0 on success, 1 on failure
 */
int main(int argc, char **argv, char **envp)
{
	char *line;
	char **env;
	int i;
	int exit_status;

	(void)argc;
	(void)argv;

	env = local_env(envp);
	if (env == NULL)
		return (1);

	exit_status = 0;

	while (1)
	{
		prompt();
		line = read_line();
		if (line == NULL)
		{
			if (isatty(STDIN_FILENO))
				printf("\nEND OF FILE\n");
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) > 0)
			exit_status = execute_command(line, env);

		free(line);
	}

	for (i = 0; env[i] != NULL; i++)
		free(env[i]);
	free(env);

	return (exit_status);
}
