#include "../inc/funcs.h"

void free_matrix(const int m, int **const pointers)
{
    for (int i = 0; i < m; i++)
        free(pointers[i]);

    free(pointers);
}

void *alloc_scan_matrix(int *const m, int *const n)
{
    if (scanf("%d %d", m, n) != 2)
        return NULL;

    if (*m < 1 || *n < 1)
        return NULL;

    int **pointers = calloc(*m, sizeof(int *));

    if (pointers == NULL)
        return NULL;

    for (int i = 0; i < *m; i++)
    {
        pointers[i] = calloc(*n, sizeof(int));

        if (pointers[i] == NULL)
        {
            free_matrix(*m, pointers);
            return NULL;
        }
    }

    for (int i = 0; i < *m; i++)
        for (int j = 0; j < *n; j++)
            if (scanf("%d", &pointers[i][j]) != 1)
            {
                free_matrix(*m, pointers);
                return NULL;
            }

    return pointers;
}

void print_matrix(const int m, const int n, int **const pointers)
{
    for (int i = 0; i < m; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%d ", pointers[i][j]);
        puts("");
    }
}

void remove_column(const int m, int *const n, const int index, int **const pointers)
{
    for (int i = 0; i < m; i++)
        for (int j = index; j < *n - 1; j++)
            pointers[i][j] = pointers[i][j + 1];

    (*n)--;
}

void remove_row(int *const m, const int index, int **const pointers)
{
    free(pointers[index]);
    for (int i = index; i < *m - 1; i++)
        pointers[i] = pointers[i + 1];

    (*m)--;
}

void make_matrix_square(int *const m, int *const n, int **const pointers)
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

        if (*n > *m)
            remove_column(*m, n, index, pointers);
        else
            remove_row(m, index, pointers);
    }
}

void *expand_row(const int s_from, const int s_to, int *const row)
{
    int *temp_row = calloc(s_to, sizeof(int));

    if (temp_row == NULL)
        return NULL;

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

void *make_row(const int s_from, const int index, int **const pointers)
{
    int *temp_row = calloc(s_from, sizeof(int));

    if (temp_row == NULL)
        return NULL;

    for (int i = 0; i < s_from; i++)
    {
        int mult = 1;
        for (int j = 0; j < index; j++)
            mult *= abs(pointers[j][i]);

        temp_row[i] = (int)pow(mult, 1 / (float)index);
    }

    return temp_row;
}

void *make_matrix_bigger(int *const s_from, const int s_to, int **const pointers)
{
    int **temp = calloc(s_to, sizeof(int *));

    for (int i = 0; i < *s_from; i++)
    {
        temp[i] = expand_row(*s_from, s_to, pointers[i]);
        if (temp[i] == NULL)
        {
            free_matrix(s_to, temp);
            return NULL;
        }
    }

    for (int i = *s_from; i < s_to; i++)
    {
        temp[i] = make_row(*s_from, i, temp);
        if (temp[i] == NULL)
        {
            free_matrix(s_to, temp);
            return NULL;
        }
    }

    for (int i = *s_from; i < s_to; i++)
    {
        temp[i] = expand_row(*s_from, s_to, temp[i]);
        if (temp[i] == NULL)
        {
            free_matrix(s_to, temp);
            return NULL;
        }
    }

    *s_from = s_to;

    free(pointers);

    return temp;
}

void *mult_matrixs(const int size, int **const a, int **const b)
{
    int **temp_res = calloc(size, sizeof(int *));

    if (temp_res == NULL)
        return NULL;

    for (int i = 0; i < size; i++)
    {
        temp_res[i] = calloc(size, sizeof(int));
        if (temp_res[i] == NULL)
        {
            free_matrix(size, temp_res);
            return NULL;
        }
    }

    for (int i = 0; i < size; i++)
        for (int j = 0; j < size; j++)
        {
            for (int k = 0; k < size; k++)
                temp_res[i][j] += a[i][k] * b[k][j];
        }

    free_matrix(size, a);

    return temp_res;
}

void *pow_operations(const int size, int **const matrix_a, int **const matrix_b)
{
    int p, q;
    if (scanf("%d %d", &p, &q) != 2)
    {
        free_matrix(size, matrix_a);
        free_matrix(size, matrix_b);
        return NULL;
    }

    if (p < 0 || q < 0)
    {
        free_matrix(size, matrix_a);
        free_matrix(size, matrix_b);
        return NULL;
    }

    int **temp;

    int **result = calloc(size, sizeof(int *));

    if (result == NULL)
        return NULL;

    for (int i = 0; i < size; i++)
    {
        result[i] = calloc(size, sizeof(int));
        if (result[i] == NULL)
        {
            free_matrix(size, result);
            return NULL;
        }
    }

    if (p == 0)
    {
        for (int i = 0; i < size; i++)
            result[i][i] = 1;
    }
    else if (q == 0)
    {
        for (int i = 0; i < size; i++)
        {
            for (int j = 0; j < size; j++)
            {
                result[i][j] = matrix_a[i][j];
                matrix_b[i][j] = 0;
            }
            matrix_b[i][i] = 1;
        }
        p--;
        q++;
    }
    else
    {
        for (int i = 0; i < size; i++)
            for (int j = 0; j < size; j++)
                result[i][j] = matrix_a[i][j];
        p--;
    }

    for (int i = 0; i < p; i++)
    {
        temp = mult_matrixs(size, result, matrix_a);
        if (temp == NULL)
        {
            free(result);
            return NULL;
        }
        result = temp;
    }

    for (int i = 0; i < q; i++)
    {
        temp = mult_matrixs(size, result, matrix_b);
        if (temp == NULL)
        {
            free(result);
            return NULL;
        }
        result = temp;
    }

    return result;
}
