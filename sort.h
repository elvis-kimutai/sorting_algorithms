#ifndef SORT_H
#define SORT_H

#include <stdlib.h>
#include <stdio.h>

/**
 * struct listint_s - Doubly linked list node
 *
 * @n: Integer stored in the node
 * @prev: Pointer to the previous element of the list
 * @next: Pointer to the next element of the list
 */
typedef struct listint_s
{
    const int n;
    struct listint_s *prev;
    struct listint_s *next;
} listint_t;


void bubble_sort(int *array, size_t size);
void print_array(const int *array, size_t size);
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2);
void insertion_sort_list(listint_t **list);
void print_list(const listint_t *list);
void swap(int *a, int *b);
void selection_sort(int *array, size_t size);
int lomuto_partition(int *array, int low, int high, size_t size);
void quick_sort_recursive(int *array, int low, int high, size_t size);
void quick_sort(int *array, size_t size);
void shell_sort(int *array, size_t size);
void cocktail_sort_list(listint_t **list);
void counting_sort(int *array, size_t size);
void merge_sort(int *array, size_t size);
void merge_recursion(int *ar, int *array, size_t left, size_t right);
void merge_subarray(int *ar, int *array, size_t left, size_t center, size_t right);
void heap_sort(int *array, size_t size);
void radix_sort(int *array, size_t size);
void bitonic_sort(int *array, size_t size);
void bitonic_recursion(int *ar, int l, int r, int direction, size_t size);
void bitonic_merge(int *ar, int l, int r, int direction);
void quick_sort_hoare(int *array, size_t size);
void quick_recursion(int *array, int left, int right, size_t size);
int part(int *array, int left, int right, size_t size);
#endif
