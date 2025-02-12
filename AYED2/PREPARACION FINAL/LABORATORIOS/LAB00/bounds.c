#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <limits.h>

#define ARRAY_SIZE 4

struct bound_data
{
    bool is_upperbound;
    bool is_lowerbound;
    bool exists;
    unsigned int where;
};

struct bound_data check_bound(int value, int arr[], unsigned int length)
{
    struct bound_data res;
    int max_value = INT_MIN;
    int min_value = INT_MAX;

    for (unsigned int i = 0; i < length; i++)
    {
        if (value == arr[i])
        {
            res.exists = true;
            res.where = i + 1;
        }
        if (max_value <= arr[i])
            max_value = arr[i];

        if (min_value >= arr[i])
            min_value = arr[i];
    }

    res.is_upperbound = max_value <= value;
    res.is_lowerbound = min_value >= value;

    return res;
}

int main(void)
{
    int a[ARRAY_SIZE];
    int value;

    for (int i = 0; i < ARRAY_SIZE; i++)
    {
        printf("Ingrese el numero °%d al arreglo: ", i + 1);
        scanf("%d", &a[i]);
    }

    printf("Que numero desea verificar: ");
    scanf("%d", &value);

    struct bound_data result = check_bound(value, a, ARRAY_SIZE);

    printf("%d\n%d\n%u\n%u\n", result.is_upperbound, result.is_lowerbound, result.exists, result.where);

    return EXIT_SUCCESS;
}
