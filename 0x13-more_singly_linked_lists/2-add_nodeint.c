#include "lists.h"

listint_t *add_nodeint(listint_t **head, const int n)
{
	listint_t *new = malloc(sizeof(listint_t));

	if (new == NULL)
		return (NULL);

	/* create new node*/
	new->n = n;
	new->next = *head;

	/* make head point to the new node*/
	*head = new;

	return (new);
}
