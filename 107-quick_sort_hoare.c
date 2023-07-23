#include "sort.h"

/**
 * part - function that gives a piv index for Quicksort
 * @array: array to find the piv.
 * @left: the index of the left element
 * @right: index of the right element
 * @size: size of the array
 *
 * Return: index of the piv element
 */
int part(int *array, int left, int right, size_t size)
{
	int tmp, pivot = array[right];
	size_t i, k;

	i = left - 1;
	k = right + 1;
	while (1)
	{
		do {
			i++;
		} while (array[i] < pivot);
		do {
			k--;
		} while (array[k] > pivot);
		if (i >= k)
			return (i);
		if (i != k)
		{
			tmp = array[i];
			array[i] = array[k];
			array[k] = tmp;
			print_array(array, size);
		}
	}
	return (0);
}

/**
 * quick_sort_hoare - the function that sorts an array
 * with the Quicksort algorithm
 * @array: the array of ints to sort
 * @size: the size of the array
 */

void quick_sort_hoare(int *array, size_t size)
{
	if (size < 2)
		return;

	quick_recursion(array, 0, (int)size - 1, size);
}

/**
 * quick_recursion - The helper function for Quicksort
 * @array: an array to sort
 * @left: index of the left element
 *
 * @right: index of the right element
 * @size: size of the array
 */
void quick_recursion(int *array, int left, int right, size_t size)
{
	int piv;

	if (left < right)
	{
		piv = part(array, left, right, size);
		quick_recursion(array, left, piv - 1, size);
		quick_recursion(array, piv, right, size);
	}
}
