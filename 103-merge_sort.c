#include <stdio.h>
#include "sort.h"

void merge_sort_recursion(int array[], int l, int r);
void merge_sorted_array(int array[], int l, int m, int r);

void merge_sort(int *array, size_t size)
{
    merge_sort_recursion(array, 0, size - 1);
}