#include "shell.h"
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

/*
 * main - entry point of function
 *
 *
 */

int main(void)
{
	char *MyBuffer = malloc(buffsize * sizeof(char));
	char *route = NULL, *strcheck = NULL, **token = NULL, **route = NULL;
	size_t buffsize = 1024;
	extern char **environ;
	route = get_path(environ);
	routes = tokenize(route, ":");

	if (MyBuffer == NULL)
	{
		perror("Error, Inadequate Memory");
		exit(1);
	}
	while (1)
	{
		if (isatty(STDIN_FILEND))
			printf("$ ");
		getline(&Mybuffer, &buffsize, stdin);
		if (exit_check(MyBuffer) == 1 || feof(stdin) != 0)
			break;
		strcheck = space_check(MyBuffer);
		if (strcmp(strcheck, " ") == 0 || strcmp(strcheck, "") == 0)
			continue;
		token = tokenize(strcheck, " ");
		forkit(routes, token);
		fflush(stdout);
		free_array(token);
		token = NULL;
		free(strcheck);
		strcheck = NULL;
	}
	free_array(routes);
	free(MyBuffer);
	fflush(stdout);
	free(strcheck);
	free(route);
	exit(0);
}
