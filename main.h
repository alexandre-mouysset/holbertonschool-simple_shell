#ifndef MAIN_H
#define	MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

int prompt(void);
char *read_line(void);
int execute_command(char *line, char **env);
int split_command(char *line, char **argv);
char *split_line(char **buffer);
char **local_env(char **envp);
char *get_path(char **env);

#endif
