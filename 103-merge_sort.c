#include <stdio.h>
#include <stdlib.h>
#include "sort.h"

void merge(int *array, size_t left_size, size_t right_size);
void merge_sort(int *array, size_t size);

/**
 * merge - creates array for dividing and conquering
 * @array: array to be divided
 * @left_size: left half of the divided array
 * @right_size: right half of the divided array
 */
void merge(int *array, size_t left_size, size_t right_size)
{
	size_t i, j, k;
	int *left;

	left = malloc(sizeof(int) * left_size);

	if (left == NULL)
	{
		perror("Error allocating memory");
		exit(EXIT_FAILURE);
	}

	for (i = 0; i < left_size; i++)
		left[i] = array[i];

	i = 0;
	j = 0;
	k = 0;

	while (i < left_size && j < right_size)
	{
		if (left[i] <= array[left_size + j])
		{
			array[k] = left[i];
			i++;
		}
		else
		{
			array[k] = array[left_size + j];
			j++;
		}
		k++;
	}

	while (i < left_size)
	{
		array[k] = left[i];
		i++;
		k++;
	}

	while (j < right_size)
	{
		array[k] = array[left_size + j];
		j++;
		k++;
	}
	printf("Merging...\n");
	printf("[left]: ");
	print_array(left, left_size);
	printf("[right]: ");
	print_array(array + left_size, right_size);
	printf("[Done]: ");
	print_array(array, left_size + right_size);

	free(left);
}

/**
 * merge_sort - uses recursion to sort by divide and conquer
 * @array: array to be sorted
 * @size: size of the array
 */
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
