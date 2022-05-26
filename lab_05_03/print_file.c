#include "print_file.h"
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_RESULT 1

int print_file(FILE *f)
{
    int cur;
    while (fread(&cur, sizeof(int), 1, f) == EXPECTED_SCANF_RESULT)
        printf("%d ", cur);

    return EXIT_SUCCESS;
}