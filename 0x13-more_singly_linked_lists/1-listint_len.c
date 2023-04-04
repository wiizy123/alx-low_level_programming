#include "lists.h"


size_t listint_len(const listint_t *h)
{
	size_t set = 0;

	while (h)
	{
		set++;
		h = h->next;
	}

	return (set);
}
