#include "main.h"

/**
 * prompt - Displays the shell prompt if input is a terminal
 *
 * Description: This function prints a custom prompt including the fixed
 *              username "Alexandre@Nabil", the current working directory,
 *              and the "$ " symbol. It only displays the prompt if the
 *              standard input (stdin) is connected to an interactive terminal.
 *
 * Return: Nothing (void)
 */
int prompt(void)
{
	char cwd[1000];

	/* Check if we are in a terminal */
	if (isatty(STDIN_FILENO))
	{
		if (getcwd(cwd, sizeof(cwd)) != NULL)
		{
			write(1, "Alexandre@Nabil", 15);
			write(1, cwd, strlen(cwd));
			write(1, "$ ", 2);
		}
		else
			write(2, "Impossible to get the current working directory\n", 48);
	}

return (0);
}
