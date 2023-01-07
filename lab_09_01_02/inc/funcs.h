#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int read_array(const char *const file, item_t **items, size_t *count);
void print_array(const item_t *const items, const size_t count);
item_t *filter_array(item_t *items, size_t *const count, const char *const string);
void sort_array(item_t *items, const int count);
void free_items(item_t *items, const size_t count);

#endif
