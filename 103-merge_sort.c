#include "sort.h"

/**
 * merge_sort - function that sorts an array with the Merge Sort algorithm
 * @array: an array of integer to sort
 * @size: the size of the array
 */
void merge_sort(int *array, size_t size)
{
	int *ar;

	if (!array || size < 2)
		return;

	ar = malloc(sizeof(int) * size);

	merge_recursion(ar, array, 0, size);
	free(ar);
}

/**
 * merge_recursion - the recursive function that merge sorts an array
 * @ar: copies an array
 * @array: array to merge sort
 *
 * @left: index of the left element
 * @right: index of the right element
 */
void merge_recursion(int *ar, int *array, size_t left, size_t right)
{
	size_t center;

	if (right - left > 1)
	{
		center = (right - left) / 2 + left;
		merge_recursion(ar, array, left, center);
		merge_recursion(ar, array, center, right);
		merge_subarray(ar, array, left, center, right);
	}
}
/**
 * merge_subarray - the function that merges subarrays
 * @ar: copy array
 * @array: array to merge
 *
 * @left: index of the left element
 * @center: index of the middle element
 * @right: index of the right element
 */

void merge_subarray(int *ar, int *array, size_t left,
		size_t center, size_t right)
{
	size_t i, j, k = 0;

	printf("Merging...\n");
	printf("[left]: ");
	print_array(array + left, center  - left);
	printf("[right]: ");
	print_array(array + center, right - center);

	for (i = left, j = center; i < center && j < right; k++)
	{
		if (array[i] < array[j])
			ar[k] = array[i++];
		else
			ar[k] = array[j++];
	}

	while (i < center)
		ar[k++] = array[i++];
	while (j < right)
		ar[k++] = array[j++];

	for (k = left, i = 0; k < right; k++)
		array[k] = ar[i++];

	printf("[Done]: ");
	print_array(array + left, right - left);
}
