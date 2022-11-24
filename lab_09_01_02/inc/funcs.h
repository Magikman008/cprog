#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int count_elems(FILE *f, size_t *count);
int read_array(char *file, item_t **items, size_t *count);
void print_array(item_t *items, const size_t count);
void filter_array(item_t *items, size_t *count, char *string);
void sort_array(item_t *items, const int count);
void free_items(item_t *items, size_t count);

#endif
