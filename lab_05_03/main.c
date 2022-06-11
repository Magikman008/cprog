#include "make_file.h"
#include "print_file.h"
#include "sort_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR_WRONG_ARGS -1
#define ERROR_NO_FILE -2
#define ERROR_NO_NUMBERS -3
#define ERROR_BAD_FCLOSE -4

int execute_p(char *s)
{
    FILE *f;
    f = fopen(s, "rb");

    if (!f)
    {
        return ERROR_NO_FILE;
    }

    size_t count = 0;
    count_numbers(f, &count);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    if (count == 0)
        return ERROR_NO_NUMBERS;

    f = fopen(s, "rb");
    print_file(f);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    return EXIT_SUCCESS;
}

int execute_s(char *s)
{
    FILE *f;
    f = fopen(s, "rb");

    if (!f)
    {
        return ERROR_NO_FILE;
    }

    size_t count = 0;
    count_numbers(f, &count);

    if (fclose(f) != 0)
        return ERROR_BAD_FCLOSE;

    if (count == 0)
        return ERROR_NO_NUMBERS;

    sort_file(s, count);

    return EXIT_SUCCESS;
}

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "c") != 0 && argc == 4)
        return ERROR_WRONG_ARGS;

    FILE *f;

    if (argc == 4)
    {
        int number = atoi(argv[2]);

        if (number < 1)
            return ERROR_WRONG_ARGS;

        f = fopen(argv[3], "wb");
        fill_file(f, number);
        fclose(f);
        return EXIT_SUCCESS;
    }

    if (argc == 3 && (strcmp(argv[1], "p") != 0 && strcmp(argv[1], "s") != 0))
        return ERROR_WRONG_ARGS;

    int rc;

    if (strcmp(argv[1], "p") == 0)
    {
        rc = execute_p(argv[2]);
        if (rc)
            return rc;
    }

    if (strcmp(argv[1], "s") == 0)
    {
        rc = execute_s(argv[2]);
        if (rc)
            return rc;
    }

    return EXIT_SUCCESS;
}
