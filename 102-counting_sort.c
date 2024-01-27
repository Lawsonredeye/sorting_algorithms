#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

/**
 * counting_sort - counting sort algorithm
 * @array: unsorted array
 * @size: size of the unsorted array
 * Return: nothing, void function
 */
void counting_sort(int *array, size_t size)
{
	size_t i;
	int j, max = array[0], *count = 0, *sorted = 0, index;

	for (i = 0; i < size; i++)
	{
		if (array[i] > max)
			max = array[i];
	}
	max += 1;
	index = 0;
	count = malloc((max + 1) * sizeof(int));
	sorted = malloc(size * sizeof(int));
	for (i = 0; i < size; i++)
		count[array[i]]++;
	for (j = 0; j < max; j++)
	{
		for (j = 0; j < count[i]; j++)
		{
			sorted[index] = i;
			index++;
		}
	}
	print_array(sorted, size);
	free(sorted);
	free(count);
}
