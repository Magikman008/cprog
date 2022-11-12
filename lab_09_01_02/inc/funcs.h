#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int count_elems(FILE *f, size_t *count);
void read_array(FILE *f, item_t *items, const int count);
void print_filtered_array(item_t *items, const int count, char *string);
void sort_array(item_t *items, const int count);
void free_items(item_t *items, size_t count);

#endif
