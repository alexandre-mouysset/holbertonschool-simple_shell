#include "main.h"

/**
 * main - Simple shell that reads and executes commands
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;
	char *token;
	char *saveptr = NULL;

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

		saveptr = line;
		token = split_line(&saveptr);

		while (token)
		{
			execute_command(token);
			token = split_line(&saveptr);
		}

		free(line);
	}

	return (0);
}
