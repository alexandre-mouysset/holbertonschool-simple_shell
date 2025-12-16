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

		token = split_line(&line);

		while (token)
		{
			execute_command(token);
			token = split_line(&line);
		}

		free(line);
	}

	return (0);
}
