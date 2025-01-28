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
    int i = 0;
    while (new_name[i] != '\0')
    {
        d->name[i] = new_name[i];
        i++;
    }
}

int main(void)
{

    data_t messi = {"Leo Messi", 36, 169};
    name_t messi_full_name = "Lionel Messi";

    print_data(messi);

    data_t *p = &messi;

    set_name(messi_full_name, p);
    print_data(messi);

    return EXIT_SUCCESS;
}
