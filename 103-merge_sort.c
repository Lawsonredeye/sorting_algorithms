#include <stdio.h>
#include <stdlib.h>

void merge(int *array, size_t left_size, size_t right_size);
void merge_sort(int *array, size_t size);

void merge(int *array, size_t left_size, size_t right_size)
{
    size_t total_size = left_size + right_size;
    int *temp = malloc(sizeof(int) * total_size);

    if (temp == NULL)
    {
        perror("Error allocating memory");
        exit(EXIT_FAILURE);
    }

    size_t i = 0, j = left_size, k = 0;

    while (i < left_size && j < total_size)
    {
        if (array[i] <= array[j])
        {
            temp[k++] = array[i++];
        }
        else
        {
            temp[k++] = array[j++];
        }
    }

    while (i < left_size)
    {
        temp[k++] = array[i++];
    }

    while (j < total_size)
    {
        temp[k++] = array[j++];
    }

    for (size_t m = 0; m < total_size; m++)
    {
        array[m] = temp[m];
    }

    free(temp);
}

void merge_sort(int *array, size_t size)
{
    if (size > 1)
    {
        size_t mid = size / 2;
        size_t left_size = mid;
        size_t right_size = size - mid;

        merge_sort(array, left_size);
        merge_sort(array + mid, right_size);

        merge(array, left_size, right_size);
    }
}
