#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

int read_array(const char *const file, size_t *const count, int **nums);
int key(const int *pb_src, const int *pe_src, int **pb_dst, int **pe_dst);
void mysort(void *first, size_t number, size_t size, int (*comparator)(const void *, const void *));
int print_file(const char *const file, int *pb_src, const int *pe_src);
int compare_int(const void *val1, const void *val2);
int parse_args(const int argc, char **const argv);
int key_no_malloc(const int *pb_src, const int *pe_src, int **pb_dst, int count);
int find_suitable(const int *pb_src, const int *pe_src);

#endif
