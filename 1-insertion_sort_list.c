#include "sort.h"
#include <stdlib.h>
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
 * insertion_sort_list - sorts a linked list in ascending order
 *
 * @list: our doubly linked list
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current;
	listint_t *new;

	if (!list || !(*list) || !(*list)->next)
		return;

	current = *list;
	while (current != NULL && current->next != NULL)
	{
		if (current->n > current->next->n)
		{
			swap_two_nodes(list, current);
			print_list(*list);
			current = current->prev;
			while (current->prev && current && current->n < current->prev->n)
			{
				new = current;
				swap_two_nodes(list, new->prev);
				print_list(*list);
			}
		}
		if (current->next != NULL)
			current = current->next;
		else
			break;
	}
}
