#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * bubble_sort - used for swap
 *
 */
void bubble_sort(int *array, size_t size)
{
    size_t i, j;
    int swapped = 0;

    /*Checks for the size of the array if its less than 2
     * then swap wouldn't occur at all
     */
    if (size < 2)
        exit(1);
    /* For Traversing across the array*/
    for (i = 0; i < size - 1; i++)
    {
        /* For comparing values at each elements*/
        for (j = 0; j < size - i - 1; j++)
        {
            if (array[j] > array[j + 1])
            {
                swap(&array[j], &array[j + 1]);
                swapped = 1;
                print_array(array, size);
            }
        }
        if (swapped == 0)
            break;
    }
}

/**
 * if it gets to the end
 * check if the current element is greater than the last element
 * if it is, then swap size - 1 else break
 *
 */