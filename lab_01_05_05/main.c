#include <stdio.h>

void printing(int x)
{
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

int main()
{
    int n;
    int rc = scanf("%i", &n);
    if (rc != 1 || n < 0)
        return 0;
    else
        printing(n);
    return 0;
}
