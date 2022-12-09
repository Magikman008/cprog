#include "../inc/funcs.h"

int main()
{
    // m - rows
    // n - columns
    int n_a, m_a, n_b, m_b;

    int **matrix_a = alloc_scan_matrix(&m_a, &n_a);

    if (matrix_a == NULL)
        return ERROR_ALLOC_MATRIX;

    int **matrix_b = alloc_scan_matrix(&m_b, &n_b);

    if (matrix_b == NULL)
        return ERROR_ALLOC_MATRIX;

    // print_matrix(m_a, n_a, matrix_a);
    // puts("");

    // print_matrix(m_b, n_b, matrix_b);
    // puts("");

    made_matrix_square(&m_a, &n_a, matrix_a);
    made_matrix_square(&m_b, &n_b, matrix_b);

    // print_matrix(m_a, n_a, matrix_a);
    // puts("");

    // print_matrix(m_b, n_b, matrix_b);
    // puts("");

    if (m_a < m_b)
    {
        matrix_a = make_matrix_bigger(&m_a, m_b, matrix_a);
        n_a = m_a;
    }
    else
    {
        matrix_b = make_matrix_bigger(&m_b, m_a, matrix_b);
        n_b = m_b;
    }

    // print_matrix(m_a, n_a, matrix_a);
    // puts("");

    // print_matrix(m_b, n_b, matrix_b);
    // puts("");

    int p, q;
    scanf("%d %d", &p, &q);

    if (p < 0 || q < 0)
    {
        free_matrix(m_a, matrix_a);
        free_matrix(m_b, matrix_b);
        return ERROR_WRONG_SIZES;
    }

    int **result = calloc(m_a, sizeof(int *));

    for (int i = 0; i < m_a; i++)
        result[i] = calloc(m_a, sizeof(int));

    if (p == 0)
    {
        for (int i = 0; i < m_a; i++)
            result[i][i] = 1;
    }
    else if (q == 0)
    {
        for (int i = 0; i < m_a; i++)
        {
            for (int j = 0; j < m_a; j++)
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
        for (int i = 0; i < m_a; i++)
            for (int j = 0; j < m_a; j++)
                result[i][j] = matrix_a[i][j];
        p--;
    }

    // print_matrix(m_a, n_a, matrix_a);
    // puts("");

    // print_matrix(m_b, n_b, matrix_b);
    // puts("");

    // print_matrix(m_a, m_a, result);
    // puts("");

    for (int i = 0; i < p; i++)
    {
        // printf("%d\n", i);
        result = mult_matrixs(m_a, result, matrix_a);
        // print_matrix(m_a, m_a, result);
    }

    for (int i = 0; i < q; i++)
    {
        // printf("%d\n", i);
        result = mult_matrixs(m_a, result, matrix_b);
        // print_matrix(m_a, m_a, result);
    }

    print_matrix(m_a, m_a, result);

    free_matrix(m_a, matrix_a);
    free_matrix(m_b, matrix_b);
    free_matrix(m_a, result);

    return EXIT_SUCCESS;
}
