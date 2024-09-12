#include <stdio.h>     // Librería estándar de entrada y salida
#include <stdlib.h>    // Librería estándar de funciones generales (como exit)
#include <unistd.h>    // Librería para llamadas al sistema como fork y exec
#include <sys/types.h> // Definiciones de tipos de datos usados en llamadas al sistema
#include <sys/wait.h>  // Librería para el manejo de procesos (waitpid)

int main()
{
    pid_t pid; // Declaración de una variable para almacenar el ID del proceso

    pid = fork(); // Crear un proceso hijo. fork() devuelve dos veces: una en el padre y otra en el hijo

    if (pid == -1)
    {
        // Si fork() devuelve -1, ocurrió un error al intentar crear el proceso hijo
        perror("Error al crear el proceso hijo"); // Imprimir un mensaje de error
        exit(EXIT_FAILURE);                       // Salir del programa indicando un error
    }

    if (pid == 0)
    {
        // Este bloque se ejecuta solo en el proceso hijo, ya que pid es 0 en el hijo
        char *args[] = {"ls", "-l", NULL};      // Lista de argumentos para el comando "ls"
        execv("/bin/ls", args);                 // Reemplaza el proceso hijo con el comando "ls" y sus argumentos
        perror("Error al ejecutar el comando"); // Si execv falla, imprime un mensaje de error
        exit(EXIT_FAILURE);                     // Salir del hijo indicando un error si execv falla
    }
    else
    {
        // Este bloque se ejecuta solo en el proceso padre
        int status;               // Variable para almacenar el estado de terminación del hijo
        waitpid(pid, &status, 0); // El padre espera a que el hijo termine su ejecución
        if (WIFEXITED(status))
        {
            // Verifica si el hijo terminó normalmente
            printf("Proceso hijo terminado con código de salida: %d\n", WEXITSTATUS(status));
            // Imprime el código de salida con el que terminó el proceso hijo
        }
    }

    return 0; // Fin del programa
}
