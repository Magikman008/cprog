#ifndef FUNCS_H
#define FUNCS_H

#include "headers.h"

void *alloc_scan_matrix(int *m, int *n);
void print_matrix(int m, int n, int **pointers);
void made_matrix_square(int *m, int *n, int **pointers);
void *make_matrix_bigger(int *s_from, int s_to, int **pointers);
void free_matrix(int m, int **pointers);
void *mult_matrixs(int s, int **a, int **b);

#endif
