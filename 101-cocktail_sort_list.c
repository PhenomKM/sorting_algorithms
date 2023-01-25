#include <stdlib.h>
#include "sort.h"
#include <stdio.h>
/**
 * swap_two_nodes - swaps two successive nodes in a doubly linked list.
 *
 * @list: our doubly linked list.
 * @current: the current node we are swapping with it's next.
 */
void swap_two_nodes(listint_t **list, listint_t *current)
{
	listint_t *next_node;

	next_node = current->next;
	current->next = next_node->next;
	if (next_node->next != NULL)
		next_node->next->prev = current;
	next_node->prev = current->prev;
	next_node->next = current;
	if (current->prev != NULL)
		current->prev->next = next_node;
	current->prev = next_node;
	current = next_node;
	if (current->prev == NULL)
		*list = current;
}
/**
 * cocktail_sort_list - sort a list using cocktailshake sort.
 *
 * @list: list to sort.
 */

void cocktail_sort_list(listint_t **list)
{
	int test = 0;
	listint_t *current;
	listint_t *last;

	if (!list || !(*list) || !(*list)->next)
		return;

	while (test == 0)
	{
		test = 1;
		last = *list;
		current = *list;
		while (last != NULL && last->next != NULL)
			last = last->next;

		while (current != NULL && current->next != NULL)
		{
			if (current->n > current->next->n)
			{
				swap_two_nodes(list, current);
				test = 0;
				print_list(*list);
			}
			else
				current = current->next;
		}
		while (last != NULL && last->prev != NULL)
		{
			if (last->n < last->prev->n)
			{
				swap_two_nodes(list, last->prev);
				test = 0;
				print_list(*list);
			}
			else
				last = last->prev;
		}
	}
}
