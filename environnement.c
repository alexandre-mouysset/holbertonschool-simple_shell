#include "main.h"

/**
 * init_env - Initializes a copy of the environment variables
 *
 * @envp: Array of environment variables
 *
 * Return: Pointer to the new environment array, or NULL on failure
 */
char **init_env(char **envp)
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
