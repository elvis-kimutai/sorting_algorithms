#include "sort.h"

/**
 * bitonic_recursion - The recursive function for bitonic sort
 * @ar: the array to sort
 * @l: index of the left most element
 * @r: index of the right most element
 *
 * @direction: ascending or descending
 * @size: size of the array
 */

void bitonic_recursion(int *ar, int l, int r, int direction, size_t size)
{
	int step;

	if (r - l >= 1)
	{
		step = (r + l) / 2;
		printf("Merging [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(ar + l, r - l + 1);
		bitonic_recursion(ar, l, step, 1, size);
		bitonic_recursion(ar, step + 1, r, 0, size);
		bitonic_merge(ar, l, r, direction);
		printf("Result [%d/%lu] ", r - l + 1, size);
		if (direction)
			printf("(UP):\n");
		else
			printf("(DOWN):\n");
		print_array(ar + l, r - l + 1);
	}
}

/**
 * bitonic_sort - function that sorts an array
 * following the Bitonic sort algorithm
 *
 * @ar: array of ints to sort
 * @size: size of the array
 */

void bitonic_sort(int *array, size_t size)
{
	if (!array || size < 2)
		return;

	bitonic_recursion(array, 0, size - 1, 1, size);
}

/**
 * bitonic_merge - function that sorts and merges a sequence
 * in ascending or descending order
 * @ar: the array to sort
 *
 * @l: the index of the left most element
 * @r: index of the right most element
 * @direction: ascending or descending
 */

void bitonic_merge(int *ar, int l, int r, int direction)
{
	int tmp, i, step = (l + r) / 2, mid = (r - l + 1) / 2;

	if (r - l >= 1)
	{
		for (i = l; i < l + mid; i++)
		{
			if (direction == (ar[i] > ar[i + mid]))
			{
				tmp = ar[i + mid];
				ar[i + mid] = ar[i];
				ar[i] = tmp;
			}
		}
		bitonic_merge(ar, l, step, direction);
		bitonic_merge(ar, step + 1, r, direction);
	}

}
