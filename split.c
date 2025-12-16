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
	int i = 0;

	if (line == NULL)
		return (0);

	token = strtok(line, " \t\n");
	while (token && i < 99)
	{
		argv[i++] = token;
		token = strtok(NULL, " \t\n");
	}
	argv[i] = NULL;

	return (i);
}

/**
 * split_line - Get next line from buffer and trim spaces
 *
 * @buffer: Pointer to pointer to buffer (line from read_line)
 *
 * Return: Pointer to trimmed line, or NULL if no more lines
 */
char *split_line(char **buffer)
{
	static char *saveptr;
	char *line;
	char *end;

	if (buffer != NULL && *buffer != NULL)
		saveptr = *buffer;

	if (saveptr == NULL)
		return (NULL);

	line = strtok(saveptr, "\n");

	saveptr = NULL;

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
