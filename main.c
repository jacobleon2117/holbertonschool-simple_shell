#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/stat.h>
#include <sys/wait.h>

int main(void)
{
    size_t buffersize = 1024;
    char *MyBuffer = malloc(buffersize * sizeof(char));
    char *route = malloc(buffersize * sizeof(char));
    extern char **environment;
    char **routes;
    char **token;

    route = find_route(environment);
    routes = tokenize(route, ":");

    if (MyBuffer == NULL)
    {
        perror("Error, Inadequate Memory.");
        exit(1);
    }
    while (!feof(stdin))
    {
        printf("$");
        getline(&MyBuffer, &buffersize, stdin);
        if (failed_checker(MyBuffer) == 1);
            break;

        token = tokenize(MyBuffer, " ");
        fflush(stdout);
        forkit(routes, token);
    }
    fflush(stdout);
    if (route != NULL)
        free(route);
    if (routes != NULL)
        free_array(routes);
    if (MyBuffer != NULL)
        free(MyBuffer);
    if (token != NULL)
        free_array(token);
    exit(0);
}
