#include <stdio.h>
#include <unistd.h>
#include <fcntl.h>

void main(void)
{
    char *filename = "lala.txt";

    pid_t pid = fork();

    if (pid == -1)
    {
        ferror("Error al realizar el fork");
    }
    else if (pid == 0)
    {
        // Esto hace el hijo

    }
    else
    {
        // Esto hace el padre
    }
    
    // Desde aquí, cualquier salida estándar se escribirá en el archivo lala.txt
    printf("Esta salida será redirigida al archivo lala.txt\n");

    return 0;
}
