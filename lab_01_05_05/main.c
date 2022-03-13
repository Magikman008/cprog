#include <stdio.h>
#include <stdlib.h>

#define EXPECTED_SCANF_VALUE 1
#define ERROR_SCANF 1
#define ERROR_NUM 2

void printing(int x)
{
    if (x == 0)
    {
        printf("0\n");
    } else {
        int tmp = 1;
        while (tmp <= x)
        {
            tmp *= 10;
        }
        tmp /= 10;
        while (tmp > 0)
        {
            printf("%i", x / tmp);
            x %= tmp;
            tmp /= 10;
        }
        printf("\n");
    }

}

int main()
{
    int n;
    int rc = scanf("%i", &n);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }
    if (n < 0)
    {
        printf("Wrong input\n");
        return ERROR_NUM;
    }
    printing(n);
    return EXIT_SUCCESS;
}
