#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 4
#define ERROR_SCANF 1

void printing(unsigned x)
{
    for (int i = 0; i < 8; i++)
    {
        unsigned bit = (x >> (7 - i)) & 1;
        printf("%u", bit);
    }
}

int main()
{
    unsigned x1, x2, x3, x4;

    int rc = scanf("%u%u%u%u", &x1, &x2, &x3, &x4);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Error: %d", ERROR_SCANF);
        return EXIT_FAILURE;
    }

    printf("Result: ");
    printing(x1);
    printing(x2);
    printing(x3);
    printing(x4);
    printf(" %u %u %u %u", x1, x2, x3, x4);
    return EXIT_SUCCESS;
}
