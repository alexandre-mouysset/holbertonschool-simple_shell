#include "main.h"

/**
 * local_env - Initializes a copy of the environment variables
 *
 * @envp: Array of environment variables
 *
 * Return: Pointer to the new environment array, or NULL on failure
 */
char **local_env(char **envp)
{
	int i, j;
	int count = 0;
	char **env;

	while (envp[count] != NULL)
		count++;

	env = malloc(sizeof(char *) * (count + 1));

	if (env == NULL)
	{
		return (NULL);
	}

	for (i = 0; i < count; i++)
	{
		env[i] = strdup(envp[i]);

		if (env[i] == NULL)
		{
			for (j = 0; j < i; j++)
				free(env[j]);
			free(env);
			return (NULL);
		}
	}
	env[count] = NULL;
	return (env);
}

/**
 * get_path - Retrieves the value of the PATH environment variable
 *
 * @env: Array of environment variables
 *
 * Return: Pointer to the PATH value, or NULL if not found
 */
char *get_path(char **env)
{
	int i = 0;

	while (env[i])
	{
		if (strncmp(env[i], "PATH=", 5) == 0) /* If match, equals 0 */
			return (env[i] + 5);			  /* +5 to go to the next string ("PATH=") = 5..* */

		i++;
	}
	return (NULL);
}
