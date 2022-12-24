#include "../inc/funcs.h"

int main()
{
    int n_a, m_a, n_b, m_b;

    int **matrix_a = alloc_scan_matrix(&m_a, &n_a);
    if (matrix_a == NULL)
        return ERROR_ALLOC_MATRIX;

    int **matrix_b = alloc_scan_matrix(&m_b, &n_b);

    if (matrix_b == NULL)
    {
        free_matrix(m_a, matrix_a);
        return ERROR_ALLOC_MATRIX;
    }

    make_matrix_square(&m_a, &n_a, matrix_a);
    make_matrix_square(&m_b, &n_b, matrix_b);

    int rc = deside_matrix_expand(&m_a, &m_b, &matrix_a, &matrix_b);
    if (rc)
        return rc;

    int p, q;
    if (scanf("%d %d", &p, &q) != 2)
    {
        FREE_MATRICES;
        return ERROR_SCANF;
    }

    if (p < 0 || q < 0)
    {
        FREE_MATRICES;
        return ERROR_WRONG_POWERS;
    }

    int **result = pow_operations(m_a, matrix_a, matrix_b, &p, &q);

    if (result == NULL)
    {
        FREE_MATRICES;
        return ERROR_MULT_MATRIX;
    }

    print_matrix(m_a, m_a, result);

    FREE_MATRICES;
    free_matrix(m_a, result);

    return EXIT_SUCCESS;
}
