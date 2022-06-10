#include "process_sequence.h"
#include <stdlib.h>

#define EXPECTED_SCANF_RESULT 1

int process(FILE *f, int *maximum)
{
    int prev;
    int rc = fscanf(f, "%d", &prev);

    if (rc != EXPECTED_SCANF_RESULT)
        return ERROR_NO_NUMBERS;

    int cur;
    *maximum = 1;
    int cur_maximum = 1;

    while (fscanf(f, "%d", &cur) == EXPECTED_SCANF_RESULT)
    {
        if (prev == cur)
            cur_maximum++;
        else
        {
            if (*maximum < cur_maximum)
                *maximum = cur_maximum;
            cur_maximum = 1;
        }

        prev = cur;
    }

    return EXIT_SUCCESS;
}
