#include "make_file.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>

#define EXPECTED_SCANF_RESULT 1

int fill_file(FILE *f, const size_t amount)
{
    srand(time(NULL));
    for (size_t i = 0; i < amount; i++)
    {
        int x = rand() % 30000;
        if (fwrite(&x, sizeof(int), 1, f) != 1)
            return EXIT_FAILURE;
    }
    return EXIT_SUCCESS;
}