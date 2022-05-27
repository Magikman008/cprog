#include "print_file.h"
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_RESULT 1

#define ERROR_NO_NUMBERS -3

int count_numbers(FILE *f)
{
    int cur;
    int count = 0;

    while (fread(&cur, sizeof(int), 1, f) == EXPECTED_SCANF_RESULT)
        count++;

    if (count == 0)
        return ERROR_NO_NUMBERS;

    return EXIT_SUCCESS;
}

int print_file(FILE *f)
{
    int cur;

    while (fread(&cur, sizeof(int), 1, f) == EXPECTED_SCANF_RESULT)
        printf("%d ", cur);

    return EXIT_SUCCESS;
}