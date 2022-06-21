#include "print_file.h"
#include <stdlib.h>

#define EXPECTED_SCANF_RESULT 1

void count_numbers(FILE *f, size_t *count)
{
    int cur;
    int si = sizeof(int);

    while (fread(&cur, si, 1, f) == EXPECTED_SCANF_RESULT)
        (*count)++;
}

int print_file(FILE *f)
{
    int cur;
    int si = sizeof(int);

    while (fread(&cur, si, 1, f) == EXPECTED_SCANF_RESULT)
        printf("%d ", cur);

    return EXIT_SUCCESS;
}
