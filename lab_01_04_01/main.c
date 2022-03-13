#include <stdio.h>

int main()
{
    double num;
    scanf("%lf", &num);
    double entrance = (int)((num + 35) / 36);
    double floor = (int)((num - ((entrance - 1) * 36) + 3) / 4);
    printf("%lf %lf\n", entrance, floor);
    return 0;
}
