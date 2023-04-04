#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "lists.h"

int sum_listint(listint_t *head)
{
	int sum;
	listint_t *next_ptr;

	if (!head)
		return (0);
	next_ptr = head;
	sum = 0;
	while (next_ptr != NULL)
	{
		sum += next_ptr->n;
		next_ptr = next_ptr->next;
	}
	return (sum);
}
