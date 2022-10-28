#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int count_elems(FILE *f, size_t *count);
int read_array(FILE *f, int *pb_src, const int *pe_src);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));
void print_file(FILE *f, int *pb_src, const int *pe_src);
int compare_int(const void *val1, const void *val2);

#endif
