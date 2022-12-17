#include "../inc/funcs.h"

int main()
{
    // m - rows
    // n - columns
    int n_a, m_a, n_b, m_b;
    int **temp;

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

    if (m_a < m_b)
    {
        temp = make_matrix_bigger(&m_a, m_b, matrix_a);

        if (temp == NULL)
        {
            free_matrix(m_a, matrix_a);
            free_matrix(m_b, matrix_b);
            return ERROR_ALLOC_MATRIX;
        }

        matrix_a = temp;
    }
    else
    {
        temp = make_matrix_bigger(&m_b, m_a, matrix_b);

        if (temp == NULL)
        {
            free_matrix(m_a, matrix_a);
            free_matrix(m_b, matrix_b);
            return ERROR_ALLOC_MATRIX;
        }

        matrix_b = temp;
    }

    int **result = pow_operations(m_a, matrix_a, matrix_b);

    if (result == NULL)
    {
        free_matrix(m_a, matrix_a);
        free_matrix(m_b, matrix_b);
        return ERROR_MULT_MATRIX;
    }

    print_matrix(m_a, m_a, result);

    free_matrix(m_a, matrix_a);
    free_matrix(m_b, matrix_b);
    free_matrix(m_a, result);

    return EXIT_SUCCESS;
}
