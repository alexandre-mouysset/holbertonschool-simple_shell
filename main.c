#include "main.h"

/**
 * main - Simple shell that reads and executes commands
 *
 * Return: 0 on success
 */
int main(void)
{
	char *line;

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

		if (*line)
			execute_command(line);

		free(line);
	}
	return (0);
}
