#include "print_file.h"
#include "sort_file.h"
#include "add_to_file.h"

#define MAX_SIZE_OF_FILE 100

#define ERROR_WRONG_ARGS 53
#define ERROR_NO_FILE -2
#define ERROR_BAD_FILE -3
#define ERROR_WRONG_INPUT -4

int main(int argc, char **argv)
{
    if (strcmp(argv[1], "st") != 0 && strcmp(argv[1], "ft") != 0 && strcmp(argv[1], "at") != 0)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "st") == 0 && argc != 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "ft") == 0 && argc != 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "at") == 0 && argc != 3)
        return ERROR_WRONG_ARGS;

    FILE *f;

    if (strcmp(argv[1], "ft") == 0)
    {
        f = fopen(argv[2], "r");

        if (!f)
        {
            return ERROR_NO_FILE;
        }

        size_t count = 0;
        count_numbers(f, &count);
        fclose(f);

        if (count % 4 != 0)
        {
            return ERROR_BAD_FILE;
        }

        count /= 4;

        if (count > MAX_SIZE_OF_FILE)
            count = MAX_SIZE_OF_FILE;

        good_t goods[MAX_SIZE_OF_FILE];

        f = fopen(argv[2], "r");
        add_to_array(f, count, goods);
        fclose(f);
        print_file(goods, count, "");
    }

    if (strcmp(argv[1], "st") == 0)
    {
        f = fopen(argv[2], "r");

        if (!f)
        {
            return ERROR_NO_FILE;
        }

        size_t count = 0;
        count_numbers(f, &count);
        fclose(f);

        if (count % 4 != 0)
        {
            return ERROR_BAD_FILE;
        }

        count /= 4;

        if (count > MAX_SIZE_OF_FILE)
            count = MAX_SIZE_OF_FILE;

        good_t goods[MAX_SIZE_OF_FILE];

        f = fopen(argv[2], "r");
        add_to_array(f, count, goods);
        fclose(f);
        sort_file(goods, count);
        f = fopen(argv[3], "w");
        if (!f)
        {
            return ERROR_NO_FILE;
        }
        write_file(f, goods, count);
    }

    if (strcmp(argv[1], "at") == 0)
    {
        f = fopen(argv[2], "r");

        if (!f)
        {
            return ERROR_NO_FILE;
        }

        size_t count = 0;
        count_numbers(f, &count);
        fclose(f);

        if (count % 4 != 0)
        {
            return ERROR_BAD_FILE;
        }

        count /= 4;

        if (count > MAX_SIZE_OF_FILE)
            count = MAX_SIZE_OF_FILE;

        good_t goods[MAX_SIZE_OF_FILE];

        f = fopen(argv[2], "r");
        add_to_array(f, count, goods);
        fclose(f);
        good_t good;

        if (scanf("%s", good.name) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_INPUT;

        if (scanf("%s", good.manufac) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_INPUT;

        if (scanf("%u", &good.amount) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_INPUT;

        if (scanf("%u", &good.number) != EXPECTED_SCANF_RESULT)
            return ERROR_WRONG_INPUT;

        insert_to_array(goods, count, good);
        count++;
        f = fopen(argv[2], "w");
        write_file(f, goods, count);
    }

    return EXIT_SUCCESS;
}
