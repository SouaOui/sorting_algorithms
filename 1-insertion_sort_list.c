#include "sort.h"

/**
 * insertion_sort_list - Entry point
 * @list: The character to print
 * Return: Always 0 (Success)
 */
void insertion_sort_list(listint_t **list)
{
	listint_t *current, *previous, *tmp;
	int n;

	if (!list || !*list || !(*list)->next)
		return;
	previous = *list;
	current = previous->next;
	while (current)
	{
		n = current->n;
		tmp = current->next;
		while (previous && n < previous->n)
		{
			if (n < previous->n)
			{
				if (previous->prev)
					previous->prev->next = current;
				current->prev = previous->prev;
				previous->next = current->next;
				previous->prev = current;
				if (current->next)
					current->next->prev = previous;
				current->next = previous;
				previous = current->prev;
				if (!previous)
					*list = current;
				print_list(*list);
			}
			else
				break;
		}
		current = tmp;
		if (!current)
			break;
		previous = current->prev;
	}
}
