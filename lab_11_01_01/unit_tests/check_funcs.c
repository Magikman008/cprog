#include <check.h>
#include "../inc/headers.h"
#include "../inc/unit.h"

#define MAX_LEN_STR 100

START_TEST(test_c_null)
{
    char format[MAX_LEN_STR] = "%c";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, '\0');
    int len2 = snprintf(res2, MAX_LEN_STR, format, '\0');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_c_standart)
{
    char format[MAX_LEN_STR] = "%c";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 'a');
    int len2 = snprintf(res2, MAX_LEN_STR, format, 'a');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_c_begin)
{
    char format[MAX_LEN_STR] = "%cwefdr";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 'a');
    int len2 = snprintf(res2, MAX_LEN_STR, format, 'a');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_c_end)
{
    char format[MAX_LEN_STR] = "rfevd%c";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 'a');
    int len2 = snprintf(res2, MAX_LEN_STR, format, 'a');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_c_middle)
{
    char format[MAX_LEN_STR] = "rfevd%cewfrv";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 'a');
    int len2 = snprintf(res2, MAX_LEN_STR, format, 'a');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_c_many)
{
    char format[MAX_LEN_STR] = "%crvf%c%crevs";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 'a', 'r', 'f');
    int len2 = snprintf(res2, MAX_LEN_STR, format, 'a', 'r', 'f');
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_c_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("c_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_c_null);
    tcase_add_test(tc_pos, test_c_standart);
    tcase_add_test(tc_pos, test_c_begin);
    tcase_add_test(tc_pos, test_c_end);
    tcase_add_test(tc_pos, test_c_middle);
    tcase_add_test(tc_pos, test_c_many);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_d_standart)
{
    char format[MAX_LEN_STR] = "%d";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_d_begin)
{
    char format[MAX_LEN_STR] = "%dwefdr";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, -123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, -123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_d_end)
{
    char format[MAX_LEN_STR] = "rfevd%d";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_d_middle)
{
    char format[MAX_LEN_STR] = "rfevd%dewfrv";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_d_many)
{
    char format[MAX_LEN_STR] = "%drvf%d%drevs";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123, -124, 0);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123, -124, 0);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_d_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("d_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_d_standart);
    tcase_add_test(tc_pos, test_d_begin);
    tcase_add_test(tc_pos, test_d_end);
    tcase_add_test(tc_pos, test_d_middle);
    tcase_add_test(tc_pos, test_d_many);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_x_standart)
{
    char format[MAX_LEN_STR] = "%x";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_x_begin)
{
    char format[MAX_LEN_STR] = "%xwefdr";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, -123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, -123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_x_end)
{
    char format[MAX_LEN_STR] = "rfevd%x";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_x_middle)
{
    char format[MAX_LEN_STR] = "rfevd%xewfrv";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_x_many)
{
    char format[MAX_LEN_STR] = "%xrvf%x%xrevs";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123, -124, 0);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123, -124, 0);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_x_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("x_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_x_standart);
    tcase_add_test(tc_pos, test_x_begin);
    tcase_add_test(tc_pos, test_x_end);
    tcase_add_test(tc_pos, test_x_middle);
    tcase_add_test(tc_pos, test_x_many);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_o_standart)
{
    char format[MAX_LEN_STR] = "%o";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_o_begin)
{
    char format[MAX_LEN_STR] = "%owefdr";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, -123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, -123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_o_end)
{
    char format[MAX_LEN_STR] = "rfevd%o";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_o_middle)
{
    char format[MAX_LEN_STR] = "rfevd%oewfrv";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_o_many)
{
    char format[MAX_LEN_STR] = "%orvf%o%orevs";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, 123, -124, 0);
    int len2 = snprintf(res2, MAX_LEN_STR, format, 123, -124, 0);
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_o_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("o_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_o_standart);
    tcase_add_test(tc_pos, test_o_begin);
    tcase_add_test(tc_pos, test_o_end);
    tcase_add_test(tc_pos, test_o_middle);
    tcase_add_test(tc_pos, test_o_many);

    suite_add_tcase(s, tc_pos);

    return s;
}

START_TEST(test_s_standart)
{
    char format[MAX_LEN_STR] = "%s";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, "wev");
    int len2 = snprintf(res2, MAX_LEN_STR, format, "wev");
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_s_begin)
{
    char format[MAX_LEN_STR] = "%swefdr";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, "wev");
    int len2 = snprintf(res2, MAX_LEN_STR, format, "wev");
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_s_end)
{
    char format[MAX_LEN_STR] = "rfevd%s";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, "wev");
    int len2 = snprintf(res2, MAX_LEN_STR, format, "wev");
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_s_middle)
{
    char format[MAX_LEN_STR] = "rfevd%sewfrv";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, "wev");
    int len2 = snprintf(res2, MAX_LEN_STR, format, "wev");
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

START_TEST(test_s_many)
{
    char format[MAX_LEN_STR] = "%srvf%s%srevs";
    char res1[MAX_LEN_STR] = "";
    char res2[MAX_LEN_STR] = "";
    int len1 = my_snprintf(res1, MAX_LEN_STR, format, "wev", "124", "");
    int len2 = snprintf(res2, MAX_LEN_STR, format, "wev", "124", "");
    ck_assert_int_eq(len1, len2);
    ck_assert_str_eq(res1, res2);
}
END_TEST

Suite *test_s_suite(void)
{
    Suite *s;
    TCase *tc_pos;

    s = suite_create("s_test");

    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_s_standart);
    tcase_add_test(tc_pos, test_s_begin);
    tcase_add_test(tc_pos, test_s_end);
    tcase_add_test(tc_pos, test_s_middle);
    tcase_add_test(tc_pos, test_s_many);

    suite_add_tcase(s, tc_pos);

    return s;
}
