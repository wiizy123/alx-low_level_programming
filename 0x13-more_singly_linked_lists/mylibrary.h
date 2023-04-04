#ifndef MYLIBRARY_H
#define MYLIBRARY_H

#include <stdio.h>
#include <stdlib.h>


typedef struct node_s
{
    int value;
    struct node_s *next;
} node_t;

size_t print_node(const node_t *h);
size_t node_len(const node_t *h);
node_t *add_node(node_t **head, const int value);
node_t *add_node_end(node_t **head, const int value);
void free_node(node_t *head);
void free_node2(node_t **head);
int pop_node(node_t **head);
node_t *get_node_at_index(node_t *head, unsigned int index);
int sum_node(node_t *head);
node_t *insert_node_at_index(node_t **head, unsigned int idx, int value);
int delete_node_at_index(node_t **head, unsigned int index);
node_t *reverse_node(node_t **head);
size_t print_node_safe(const node_t *head);
size_t free_node_safe(node_t **h);
node_t *find_node_loop(node_t *head);

#endif /* MYLIBRARY_H */

