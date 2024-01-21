#include <stdio.h>
#include "sort.h"

/**
 * swap - used for swapping two element values together
 * @xp: pointer to an array
 * @yp: pointer to an array
 * Return: nothing as it just swaps elements from the memory address
 */
void swap(int *xp, int *yp)
{
    int temp;

    temp = *xp;
    *xp = *yp;
    *yp = temp;
}

void quick_sort(int *array, size_t size)
{
    size_t i, j;

    if (size < 2)
        return;
}