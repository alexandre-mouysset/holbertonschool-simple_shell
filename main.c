#include "main.h"

int main(void)
{
	char *line;

	while (1)
	{
		prompt();
		line = read_line();

		if (line == NULL)
		{
			printf("\nEND OF FILE\n");
			break;
		}
		if (strlen(line) > 0 && line[strlen(line) - 1] == '\n')
			line[strlen(line) - 1] = '\0';

		free(line);
	}

	return (0);
}
