#include "sort.h"

/**
 * counting_sort -  sorts an array of integers in ascending order
 * using the Counting sort algorithm.
 *
 * @array: array to sort
 * @size: size of the array
 */
void counting_sort(int *array, size_t size)
{
	int *counts_arr, *out_arr, max, num, j, l;
	size_t i, k, m, t;

	if (size < 2)
		return;

	max = array[0];
	for (i = 1; i < size; i++)
		if (array[i] > max)
			max = array[i];

	counts_arr = malloc(sizeof(size_t) * (max + 1));
	out_arr = malloc(sizeof(int) * size);

	for (j = 0; j <= max; j++)
		counts_arr[j] = 0;
	for (k = 0; k < size; k++)
	{
		num = array[k];
		counts_arr[num] += 1;
	}

	for (l = 1; l <= max; l++)
		counts_arr[l] += counts_arr[l - 1];
	print_array(counts_arr, max + 1);
	for (m = 0; m < size; m++)
	{
		out_arr[counts_arr[array[m]] - 1] = array[m];
		counts_arr[array[m]]--;
	}
	for (t = 0; t < size; t++)
		array[t] = out_arr[t];

	free(counts_arr);
	free(out_arr);
}
