#include "../inc/funcs.h"

void *alloc_scan_matrix(int *m, int *n)
{
    scanf("%d %d", m, n);

    int **pointers = calloc(*m, sizeof(int *));

    for (int i = 0; i < *m; i++)
        pointers[i] = calloc(*n, sizeof(int));

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            scanf("%d", &pointers[i][j]);

    return pointers;
}

void print_matrix(int m, int n, int **pointers)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", pointers[i][j]);
        puts("");
    }
}

void remove_column(int m, int *n, int index, int **pointers)
{
    for (int i = 0; i < m; i++)
        for (int j = index; j < *n - 1; j++)
            pointers[i][j] = pointers[i][j + 1];

    (*n)--;
}

void remove_row(int *m, int index, int **pointers)
{
    free(pointers[index]);
    for (int i = index; i < *m - 1; i++)
        pointers[i] = pointers[i + 1];

    (*m)--;
}

void made_matrix_square(int *m, int *n, int **pointers)
{
    while (*n != *m)
    {
        int index = 0;
        int min = pointers[0][0];

        for (int i = 0; i < *m; i++)
            for (int j = 0; j < *n; j++)
                if (pointers[i][j] < min)
                {
                    min = pointers[i][j];

                    if (*n > *m)
                        index = j;
                    else
                        index = i;
                }

        // printf("min = %d, index = %d\n", min, index);
        if (*n > *m)
            remove_column(*m, n, index, pointers);
        else
            remove_row(m, index, pointers);
    }
}

void *expand_row(int s_from, int s_to, int *row)
{
    int *temp_row = calloc(s_to, sizeof(int));
    int max = row[0];
    for (int i = 0; i < s_from; i++)
    {
        temp_row[i] = row[i];
        if (row[i] > max)
            max = row[i];
    }

    for (int i = s_from; i < s_to; i++)
        temp_row[i] = max;

    free(row);

    return temp_row;
}

void *make_row(int s_from, int index, int **pointers)
{
    int *temp_row = calloc(s_from, sizeof(int));

    for (int i = 0; i < s_from; i++)
    {
        int mult = 1;
        for (int j = 0; j < index; j++)
            mult *= pointers[j][i];

        temp_row[i] = (int)pow(mult, 1 / (float)index);
    }

    return temp_row;
}

void *make_matrix_bigger(int *s_from, int s_to, int **pointers)
{
    int **temp = calloc(s_to, sizeof(int *));

    for (int i = 0; i < *s_from; i++)
        temp[i] = expand_row(*s_from, s_to, pointers[i]);

    for (int i = *s_from; i < s_to; i++)
        temp[i] = make_row(*s_from, i, temp);

    for (int i = *s_from; i < s_to; i++)
        temp[i] = expand_row(*s_from, s_to, temp[i]);

    *s_from = s_to;

    free(pointers);

    return temp;
}

void free_matrix(int m, int **pointers)
{
    for (int i = 0; i < m; i++)
        free(pointers[i]);

    free(pointers);
}

void *mult_matrixs(int s, int **A, int **B)
{
    int **temp_res = calloc(s, sizeof(int *));

    for (int i = 0; i < s; i++)
        temp_res[i] = calloc(s, sizeof(int));

    for (int i = 0; i < s; i++)
        for (int j = 0; j < s; j++)
            for (int k = 0; k < s; k++)
                temp_res[i][j] += A[i][k] * B[k][j];

    free_matrix(s, A);

    return temp_res;
}