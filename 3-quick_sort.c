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
 * partition - used for getting the pivot for the array
 * @array: array to be traversed
 * @size: size of the array
 * Return: the index of the pivot
 */
int partition(int *array, size_t size)
{
	int low, high, i, j, pivot;

	/**
	 * high: get the last element of the array using size - 1
	 * low: get the least element of the array i.e low = 0
	 * i : this would be low - 1 to say no swap has been made
	 */
	high = size - 1;
	low = 0;
	pivot = array[high];
	i = low - 1;

	/**
	 * using a loop, traverse across the size of the array
	 * and check if the jth element is <= the pivot
	 */
	if (low >= high || low < 0)
		return (1);
	for (j = low; j < high; j++)
	{
		if (array[j] <= pivot)
		{
			i = i + 1;
			swap(&array[i], &array[j]);
		}
	}
	i = i + 1;
	swap(&array[i], &array[high]);
	return (i);
}

/**
 * quick_sort - used for sorting an unsorted list
 * @array: array to be traversed
 * @size: size of the array
 * Return: the index of the pivot
 */
void quick_sort(int *array, size_t size)
{
	int p;

	if (size < 2)
		return;
	p = partition(array, size);
	quick_sort(array, p);
	quick_sort(array + p + 1, size - p - 1);
	print_array(array, size);
}
