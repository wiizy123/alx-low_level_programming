#include "lists.h"
#include <stdio.h>

size_t print_listint(const listint_t *h)
{
	size_t set = 0;

	while (h != NULL)
	{
		printf("%d\n", h->n);
		set++;
		h = h->next;
	}

	return (set);
}
