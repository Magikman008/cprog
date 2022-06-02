#include "print_file.h"

#define EXPECTED_SCANF_RESULT 1

void count_numbers(FILE *f, size_t *count)
{
    char cur[30];

    while (fscanf(f, "%s", cur) == EXPECTED_SCANF_RESULT)
        (*count)++;
}

int add_to_array(FILE *f, size_t count, good_t *goods)
{
    for (size_t cur = 0; cur < count; cur++)
    {
        if (fscanf(f, "%s", goods[cur].name) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
        if (fscanf(f, "%s", goods[cur].manufac) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
        if (fscanf(f, "%u", &goods[cur].amount) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
        if (fscanf(f, "%u", &goods[cur].number) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int print_file(good_t *goods, size_t count, char *substr)
{
    size_t len;
    for (size_t i = 0; i < count; i++)
    {
        len = strlen(goods[i].name) - strlen(substr);
        if (strcmp(goods[i].name + len, substr) == 0)
            (void)0;
        printf("%s %s %u %u\n", goods[i].name, goods[i].manufac, goods[i].amount, goods[i].number);
    }
    return EXIT_SUCCESS;
}