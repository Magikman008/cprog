#include <check.h>
#include "../inc/headers.h"
#include "../inc/unit.h"

START_TEST(test_key_reverse)
{
    int arr[] = { 7, 6, 5, 4, 3, 2, 1 };
    size_t src_elems = 7, dst_elems = 1;
    int res[] = { 2 };
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(arr, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    for (size_t i = 0; i < dst_elems; i++)
        ck_assert_int_eq(pb_dst[i], res[i]);

    free(pb_dst);
}
END_TEST

START_TEST(test_key_straight)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    size_t src_elems = 7;
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(arr, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERROR_NO_NUMBERS);

    free(pb_dst);
}
END_TEST

START_TEST(test_key_one_elem)
{
    int arr[] = { 7 };
    size_t src_elems = 1;
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(arr, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERROR_NO_NUMBERS);

    free(pb_dst);
}
END_TEST

START_TEST(test_key_null)
{
    int arr[] = { 7 };
    size_t src_elems = 1;
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(NULL, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, ERROR_KEY_POINTERS);

    free(pb_dst);
}
END_TEST

START_TEST(test_key_two_elems)
{
    int arr[] = { 7, 6 };
    size_t src_elems = 2, dst_elems = 1;
    int res[] = { 7 };
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(arr, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    for (size_t i = 0; i < dst_elems; i++)
        ck_assert_int_eq(pb_dst[i], res[i]);

    free(pb_dst);
}
END_TEST

Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    s = suite_create("key_test");

    tc_neg = tcase_create("negatives");
    tcase_add_test(tc_neg, test_key_straight);
    tcase_add_test(tc_neg, test_key_null);
    tcase_add_test(tc_neg, test_key_one_elem);

    suite_add_tcase(s, tc_neg);

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_reverse);
    tcase_add_test(tc_pos, test_key_two_elems);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_mysort_reverse)
{
    int arr[] = { 7, 6, 5, 4, 3, 2, 1 };
    size_t elems = 7;
    int res[] = { 1, 2, 3, 4, 5, 6, 7 };

    mysort(arr, elems, sizeof(int), compare_int);

    for (size_t i = 0; i < elems; i++)
        ck_assert_int_eq(arr[i], res[i]);
}
END_TEST

START_TEST(test_mysort_straight)
{
    int arr[] = { 1, 2, 3, 4, 5, 6, 7 };
    size_t elems = 7;
    int res[] = { 1, 2, 3, 4, 5, 6, 7 };

    mysort(arr, elems, sizeof(int), compare_int);

    for (size_t i = 0; i < elems; i++)
        ck_assert_int_eq(arr[i], res[i]);
}
END_TEST

START_TEST(test_mysort_one_elem)
{
    int arr[] = { 1 };
    size_t elems = 1;
    int res[] = { 1 };

    mysort(arr, elems, sizeof(int), compare_int);

    for (size_t i = 0; i < elems; i++)
        ck_assert_int_eq(arr[i], res[i]);
}
END_TEST

START_TEST(test_mysort_equals)
{
    int arr[] = { 1, 1, 1 };
    size_t elems = 3;
    int res[] = { 1, 1, 1 };

    mysort(arr, elems, sizeof(int), compare_int);

    for (size_t i = 0; i < elems; i++)
        ck_assert_int_eq(arr[i], res[i]);
}
END_TEST

START_TEST(test_mysort_negatives)
{
    int arr[] = { 1, 0, -1 };
    size_t elems = 3;
    int res[] = { -1, 0, 1 };

    mysort(arr, elems, sizeof(int), compare_int);

    for (size_t i = 0; i < elems; i++)
        ck_assert_int_eq(arr[i], res[i]);
}
END_TEST

Suite *mysort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("mysort_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_mysort_reverse);
    tcase_add_test(tc_pos, test_mysort_straight);
    tcase_add_test(tc_pos, test_mysort_one_elem);
    tcase_add_test(tc_pos, test_mysort_equals);
    tcase_add_test(tc_pos, test_mysort_negatives);

    suite_add_tcase(s, tc_pos);

    return s;
}
