#include "sort.h"
#include <stdio.h>

/**
 * list_len - The function returns length of list.
 * @list: The head of list
 *
 * Return: length
 */
size_t list_len(listint_t *list)
{
	size_t le = 0;

	while (list)
	{
		le++;
		list = list->next;
	}
	return (le);
}

/**
 * switch_nodes - swaps nodes at pointer p with the following node.
 *
 * @list: head of list
 * @p: pointer to node
 */
void switch_nodes(listint_t **list, listint_t **p)
{
	listint_t *one, *two, *three, *four;

	one = (*p)->prev;
	two = *p;
	three = (*p)->next;
	four = (*p)->next->next;
	two->next = four;
	if (four)
		four->prev = two;
	three->next = two;
	three->prev = two->prev;
	if (one)
		one->next = three;
	else
		*list = three;
	two->prev = three;
	*p = three;
}

/**
 * cocktail_sort_list - sorts a doubly linked list using
 * the cocktail sort algorithm
 *
 * @list: pointer to list
 */
void cocktail_sort_list(listint_t **list)
{
	listint_t *p;
	int sorts = 0;

	if (!list || !*list || list_len(*list) < 2)
		return;
	p = *list;
	while (!sorts)
	{
		sorts = 1;
		while (p->next)
		{
			if (p->n > p->next->n)
			{
				sorts = 0;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->next;
		}
		if (sorts)
			break;
		p = p->prev;
		while (p->prev)
		{
			if (p->n < p->prev->n)
			{
				sorts = 0;
				p = p->prev;
				switch_nodes(list, &p);
				print_list(*list);
			}
			else
				p = p->prev;
		}
	}
}
