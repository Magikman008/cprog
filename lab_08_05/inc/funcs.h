#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

void free_matrix(const int m, int **const pointers);
void *alloc_scan_matrix(int *const m, int *const n);
void print_matrix(const int m, const int n, int **const pointers);
void made_matrix_square(int *const m, int *const n, int **const pointers);
void *make_matrix_bigger(int *const s_from, const int s_to, int **const pointers);
void *pow_operations(const int size, int **const matrix_a, int **const matrix_b);

#endif
