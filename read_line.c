#include "main.h"

/**
 * read_line - Reads a line of input from standard input (stdin)
 *
 * Description: This function uses getline to read a full line from stdin.
 *              Memory for the line is dynamically allocated. The caller
 *              is responsible for freeing the memory. If an error occurs
 *              or end-of-file (EOF) is reached, any allocated memory is
 *              freed and the function returns NULL.
 *
 * Return: Pointer to the line read (must be freed by the caller),
 *         or NULL on EOF or error.
 */
char *read_line(void)
{
	char *line = NULL;
	size_t size = 0;
	ssize_t nread;

	nread = getline(&line, &size, stdin);

	if (nread == -1)
	{
		free(line);
		return (NULL);
	}
	return (line);
}
