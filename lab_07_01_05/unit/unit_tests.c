// Сборка примера в MSYS2
//
// gcc -std=c99 -Wall -Werror -c avc.c
// gcc -std=c99 -Wall -Werror -c check_unit_tests.c
// gcc -o app.exe avg.o check_unit_tests.o -lcheck
//
// Сборка примера в Linux
//
// gcc -std=c99 -Wall -Werror -c avc.c
// gcc -std=c99 -Wall -Werror -c check_unit_tests.c
// gcc -o app.exe avg.o check_unit_tests.o -lcheck -lpthread -lrt

#include <check.h>
#include "../inc/headers.h"
#include "../inc/unit.h"

#define EPS 1.0e-7

// Это функция-тест (test function), которая реализует один конкретный тест.
//
// Описание функции-теста всегда начинается с макроса START_TEST, а заканчивается
// макросом END_TEST. У макроса START_TEST есть параметр - это имя теста. Имя теста - это
// имя функции, поэтому оно должно быть корректным идентификатором языка Си. Имя теста
// должно быть информативным и описывать суть теста.
START_TEST(test_key_ordinary)
{
    int arr[] = {7, 6, 5, 4, 3, 2, 1};
    size_t src_elems = 7, dst_elems = 1;
    int res[] = {2};
    int *pb_dst = NULL, *pe_dst = NULL;

    int rc = key(arr, arr + src_elems, &pb_dst, &pe_dst);
    ck_assert_int_eq(rc, EXIT_SUCCESS);

    for (size_t i = 0; i < dst_elems; i++)
        ck_assert_int_eq(pb_dst[i], res[i]);
    free(pb_dst);
}
END_TEST


// Функции-тесты группируются в тестовые случаи (test case, TCase), а несколько
// тестовых случаев образуют тестовый набор (test suite, Suite).
Suite *key_suite(void)
{
    Suite *s;
    TCase *tc_neg;
    TCase *tc_pos;

    // Создадим тестовый набор для тестирования функции calc_avg
    s = suite_create("key_test");

    // Создадим тестовый случай из функций-тестов, которые проверяют разного
    // рода ошибочные ситуации при вызове calc_avg
    tc_neg = tcase_create("negatives");
    // Добавим в tc_neg соответствующие функции-тесты
    // tcase_add_test(tc_neg, test_calc_avg_bad_array_size);
    // tcase_add_test(tc_neg, test_calc_avg_bad_avg_ptr);
    // tcase_add_test(tc_neg, test_calc_avg_empty_array);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_neg);

    // Создадим тестовый случай из функций-тестов, которые проверяют работу
    // calc_avg для корректных параметров
    tc_pos = tcase_create("positives");
    tcase_add_test(tc_pos, test_key_ordinary);
    // Добавим в tc_pos соответствующие функции-тесты
    // tcase_add_test(tc_pos, test_calc_avg_zero_avg);
    // tcase_add_test(tc_pos, test_calc_avg_usual_array);
    // tcase_add_test(tc_pos, test_calc_avg_array_with_one_element);

    // Добавим сформированный тестовый случай в тестовый набор
    suite_add_tcase(s, tc_pos);

    return s;
}
