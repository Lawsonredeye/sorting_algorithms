#include <stdio.h>
#include "sort.h"

/**
 * shell_sort - using this method of insertion to sort an
 * unorded array
 * @array: unsorted/ almost sorted array
 * @size: size of the array
 * Return: nothing since its a void function
 */
void shell_sort(int *array, size_t size)
{
	size_t i, j, gap = 1;
	int temp, swapped;

	if (size < 2)
		return;
	while (gap < size)
		gap = gap * 3 + 1;
	gap /= 3;
	for (; gap > 0; gap /= 3)
	{
		swapped = 0;
		for (i = gap; i < size; i++)
		{
			temp = array[i];
			for (j = i; (j >= gap) && (array[j - gap] > temp); j -= gap)
			{
				array[j] = array[j - gap];
				swapped = 1;
			}
			array[j] = temp;
		}
		print_array(array, size);
		if (swapped == 0)
			break;
	}
}
