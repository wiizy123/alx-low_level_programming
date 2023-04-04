#include "lists.h"

/**
pop_listint - deletes head node of a listint and returns the head node's data(n)
@head: pointer to pointer of 1st element in the list
Return: head node data, 0 if list is empty
*/
int pop_listint(listint_t **head)
{
    listint_t *temp;
    int value_of_head;

    if (*head == NULL)
    {
        return (0);
    }

    temp = *head;
    value_of_head = (*head)->n;
    *head = (*head)->next;

    free(temp);
    temp = NULL;

    return (value_of_head);
}
