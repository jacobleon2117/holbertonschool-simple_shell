#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *command) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        char *commandCopy = malloc(strlen(command) + 1); // +1 for the null terminator
        if (commandCopy == NULL) {
            perror("Memory allocation failed");
            exit(EXIT_FAILURE);
        }

        strcpy(commandCopy, command);

        execlp(commandCopy, commandCopy, (char *)NULL);
        
         // If execlp fails, print an error and exit
        perror("Execution failed");
        free(commandCopy); // Release the allocated memory
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        /* Fork failed */
        perror("Fork failed");
    } else {
        /* Parent process */
        int status;
        waitpid(pid, &status, 0);
/* Checks if the child process exited normally. This macro returns true if the child terminated normally. */
        if (WIFEXITED(status)) { /* retrieves the exit status of the child process. */
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0) {
                fprintf(stderr, "Command '%s' failed with exit status %d\n", command, exit_status);
            }
        } else if (WIFSIGNALED(status)) { /* If the child process did not exit normally, this condition checks if it terminated due to a signal. */
            /* Prints an error message to stderr indicating that the command terminated by a signal. */
            fprintf(stderr, "Command '%s' terminated by signal %d\n", command, WTERMSIG(status));
        }
    }
}

