#include "sort.h"

/* Function to swap two integers */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* Lomuto partition scheme for Quick sort */
int lomuto_partition(int *array, int low, int high, size_t size)
{
    int pivot = array[high];
    int i = low - 1;
    int j;

    for (j = low; j <= high - 1; j++)
    {
        if (array[j] < pivot)
        {
            i++;
            if (i != j)
            {
                swap(&array[i], &array[j]);
                print_array(array, size);
            }
        }
    }
    if (array[i + 1] != array[high])
    {
        swap(&array[i + 1], &array[high]);
        print_array(array, size);
    }
    return (i + 1);
}

/* Quick sort recursive function */
void quick_sort_recursive(int *array, int low, int high, size_t size)
{
    int partition_index;

    if (low < high)
    {
        partition_index = lomuto_partition(array, low, high, size);
        quick_sort_recursive(array, low, partition_index - 1, size);
        quick_sort_recursive(array, partition_index + 1, high, size);
    }
}

/* Function to perform Quick sort on an array */
void quick_sort(int *array, size_t size)
{
    if (array == NULL || size <= 1)
        return;

    quick_sort_recursive(array, 0, size - 1, size);
}

