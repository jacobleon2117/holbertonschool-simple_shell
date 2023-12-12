#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/wait.h>

void execute_command(char *command, char *arguments[]) {
    pid_t pid = fork();

    if (pid == 0) {
        // Child process
        execvp(command, arguments);
        // If execvp fails, print an error and exit
        perror("Execution failed");
        exit(EXIT_FAILURE);
    } else if (pid < 0) {
        // Fork failed
        perror("Fork failed");
    } else {
        // Parent process
        int status;
        waitpid(pid, &status, 0);

        if (WIFEXITED(status)) {
            int exit_status = WEXITSTATUS(status);
            if (exit_status != 0) {
                fprintf(stderr, "Command '%s' failed with exit status %d\n", command, exit_status);
            }
        } else if (WIFSIGNALED(status)) {
            fprintf(stderr, "Command '%s' terminated by signal %d\n", command, WTERMSIG(status));
        }
    }
}

