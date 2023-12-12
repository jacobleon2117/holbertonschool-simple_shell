#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
   char input[MAX_INPUT_SIZE];

   while (1) {
       printf("$ ");
       if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
           break;
       }

       size_t input_length = strlen(input);
       if (input_length > 0 && input[input_length - 1] == '\n') {
           input[input_length - 1] = '\0';
       }

       if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
           break;
       }

       char *args[] = {input, NULL};
       pid_t pid = fork();

       if (pid == -1) {
           printf("Failed to fork.\n");
           return 1;
       } else if (pid == 0) {
           execvp(args[0], args);
       } else {
           wait(NULL);
       }
   }

   return 0;
}
