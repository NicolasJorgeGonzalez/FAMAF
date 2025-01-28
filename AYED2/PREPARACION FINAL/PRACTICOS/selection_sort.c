#include <stdio.h>
#define N 5

void swap(int array[], int pos1, int pos2)
{
    int aux = array[pos1];
    array[pos1] = array[pos2];
    array[pos2] = aux;
}

int min_pos(int array[], unsigned int start, unsigned int end)
{
    int min_pos = start;

    for (unsigned int i = start; i <= end; i++)
    {
        if (array[i] < array[min_pos])
        {
            min_pos = i;
        }
    }
    return min_pos;
}

void selection_sort(int array[], unsigned int length)
{
    int min_element;

    for (unsigned int i = 0; i < length; i++)
    {
        min_element = min_pos(array, i, length - 1);
        swap(array, i, min_element);
    }
}

int main(void)
{
    int array[N] = {4, 1, 6, 3, 7};

    for (unsigned int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }

    selection_sort(array, N);

    printf("\n");

    for (unsigned int i = 0; i < N; i++)
    {
        printf("%d ", array[i]);
    }
}