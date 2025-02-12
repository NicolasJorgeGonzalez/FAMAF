#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(int argc, char *arcv[])
{
    printf("hello (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        perror("Error al crear el subproceso.");
        exit(EXIT_FAILURE);
    }
    if (rc == 0)
    {
        printf("child (pid;%n)\n", (int)getpid());
        char *myargs[3];
        myargs[0] = strdup("wc");             // program: "wc"
        myargs[1] = strdup("./fork_libro.c"); // arg: input file
        myargs[2] = NULL;                     // mark end of array
        execvp(myargs[0], myargs);
        printf("This shoud not print out.");
    }
    else
    {
        wait(NULL);
        printf("parent of  %d (pid:%d)\n", rc, (int)getpid());
    }
    return 0;
}