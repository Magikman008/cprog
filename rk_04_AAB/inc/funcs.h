#ifndef FUNCS
#define FUNCS

#include "header.h"

void push(node_t **const head, const int value);
void print_list(node_t *const head, FILE *const f);
void reduce(node_t *const head);
void free_list(node_t *const head);

#endif
