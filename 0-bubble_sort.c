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
    int temp = *xp;
    *xp = *yp;
    *yp = temp;
}

/**
 * bubble_sort - used for swap
 *
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;

    /*Checks for the size of the array if its less than 2
     * then swap wouldn't occur at all
     */
    if (size < 2)
        exit(1);
    /* For Traversing across the array*/
    for (i = 0; i < size; i++)
    {
        /* For comparing values at each elements*/
        for (j = i; j < size; j++)
        {
            if (array[j] > array[j + 1])
                swap(&array[j], &array[j + 1]);
            print_array(array, size);
        }
    }
}