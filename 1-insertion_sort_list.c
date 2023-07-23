#include "sort.h"

/**
 * swap - Entry point
 * @list: The character to print
 * @previous: The character to print
 * @current: The character to print
 * Return: Always 0 (Success)
 */
void swap(listint_t **list, listint_t **previous, listint_t **current)
{
	if ((*previous)->prev)
		(*previous)->prev->next = *current;
	(*current)->prev = (*previous)->prev;
	(*previous)->next = (*current)->next;
	(*previous)->prev = *current;
	if ((*current)->next)
		(*current)->next->prev = *previous;
	(*current)->next = *previous;
	*previous = (*current)->prev;
	if (!*previous)
		*list = (*current);
	print_list(*list);
}

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
		if (n < previous->n)
		{
			if (!current->next && !previous->prev)
			{
				previous->next = NULL;
				previous->prev = current;
				current->next = previous;
				current->prev = NULL;
				*list = current;
				print_list(*list);
				return;
			}
			else
			{
				while (previous)
				{
					if (n < previous->n)
						swap(list, &previous, &current);
					else
						break;
				}
			}
		}
		current = tmp;
		if (!current)
			break;
		previous = current->prev;
	}
}
