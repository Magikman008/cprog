#include "print_file.h"

#define EXPECTED_SCANF_RESULT 1

void count_numbers(FILE *f, size_t *count)
{
    good_t good;
    short int ok = 0;
    while (ok == 0)
    {
        if (fgets(good.name, 30, f) == NULL)
            ok = 1;
        else
            (*count)++;

        if (fgets(good.manufac, 15, f) == NULL)
            ok = 1;
        else
            (*count)++;

        if (fscanf(f, "%" SCNu32 "\n", &good.amount) != EXPECTED_SCANF_RESULT)
            ok = 1;
        else
            (*count)++;

        if (fscanf(f, "%" SCNu32 "\n", &good.number) != EXPECTED_SCANF_RESULT)
            ok = 1;
        else
            (*count)++;
    }
}

int add_to_array(FILE *f, size_t count, good_t *goods)
{
    for (size_t cur = 0; cur < count; cur++)
    {
        if (fgets(goods[cur].name, 30, f) == NULL)
            return EXIT_FAILURE;
        if (fgets(goods[cur].manufac, 15, f) == NULL)
            return EXIT_FAILURE;
        if (fscanf(f, "%" SCNu32 "\n", &goods[cur].amount) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
        if (fscanf(f, "%" SCNu32 "\n", &goods[cur].number) != EXPECTED_SCANF_RESULT)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}

int print_file(good_t *goods, size_t count, char *substr)
{
    int len;
    int temp_count = 0;
    for (size_t i = 0; i < count; i++)
    {
        len = strlen(goods[i].name) - strlen(substr);
        if (len > 0)
            if (strcmp(goods[i].name + len, substr) == 0)
            {
                temp_count++;
                printf("%s%s%" PRIu32 "\n%" PRIu32 "\n", goods[i].name, goods[i].manufac, goods[i].amount, goods[i].number);
            }
    }

    if (temp_count == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}