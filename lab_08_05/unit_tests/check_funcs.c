#include <check.h>
#include "../inc/defines.h"
#include "../inc/unit.h"

void *make_matrix(int (*a)[15], int n, int m)
{
    int **pointers = calloc(m, sizeof(int *));

    if (pointers == NULL)
        return NULL;

    for (int i = 0; i < m; i++)
    {
        pointers[i] = calloc(n, sizeof(int));

        if (pointers[i] == NULL)
        {
            free_matrix(m, pointers);
            return NULL;
        }
    }

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            pointers[i][j] = a[i][j];

    return pointers;
}

START_TEST(test_square_normal)
{
    int n = 4;
    int m = 2;
    int a[][15] = {{4, 7, -1, -3}, {3, -5, 7, 3}};

    int **arr = make_matrix(a, n, m);

    int r[][15] = {{4, -1}, {3, 7}};
    int **res = make_matrix(r, 2, 2);

    make_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);

    free_matrix(2, arr);
    free_matrix(2, res);
}
END_TEST

START_TEST(test_square_2x2)
{
    int n = 2;
    int m = 2;
    int a[][15] = {{4, -1}, {3, 7}};

    int **arr = make_matrix(a, n, m);

    int r[][15] = {{4, -1}, {3, 7}};
    int **res = make_matrix(r, 2, 2);

    make_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);

    free_matrix(2, arr);
    free_matrix(2, res);
}
END_TEST

START_TEST(test_square_1x1)
{
    int n = 1;
    int m = 1;
    int a[][15] = {{4}};

    int **arr = make_matrix(a, n, m);

    int r[][15] = {{4}};
    int **res = make_matrix(r, 1, 1);

    make_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 1; i++)
        for (size_t j = 0; j < 1; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);

    free_matrix(2, arr);
    free_matrix(2, res);
}
END_TEST

Suite *square_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("square_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_square_normal);
    tcase_add_test(tc_pos, test_square_1x1);
    tcase_add_test(tc_pos, test_square_2x2);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_bigger_normal)
{
    int n = 2;
    int m = 2;
    int a[][15] = {{1, 2}, {2, 4}};

    int **arr = make_matrix(a, n, m);

    int r[][15] = {{1, 2, 2}, {2, 4, 4}, {1, 2, 2}};
    int **res = make_matrix(r, 3, 3);

    arr = make_matrix_bigger(&m, 3, arr);

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);

    free_matrix(3, arr);
    free_matrix(3, res);
}
END_TEST

Suite *bigger_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("bigger_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_bigger_normal);

    suite_add_tcase(s, tc_pos);

    return s;
}
