#include "print_file.h"

#define EXPECTED_SCANF_RESULT 1

int fscan_str(char str[], size_t n, FILE *f)
{
    char buf[32];

    if (!fgets(buf, n + 1, f))
        return ERROR_EMPTY_STRING;

    size_t len = strlen(buf);

    if (buf[len - 1] == '\n')
        buf[--len] = '\0';

    if (len == 0)
        return ERROR_EMPTY_STRING;

    if (len >= n)
        return ERROR_TOO_LONG_STRING;

    strcpy(str, buf);

    return EXIT_SUCCESS;
}

void count_numbers(FILE *f, size_t *count)
{
    good_t good;
    short int ok = 0;

    while (ok == 0)
    {
        if (fscan_str(good.name, 31, f) != EXIT_SUCCESS)
            ok = 1;
        else if (ok == 0)
            (*count)++;

        if (fscan_str(good.manufac, 16, f) != EXIT_SUCCESS && ok == 0)
            ok = 1;
        else if (ok == 0)
            (*count)++;

        if (fscanf(f, "%" SCNu32 "\n", &good.amount) != EXPECTED_SCANF_RESULT && ok == 0)
            ok = 1;
        else if (ok == 0)
            (*count)++;

        if (fscanf(f, "%" SCNu32 "\n", &good.number) != EXPECTED_SCANF_RESULT && ok == 0)
            ok = 1;
        else if (ok == 0)
            (*count)++;
    }
}

int add_to_array(FILE *f, size_t count, good_t *goods)
{
    for (size_t cur = 0; cur < count; cur++)
    {
        if (fscan_str(goods[cur].name, 31, f) != EXIT_SUCCESS)
            return EXIT_FAILURE;

        if (fscan_str(goods[cur].manufac, 16, f) != EXIT_SUCCESS)
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
                printf("%s\n%s\n%" PRIu32 "\n%" PRIu32 "\n", goods[i].name, goods[i].manufac, goods[i].amount, goods[i].number);
            }
    }

    if (temp_count == 0)
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}
