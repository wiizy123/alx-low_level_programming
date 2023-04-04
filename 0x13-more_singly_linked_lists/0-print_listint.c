#include "mylibrary.h"


size_t print_node(const node_t *h)
{
    size_t count = 0;

    while (h != NULL)
    {
        printf("%d\n", h->value);
        h = h->next;
        count++;
    }

    return (count);
}

