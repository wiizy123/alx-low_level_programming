#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"


int delete_nodeint_at_index(listint_t **head, unsigned int index)
{
	listint_t *previous_ptr;
	listint_t *next_ptr;
	unsigned int i;

	if (head == NULL || *head == NULL)
		return (-1);

	next_ptr = *head;
	previous_ptr = NULL;
	if (index == 0)
	{
		*head = (*head)->next;
		free(next_ptr);
		return (1);
	}
	for (i = 0; i < index; i += 1)
	{
		if (next_ptr == NULL)
			return (-1);
		previous_ptr = next_ptr;
		next_ptr = next_ptr->next;
	}
	if (previous_ptr)
		previous_ptr->next = next_ptr->next;
	free(next_ptr);

	return (1);
}
