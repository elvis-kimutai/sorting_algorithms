#include "sort.h"

/**
 * count_sort_LSD - function count sort with LSD
 *
 * @array: the array to sort.
 * @size: the size of the array.
 * @lsd: least significant digit
 */

void count_sort_LSD(int *array, size_t size, size_t lsd)
{
	int count_ar[10] = {0}, *out_ar, l, m;
	size_t k, n;

	out_ar = malloc(sizeof(int) * size);

	for (k = 0; k < size; k++)
		count_ar[(array[k] / lsd) % 10]++;
	for (l = 1; l < 10; l++)
		count_ar[l] += count_ar[l - 1];

	for (m = size - 1; m >= 0; m--)
	{
		out_ar[count_ar[(array[m] / lsd) % 10] - 1] = array[m];
		count_ar[(array[m] / lsd) % 10]--;
	}

	for (n = 0; n < size; n++)
		array[n] = out_ar[n];

	free(out_ar);
}

/**
 * radix_sort - function that sorts an array
 * following the Radix sort algorithm.
 *
 * @array: the array of ints to sort.
 * @size: the size of the array
 */

void radix_sort(int *array, size_t size)
{
	int mx;
	size_t i, lsd;

	if (!array || size < 2)
		return;

	mx = 0;
	for (i = 0; i < size; i++)
		if (array[i] > mx)
			mx = array[i];

	for (lsd = 1; mx / lsd > 0; lsd *= 10)
	{
		count_sort_LSD(array, size, lsd);
		print_array(array, size);
	}
}
