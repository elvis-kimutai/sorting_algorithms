#include "sort.h"

/**
* shell_sort - sorts an array of integers using the shell
* sort algorithm with Knuth sequence
* @array: the array of integers to be sorted
* @size: size of the array
*
* Return: void
*/
void shell_sort(int *array, size_t size)
{
	size_t gap = 0, a, i;
	int index;

	if (size < 2)
		return;

	while ((gap = gap * 3 + 1) < size);

	gap = (gap - 1) / 3;

	for (; gap > 0; gap = (gap - 1) / 3)
	{
		for (i = gap; i < size; i++)
		{
			index = array[i];
			for (a = i; a >= gap && index <= array[a - gap]; a -= gap)
				array[a] = array[a - gap];
			array[a] = index;
		}
		print_array(array, size);
	}
}
