#include "sort.h"

/* Function to swap two nodes in a doubly linked list */
void swap_nodes(listint_t **list, listint_t *node1, listint_t *node2)
{
    if (node1->prev != NULL)
        node1->prev->next = node2;
    if (node2->next != NULL)
        node2->next->prev = node1;

    node1->next = node2->next;
    node2->prev = node1->prev;

    node1->prev = node2;
    node2->next = node1;

    if (node1 == *list)
        *list = node2;
}

/* Function to perform Insertion sort on a doubly linked list */
void insertion_sort_list(listint_t **list)
{
    listint_t *current, *temp;

    if (list == NULL || *list == NULL)
        return;

    current = (*list)->next;

    while (current != NULL)
    {
        temp = current->next;

        while (current->prev != NULL && current->n < current->prev->n)
        {
            swap_nodes(list, current->prev, current);
            print_list(*list);
        }

        current = temp;
    }
}

