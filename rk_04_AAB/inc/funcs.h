#ifndef FUNCS
#define FUNCS

#include "header.h"

void push(node_t **head, int value);
void print_list(node_t *head, FILE *f);
void reduce(node_t *head);
void free_list(node_t *head);

#endif
