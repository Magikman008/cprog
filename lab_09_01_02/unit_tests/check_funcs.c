#include <check.h>
#include "../inc/headers.h"
#include "../inc/unit.h"

START_TEST(test_sort_normal)
{
    item_t arr[] = {{"wergh", 1.1, 3}, {"werghjnm", 23.45, 3}, {"wegdfh3retgh", 1, 1}};
    size_t src_elems = 3;
    item_t res[] = {{"wergh", 1.1, 3}, {"wegdfh3retgh", 1, 1}, {"werghjnm", 23.45, 3}};

    sort_array(arr, src_elems);

    for (size_t i = 0; i < src_elems; i++)
    {
        ck_assert_str_eq(arr[i].name, res[i].name);
        ck_assert_double_eq(arr[i].volume, res[i].volume);
        ck_assert_double_eq(arr[i].weight, res[i].weight);
    }
}
END_TEST

START_TEST(test_sort_straight)
{
    item_t arr[] = {{"wergh", 1.1, 3}, {"wegdfh3retgh", 1, 1}, {"werghjnm", 23.45, 3}};
    size_t src_elems = 3;
    item_t res[] = {{"wergh", 1.1, 3}, {"wegdfh3retgh", 1, 1}, {"werghjnm", 23.45, 3}};

    sort_array(arr, src_elems);

    for (size_t i = 0; i < src_elems; i++)
    {
        ck_assert_str_eq(arr[i].name, res[i].name);
        ck_assert_double_eq(arr[i].volume, res[i].volume);
        ck_assert_double_eq(arr[i].weight, res[i].weight);
    }
}
END_TEST

START_TEST(test_sort_reverse)
{
    item_t arr[] = {{"werghjnm", 23.45, 3}, {"wegdfh3retgh", 1, 1}, {"wergh", 1.1, 3}};
    size_t src_elems = 3;
    item_t res[] = {{"wergh", 1.1, 3}, {"wegdfh3retgh", 1, 1}, {"werghjnm", 23.45, 3}};

    sort_array(arr, src_elems);

    for (size_t i = 0; i < src_elems; i++)
    {
        ck_assert_str_eq(arr[i].name, res[i].name);
        ck_assert_double_eq(arr[i].volume, res[i].volume);
        ck_assert_double_eq(arr[i].weight, res[i].weight);
    }
}
END_TEST

START_TEST(test_sort_one)
{
    item_t arr[] = {{"werghjnm", 23.45, 3}};
    size_t src_elems = 1;
    item_t res[] = {{"werghjnm", 23.45, 3}};

    sort_array(arr, src_elems);

    for (size_t i = 0; i < src_elems; i++)
    {
        ck_assert_str_eq(arr[i].name, res[i].name);
        ck_assert_double_eq(arr[i].volume, res[i].volume);
        ck_assert_double_eq(arr[i].weight, res[i].weight);
    }
}
END_TEST

Suite *sort_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("key_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_sort_normal);
    tcase_add_test(tc_pos, test_sort_straight);
    tcase_add_test(tc_pos, test_sort_reverse);
    tcase_add_test(tc_pos, test_sort_one);

    suite_add_tcase(s, tc_pos);

    return s;
}
