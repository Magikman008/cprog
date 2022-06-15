#include "case.h"
#include "print_file.h"
#include "sort_file.h"
#include "add_to_file.h"

int open_file(FILE *f, size_t *count)
{
    if (!f)
        return ERROR_NO_FILE;

    count_numbers(f, count);

    if (*count % 4 != 0)
    {
        if (f && fclose(f) != 0)
            return ERROR_BAD_FCLOSE;
        return ERROR_BAD_FILE;
    }

    fseek(f, 0, SEEK_SET);
    (*count) /= 4;

    return EXIT_SUCCESS;
}

int case_ft(char *s1, char *s2)
{
    FILE *f = NULL;
    f = fopen(s1, "r");
    size_t count = 0;

    int rc = open_file(f, &count);

    if (rc)
        return rc;

    good_t goods[MAX_SIZE_OF_FILE];

    add_to_array(f, count, goods);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    if (print_file(goods, count, s2))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int case_st(char *s1, char *s2)
{
    FILE *f = NULL;
    f = fopen(s1, "r");
    size_t count = 0;

    int rc = open_file(f, &count);

    if (rc)
        return rc;

    good_t goods[MAX_SIZE_OF_FILE];

    add_to_array(f, count, goods);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    sort_file(goods, count);
    f = fopen(s2, "w+");

    if (!f)
        f = fopen(s2, "w");

    if (!f)
        return ERROR_NO_FILE;

    write_file(f, goods, count);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    return EXIT_SUCCESS;
}

int case_at(char *s1)
{
    FILE *f = NULL;
    good_t good = {0};

    if (scanf("%s", good.name) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%s", good.manufac) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%" SCNu32 "", &good.amount) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%" SCNu32 "", &good.number) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    f = fopen(s1, "r");
    good_t goods[MAX_SIZE_OF_FILE];

    size_t count = 0;

    int rc = open_file(f, &count);

    if (rc)
        return rc;

    add_to_array(f, count, goods);

    if (f && fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    insert_to_array(goods, count, good);
    count++;
    f = fopen(s1, "w+");

    if (!f)
        return ERROR_NO_FILE;

    write_file(f, goods, count);

    if (f && fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    return EXIT_SUCCESS;
}