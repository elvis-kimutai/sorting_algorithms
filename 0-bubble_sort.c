#include "sort.h"
/**
 * bubble_sort - Sorts an array of integers in ascending order using Bubble sort.
 * @array: The array to be sorted.
 * @size: The size of the array.
 *
 * Return: Void
 */

void bubble_sort(int *array, size_t size)
{
	size_t i, index, new;
	int swap;

	if (array == NULL || size < 2)
		return;

	index = size;
	while (index > 0)
	{
		new = 0;
		for (i = 0; i < index - 1; i++)
		{
			if (array[i] > array[i + 1])
			{
				swap = array[i];
				array[i] = array[i + 1];
				array[i + 1] = swap;
				new = i + 1;
				print_array(array, size);
			}
		}
		index = new;
	}
}
