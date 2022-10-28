#include "process_file.h"
#include <stdlib.h>
#include <math.h>

int scan(FILE *f, size_t *count, good_t *goods)
{
    if (fscanf(f, "%lu\n", count) != EXPECTED_SCANF_RESULT)
        return ERROR_BAD_FILE;

    if (*count < 1 || *count > MAX_ARRAY_LEN)
        return ERROR_BAD_FILE;

    size_t cur = 0;

    while (cur < *count)
    {
        if (fgets(goods[cur].name, MAX_SIZE_NAME, f) == NULL || strlen(goods[cur].name) == 1)
            return ERROR_NAME_SCAN;

        if (fscanf(f, "%d\n", &goods[cur].price) != EXPECTED_SCANF_RESULT || goods[cur].price < 1)
            return ERROR_BAD_FILE;

        cur++;
    }

    if (cur < *count)
        return ERROR_BAD_FILE;

    return EXIT_SUCCESS;
}

int print_answer(size_t count, good_t *goods, char *border)
{
    size_t res_count = 0;

    double price;
    char *endptr;
    price = strtod(border, &endptr);

    if (border == endptr)
        return ERROR_SCAN_PRICE;

    for (size_t i = 0; i < count; i++)
        if (goods[i].price < price)
        {
            res_count++;
            printf("%s%d\n", goods[i].name, goods[i].price);
        }

    return EXIT_SUCCESS;
}

// какие бывают файлы
// найти минусы структур
// Union
// double free
// муньтрицы
// есть файлик с матрицей nxn с цифрами пересечение (число) между строкой и столбцом с макс суммой чисел в файлик вывод 
