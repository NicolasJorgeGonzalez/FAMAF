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

    data_t messi = {"Leo Messi", 36, 169};
    data_t *p = &messi;
    print_data(messi);

    printf("name-size  : %lu bytes\n"
           "age-size   : %lu bytes\n"
           "height-size: %lu bytes\n"
           "data_t-size: %lu bytes\n\n",
           sizeof(name_t), sizeof(unsigned int), sizeof(unsigned int), sizeof(data_t));

    printf("name-direction  : %p\n"
           "age-direction   : %p\n"
           "height-direction: %p\n"
           "data_t-direction: %p\n",
           (void *)&messi.name, (void *)&messi.age, (void *)&messi.height, (void *)p);

    return EXIT_SUCCESS;
}
