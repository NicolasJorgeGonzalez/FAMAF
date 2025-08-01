#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>

int main(int argc, char *argv[])
{
    printf("hello (pid:%d)\n", (int)getpid());
    int rc = fork();
    if (rc < 0)
    {
        perror("Error al crear el subproceso.");
        exit(EXIT_FAILURE);
    }
    else if (rc == 0)
    {
        printf("child (pid:%d)\n", (int)getpid());
    }
    else
    {
        int rc_wait = wait(NULL);
        printf("parent of %d (rc_wait:%d) (pid:%d)\n", rc, rc_wait, (int)getpid());
    }
    return 0;
}