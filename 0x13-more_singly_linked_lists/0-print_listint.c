#include "lists.h"

size_t print_listint(const listint_t *h)
{
	size_t set = 0;

	while (h)
	{
		printf("%d\n", h->n);
		set++;
		h = h->next;
	}

	return (set);
}
