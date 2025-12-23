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
	int exit_status = 0;

	(void)argc;
	(void)argv;

	env = local_env(envp);
	if (env == NULL)
		return (1);


	while (1)
	{
		prompt();
		line = read_line();
		if (line == NULL)
		{
			break;
		}

		line[strcspn(line, "\n")] = '\0';

		if (strlen(line) > 0)
			exit_status = execute_command(line, env);

		free(line);
	}

	free_env(env);

	return (exit_status);
}
