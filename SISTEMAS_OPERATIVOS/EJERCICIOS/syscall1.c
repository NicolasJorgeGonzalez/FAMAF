#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

int main()
{
    char *filename = "lala.txt";

    int fd = open(filename, O_CREAT | O_WRONLY);

    dup2(fd, STDOUT_FILENO);

    printf("Esta salida sera redirigida al archivo lala.txt\n");

    close(fd);

    return 0;
}