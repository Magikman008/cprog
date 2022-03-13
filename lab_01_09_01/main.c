#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 1
#define ERROR_SCANF 1
#define NULL_SEQ 1

int main()
{
    double x, sum = 0;
    int rc = scanf("%lf", &x);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }
    if (x < 0)
    {
        printf("Wrong input\n");
        return NULL_SEQ;
    }
    int index = 1;
    while (x >= 0)
    {
        sum += sqrt(x / index);
        int rc = scanf("%lf", &x);
        if (rc != EXPECTED_SCANF_VALUE)
        {
            printf("Wrong input\n");
            return ERROR_SCANF;
        }
        index += 1;
    }
    sum = sin(sum);
    printf("%lf", sum);
    return EXIT_SUCCESS;
}
