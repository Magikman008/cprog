#include "case.h"
#include "print_file.h"
#include "sort_file.h"
#include "add_to_file.h"

int case_ft(char *s1, char *s2)
{
    FILE *f;
    f = fopen(s1, "r");

    if (!f)
        return ERROR_NO_FILE;

    size_t count = 0;
    count_numbers(f, &count);
    fseek(f, 0, SEEK_SET);

    if (count % 4 != 0)
    {
        fclose(f);
        return ERROR_BAD_FILE;
    }

    count /= 4;

    if (count > MAX_SIZE_OF_FILE)
        count = MAX_SIZE_OF_FILE;

    good_t goods[MAX_SIZE_OF_FILE];

    add_to_array(f, count, goods);
    fclose(f);

    if (print_file(goods, count, strcat(s2, "\n")))
        return EXIT_FAILURE;

    return EXIT_SUCCESS;
}

int case_st(char *s1, char *s2)
{
    FILE *f;
    f = fopen(s1, "r");

    if (!f)
        return ERROR_NO_FILE;

    size_t count = 0;
    count_numbers(f, &count);
    fclose(f);

    if (count % 4 != 0)
    {
        fclose(f);
        return ERROR_BAD_FILE;
    }

    count /= 4;

    if (count > MAX_SIZE_OF_FILE)
        count = MAX_SIZE_OF_FILE;

    good_t goods[MAX_SIZE_OF_FILE];

    f = fopen(s1, "r");
    add_to_array(f, count, goods);
    fclose(f);
    sort_file(goods, count);
    f = fopen(s2, "w");

    if (!f)
        return ERROR_NO_FILE;

    write_file(f, goods, count);
    fclose(f);
    return EXIT_SUCCESS;
}

int case_at(char *s1)
{
    FILE *f;
    good_t good = { 0 };

    if (scanf("%s", good.name) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%s", good.manufac) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%" SCNu32 "", &good.amount) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    if (scanf("%" SCNu32 "", &good.number) != EXPECTED_SCANF_RESULT)
        return ERROR_WRONG_INPUT;

    strcpy(good.name, strcat(good.name, "\n"));
    strcpy(good.manufac, strcat(good.manufac, "\n"));

    size_t count = 0;
    f = fopen(s1, "r");
    good_t goods[MAX_SIZE_OF_FILE];

    if (f)
    {
        count_numbers(f, &count);
        fseek(f, 0, SEEK_SET);

        if (count % 4 != 0)
        {
            fclose(f);
            return ERROR_BAD_FILE;
        }

        count /= 4;

        if (count > MAX_SIZE_OF_FILE)
            count = MAX_SIZE_OF_FILE;

        add_to_array(f, count, goods);
        fclose(f);
    }

    count++;
    insert_to_array(goods, count, good);
    f = fopen(s1, "w");
    write_file(f, goods, count);
    fclose(f);

    return EXIT_SUCCESS;
}