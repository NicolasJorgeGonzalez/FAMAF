#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

#include "data.h"

void print_data(data_t d)
{
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

int main(void)
{

    data_t messi = {"Leonel Messi", 36, 169};
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n",
           sizeof(messi.name), sizeof(messi.age), sizeof(messi.height), (sizeof(messi.name) + sizeof(messi.age) + sizeof(messi.height)));

    printf("\nname-location  : %lu \n"
           "age-location   : %lu \n"
           "height-location: %lu \n",
           (uintptr_t)&messi.name, (uintptr_t)&messi.age, (uintptr_t)&messi.height);

    return EXIT_SUCCESS;
}
