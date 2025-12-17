#include "main.h"


char *get_path(char **env)
{
    int i = 0;
    
    while (env[i])
    {
        if (strncmp(env[i], "PATH=", 5) == 0) /* If match, equals 0 */
            return (env[i + 5]);			/* +5 to go to the next string ("PATH=") = 5..*, returns pointer */
        i++;
    }
    return (NULL);
}
