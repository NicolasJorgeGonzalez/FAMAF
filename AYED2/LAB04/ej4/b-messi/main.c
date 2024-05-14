#include <stdio.h>
#include <stdlib.h>

#include "data.h"

void print_data(data_t d)
{
    printf("NOMBRE: %s\n"
           "EDAD  : %d años\n"
           "ALTURA: %d cm\n\n",
           d.name, d.age, d.height);
}

void set_name(name_t new_name, data_t *d)
{
    // Copia los caracteres uno por uno desde new_name hasta que encuentre el carácter nulo '\0'
    int i;
    for (i = 0; new_name[i] != '\0'; i++)
    {
        d->name[i] = new_name[i];
    }
    // Asegúrate de agregar el carácter nulo al final de la cadena
    d->name[i] = '\0';
}

int main(void)
{

    data_t messi = {"Leo Messi", 36, 169};
    print_data(messi);
    name_t messi_full_name = "Lionel Messi";

    data_t *p = NULL;
    p = &messi;

    set_name(messi_full_name, p);

    print_data(messi);

    return EXIT_SUCCESS;
}
