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
	char *end;

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

		token = strtok(line, "\n");

		while (token)
		{
			while (*token == ' ' || *token == '\t')
				token++;

			end = token + strlen(token) - 1;
			while (end > token && (*end == ' ' || *end == '\t'))
			{
				*end = '\0';
				end--;
			}

			if (*token)
				execute_command(token);

			token = strtok(NULL, "\n");
		}

		free(line);
	}

	return (0);
}
