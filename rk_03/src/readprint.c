#include "../inc/readprint.h"

int read_matrix(int **ptrs, const int n, const int m, FILE *f)
{
    for (int i = 0; i < n; i++)
    {
        int *ptr_temp = ptrs[i];

        for (int j = 0; j < m; j++)
            fscanf(f, "%d", &ptr_temp[j]);
    }

    return EXIT_SUCCESS;
}

int print_matrix(int **ptrs, const int n, const int m, FILE *f)
{
    for (int i = 0; i < n; i++)
    {
        int *ptr_temp = ptrs[i];

        for (int j = 0; j < m; j++)
            fprintf(f, "%d ", ptr_temp[j]);
    }

    fprintf(f, "\n");

    return EXIT_SUCCESS;
}
