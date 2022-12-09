#include <check.h>
#include "../inc/headers.h"
#include "../inc/unit.h"

START_TEST(test_squre_normal)
{
    int arr0[4] = {4, 7, -1, -3};
    int arr1[4] = {3, -5, 7, 3};
    int *arr[2];
    arr[0] = arr0;
    arr[1] = arr1;

    int res0[2] = {4, -1};
    int res1[2] = {3, 7};
    int *res[2];
    res[0] = res0;
    res[1] = res1;

    int m = 2;
    int n = 4;

    made_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);
}
END_TEST

START_TEST(test_squre_2x2)
{
    int arr0[2] = {4, -1};
    int arr1[2] = {3, 7};
    int *arr[2];
    arr[0] = arr0;
    arr[1] = arr1;

    int res0[2] = {4, -1};
    int res1[2] = {3, 7};
    int *res[2];
    res[0] = res0;
    res[1] = res1;

    int m = 2;
    int n = 2;

    made_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 2; i++)
        for (size_t j = 0; j < 2; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);
}
END_TEST

START_TEST(test_squre_1x1)
{
    int arr0[1] = {4};
    int *arr[1];
    arr[0] = arr0;

    int res0[1] = {4};
    int *res[1];
    res[0] = res0;

    int m = 1;
    int n = 1;

    made_matrix_square(&m, &n, arr);

    for (size_t i = 0; i < 1; i++)
        for (size_t j = 0; j < 1; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);
}
END_TEST

Suite *squre_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("squre_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_squre_normal);
    tcase_add_test(tc_pos, test_squre_1x1);
    tcase_add_test(tc_pos, test_squre_2x2);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_bigger_normal)
{
    int **arr = calloc(2, sizeof(int *));

    for (int i = 0; i < 2; i++)
    {
        arr[i] = calloc(2, sizeof(int));
    }

    for (int i = 1; i < 3; i++)
        for (int j = 1; j < 3; j++)
            arr[i - 1][j - 1] = i * j;

    int res0[3] = {1, 2, 2};
    int res1[3] = {2, 4, 4};
    int res2[3] = {1, 2, 2};
    int *res[3];
    res[0] = res0;
    res[1] = res1;
    res[2] = res2;

    int m = 2;

    arr = make_matrix_bigger(&m, 3, arr);

    for (size_t i = 0; i < 3; i++)
        for (size_t j = 0; j < 3; j++)
            ck_assert_double_eq(arr[i][j], res[i][j]);
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
