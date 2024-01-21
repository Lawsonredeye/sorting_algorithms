#include <stdio.h>
#include <stdlib.h>
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
 * bubble_sort - used for swap
 * @array: Array of unsorted values
 * @size: size of unsorted array
 * Return: Nothing
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