#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 4
#define ERROR_SCANF 1
#define WRONG_INPUT 2

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
    if (rc != EXPECTED_SCANF_VALUE){
        printf("Error: %d", ERROR_SCANF);
        return EXIT_FAILURE;
    }
    /*if (x1 < 0 || x1 > 255 || x2 < 0 || x2 > 255 || x3 < 0 || x3 > 255 ||
            x4 < 0 || x4 > 255)
    {
        printf("Error: %d", WRONG_INPUT);
        return EXIT_FAILURE;
    }*/
    printing(x1);
    printing(x2);
    printing(x3);
    printing(x4);
    //printf("Result: %c", a);
    return EXIT_SUCCESS;
}
