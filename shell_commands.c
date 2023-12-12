#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <string.h>

void execute_command(char *command) {
   char *args[MAX_INPUT_SIZE];
   char *token;
   int i = 0;

   // Parse the command into a program name and arguments
   token = strtok(command, " ");
   while (token != NULL) {
       args[i] = token;
       i++;
       token = strtok(NULL, " ");
   }
   args[i] = NULL;

   pid_t pid = fork();

   if (pid == 0) {
       // Child process
       execvp(args[0], args);

       // If execvp fails, print an error and exit
       perror("Execution failed");
       exit(EXIT_FAILURE);
   } else if (pid < 0) {
       /* Fork failed */
       perror("Fork failed");
   } else {
       /* Parent process */
       int status;
       if (waitpid(pid, &status, 0) == -1) perror("waitpid");

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


