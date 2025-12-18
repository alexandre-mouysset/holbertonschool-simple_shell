#include <stdlib.h>

/**
 * split_path - splits a PATH string into an array of strings
 * @path: the PATH string
 *
 * Return: pointer to array of strings, NULL on failure
 */
char **split_path(char *path)
{
	char **array;  /* Each char is a directory in the PATH */
	char *path_copy; /* To not modify PATH */
	char *token; /* Will be the the folders in path */
	int i = 0;

	if (!path)
		return (NULL);

	path_copy = strdup(path); /* To not modify PATH */
	if (!path_copy)
		return (NULL);

	array = malloc(sizeof(char *) * 1024); /* Allocates memory for pointers to the strings */
	if (!array)
	{
		free(path_copy);
		return (NULL);
	}

	token = strtok(path_copy, ":"); /* Tokenizes the path string */
	while (token) /* Loops through all folders */
	{
		array[i] = strdup(token);
		if (!array[i])
		{
			while (i--)
				free(array[i]);
			free(array);
			free(path_copy);
			return (NULL);
		}
		i++;
		token = strtok(NULL, ":");
	}
	array[i] = NULL;

	free(path_copy);
	return (array);
}
