#include "process_file.h"
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_RESULT 1

int find_average(FILE *f, float *average)
{
    float count = 0;
    float sum = 0;
    float num;

    while (fscanf(f, "%f", &num) == EXPECTED_SCANF_RESULT)
    {
        count++;
        sum += num;
    }

    if (count < 0.5)
        return ERROR_NO_NUMBERS;

    *average = sum / count;

    return EXIT_SUCCESS;
}

int find_nearest(FILE *f, const float average, float *nearest)
{
    float num;
    int rc = fscanf(f, "%f", nearest);

    if (rc != EXPECTED_SCANF_RESULT)
        return ERROR_NO_NUMBERS;

    while (fscanf(f, "%f", &num) == EXPECTED_SCANF_RESULT)
        if (fabs(average - num) <= fabs(average - *nearest))
            *nearest = num;

    return EXIT_SUCCESS;
}