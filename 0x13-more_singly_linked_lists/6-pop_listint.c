#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

int pop_listint(listint_t **head)
{
	int data_n;
	listint_t *free_node;

	if (head == NULL)
		return (0);
	if (*head == NULL)
		return (0);
	data_n = 0;
	free_node = *head;
	data_n = (*head)->n;
	*head = (*head)->next;
	free(free_node);
	return (data_n);
}
