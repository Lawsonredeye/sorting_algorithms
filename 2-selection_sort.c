#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void selection_sort(int *array, size_t size)
{
    size_t i, j, temp;

    if (size < 2)
        exit(1);
    /* Traverse the Loop*/
    for (i = 0; i < size; i++)
    {
        /*A temp variable to store the smallest
         * value at a particular element
         */
        temp = i;
        for (j = i + 1; j < size; j++)
        {
            if (array[temp] > array[j])
                temp = j;
        }
        /* check if the the new temp value is greater than the
         * the current traverse index
         */
        if (array[temp] < array[i])
        {
            swap(&array[temp], &array[i]);
            print_array(array, size);
        }
    }
}