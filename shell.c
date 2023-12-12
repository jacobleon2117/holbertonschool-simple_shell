#include "shell_commands.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_INPUT_SIZE 1024

int main() {
    char input[MAX_INPUT_SIZE];

    while (1) {
        // Display prompt and get user input
        printf("$ ");
        if (fgets(input, MAX_INPUT_SIZE, stdin) == NULL) {
            break;
        }

        // Remove newline character from input
        size_t input_length = strlen(input);
        if (input_length > 0 && input[input_length - 1] == '\n') {
            input[input_length - 1] = '\0';
        }

        // Exit the shell if the user enters 'exit' or 'quit'
        if (strcmp(input, "exit") == 0 || strcmp(input, "quit") == 0) {
            break;
        }

        // Split the input into command and arguments
        char *token = strtok(input, " ");
        char *command = token;
        char *arguments[MAX_INPUT_SIZE];
        int i = 0;

        // Fill the arguments array
        while (token != NULL) {
            arguments[i++] = token;
            token = strtok(NULL, " ");
        }
        arguments[i] = NULL;  // Set the last element to NULL for execvp

        // Execute the command
        execute_command(command, arguments);
    }

    return 0;
}

