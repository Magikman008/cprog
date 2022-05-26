#include "make_file.h"
#include "print_file.h"
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define ERROR_WRONG_ARGS -1

int main(int argc, char **argv)
{
    if (argc < 3 || argc > 4)
        return ERROR_WRONG_ARGS;

    if (strcmp(argv[1], "c") != 0 && argc == 4)
        return ERROR_WRONG_ARGS;

    FILE *f;

    if (argc == 4)
    {
        if (atoi(argv[2]) < 1)
            return ERROR_WRONG_ARGS;
        int number = atoi(argv[2]);
        f = fopen(argv[3], "wb");
        fill_file(f, number);
        fclose(f);
    }

    if (argc == 3)
    {
        f = fopen(argv[2], "rb");
        print_file(f);
        fclose(f);
    }
    // FILE *f = fopen(argv[1], "r");

    // if (f == NULL)
    //     return ERROR_EMPTY_FILE;

    // float average;
    // int rc = find_average(f, &average);

    // if (rc != EXIT_SUCCESS)
    //     return rc;

    // fclose(f);

    // f = fopen(argv[1], "r");
    // float nearest;
    // rc = find_nearest(f, average, &nearest);

    // if (rc != EXIT_SUCCESS)
    //     return rc;

    // printf("%f\n", nearest);
    // fclose(f);

    return EXIT_SUCCESS;
}
