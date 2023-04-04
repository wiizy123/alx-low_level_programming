#include "lists.h"

/**
 * add_nodeint_end - function that adds a new node to the end of a list
 *
 * @head: a pointer to a pointer to the first element of the list
 * @n: the data to be added
 *
 * Return: address of the new element, NULL on failure
 */
listint_t *add_nodeint_end(listint_t **head, const int n)
{
	listint_t *new_elem, *current;

	current = *head;

	new_elem = malloc(sizeof(listint_t));

	if (new_elem == NULL)
		return (NULL);

	new_elem->n = n;
	new_elem->next = NULL;

	if (*head == NULL)
	{
		*head = new_elem;
	}
	else
	{
		while (current->next != NULL)
			current = current->next;

		current->next = new_elem;
	}

	return (*head);
}
