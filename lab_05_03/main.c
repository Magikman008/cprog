#include "make_file.h"
#include "print_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR_WRONG_ARGS -1
#define ERROR_NO_FILE -2

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

    if (strcmp(argv[1], "p") == 0)
    {
        f = fopen(argv[2], "rb");

        if (!f)
        {
            fclose(f);
            return ERROR_NO_FILE;
        }

        int rc = count_numbers(f);

        if (rc)
            return rc;

        print_file(f);
        fclose(f);
    }

    return EXIT_SUCCESS;
}
