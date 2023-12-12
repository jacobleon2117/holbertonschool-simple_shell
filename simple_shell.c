#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024
/* Declares a character array input to store the user's input */
int main() {
   char input[MAX_INPUT_SIZE];
/* Enters an infinite loop to keep prompting the user for input until an exit command is entered. */
   while (1) {
       printf("$ ");
/* reads a line of input from the user. If fgets returns NULL, it indicates an error or the end of input (e.g., EOF), and the loop is terminated. */       if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
           break;
       }
/* Removes the newline character at the end of the input if it exists. */
       size_t input_length = strlen(input);
       if (input_length > 0 && input[input_length - 1] == '\n') {
           input[input_length - 1] = '\0';
       }
/* Checks if the user entered either "exit" or "quit" as the input */
       if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
           break;
       }
/* an array of strings to be passed to the execvp function. */
       char *args[] = {input, NULL};
/* Creates a child process using fork() */
       pid_t pid = fork();
/* Checks if fork() was successful. If not, it prints an error message and exits with an error code */
       if (pid == -1) {
           printf("Failed to fork.\n");
           return 1;
/* replaces its image with a new program using execvp, passing the command and its arguments. */
       } else if (pid == 0) {
           execvp(args[0], args);
/* waits for the child process to complete using wait(NULL). */
       } else {
           wait(NULL);
       }
   }

   return 0;
}
