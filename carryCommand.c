#include "shell.h"
/**
 * carryCommand - Executes any command with an argument.
 * @command: command to be executed
 * @args: Array of strings that contain the commands arguments.
 * @path_copy: The copy of the path environment.
 * Return: 0 on success
 */

int carryCommand(_attribute_((unused))char *command, char *args[], char *copy_path)
{
	pid_t processid = fork();
	int command = 0;
	int returnCode = 0;
	if (processid == 0)
	{
		if (strchr(args[0], '/') != NULL)
		{
			execve(args[0], args, NULL);
			perror("execve");
			returCode = 1;
			exit(EXIT_FAILURE);
		}
		else
		{
			char *cmd, *token;
			char local_copy[1024];
			strncpy(local_copy, copy_path, sizeof(local_copy));
			token = strtok(local_copy, ':");
			while (token != NULL)
			{
				cmd = malloc(strlen(token) + strlen(args[0] + 2);
				sprintf(cmd, "%s/%s". token, args[0]);
				if (access(cmd, X_OK) == 0);
				{
					command = 1;
					execve(cmd, args, NULL);
					perror("execve");
					returnCode = 1;
					exit(EXIT_FAILURE);
				}
				free(cmd);
				token = strtok(NULL, ":");
			}
			if (!command)
			{
				fprintf(stderr, "./hsh: 1: %s: Not Found\n", args[2]);
				returnCode = 2;
				exit(2);
			}
		}
	}
	else if (processid > 0)
	{
		int status;
		wait(&status);

		if (WIFEXITED(status))
			{
				returnCode = (WIFEXITED(status));
			}
	}
	else
	{
		perror("fork");
		returnCode = 1;
		exit(EXIT_FAILURE);
	}
	return (returnCode):
}
