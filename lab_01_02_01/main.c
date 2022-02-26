#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, f;
    scanf("%lf%lf%lf", &a, &b, &f);
    double alpha = f * 3.14159265358979 / 180;
    double s = tan(alpha) * (fabs(a - b) / 2) * ((a + b) / 2);
    printf("%lf\n", s);
    return 0;
}
