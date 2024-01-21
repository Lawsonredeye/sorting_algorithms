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

/**
 * selection_sort - used for swap
 * @array: Array of unsorted values
 * @size: size of unsorted array
 * Return: Nothing
 */
void selection_sort(int *array, size_t size)
{
    size_t i, j, temp;

    if (size < 2)
        return;
    /* Traverse the Loop*/
    for (i = 0; i < size; i++)
    {
        /**
         * A temp variable to store the smallest
         * value at a particular element
         */
        temp = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[temp] > array[j])
                temp = j;
        }
        /**
         *  check if the the new temp value is greater than the
         * the current traverse index
         */
        if (temp != i)
        {
            swap(&array[temp], &array[i]);
            print_array(array, size);
        }
    }
}
