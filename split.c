#include "main.h"

/**
 * split_command - Split a command line into arguments
 *
 * @line: Command line to split
 * @argv: Array to store the arguments
 *
 * Return: Number of arguments parsed
 */
int split_command(char *line, char **argv)
{
	char *token;
	int i;

	i = 0;

	if (line == NULL)
		return (0);

	token = strtok(line, " \t");

	while (token && i < 99)
	{
		argv[i] = token;
		i++;
		token = strtok(NULL, " \t");
	}
	argv[i] = NULL;

	return (i);
}

/**
 * split_line - Get next line from buffer and trim spaces
 *
 * @buffer: Buffer to parse
 *
 * Return: Pointer to trimmed line or NULL
 */
char *split_line(char **buffer)
{
	char *line;
	char *end;

	if (buffer == NULL || *buffer == NULL)
		return (NULL);

	line = strtok(*buffer, "\n");

	*buffer = NULL;

	if (line == NULL)
		return (NULL);

	while (*line == ' ' || *line == '\t')
		line++;

	end = line + strlen(line) - 1;

	while (end > line && (*end == ' ' || *end == '\t'))
	{
		*end = '\0';
		end--;
	}

	if (*line == '\0')
		return (NULL);

	return (line);
}
