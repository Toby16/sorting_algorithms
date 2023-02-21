#include "sort.h"
#include <stdlib.h>

void insertion_sort_list(listint_t **list);

/**
 * insertion_sort_list - function to perform 'insertion sort'
 *	on a list
 * @list: argument of type 'listint_t **'
 *	doubly linked list
 */

void insertion_sort_list(listint_t **list)
{
	if (list == NULL || *list == NULL || (*list)->next == NULL)
		return (NULL);

	listint_t *i, *j, *temp;
	int key;

	temp = malloc(sizeof(listint_t));

	/* check if malloc encounters error */
	if (temp != NULL)
	{
		temp = *list;
		temp = temp->next;

		for (i = temp; i != NULL; i = i->next)
		{
			key = i->n;
			j = i->prev;

			while ((j != NULL) && (j->n > key))
			{
				/* swap nodes */
				i->prev = j->prev;
				j->prev = i;
				j->next = i->next;

				if (i->next != NULL)
				{
					i->next->prev = j;
				}

				i->next = j;

				if (i->prev == NULL)
				{
					*list = i;
				}
				else
				{
					i->prev->next = i;
				}

				j = i->prev;
				print_list(*list);
			}
		}
	}
}


