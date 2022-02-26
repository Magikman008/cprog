#include <stdio.h>
#include <math.h>

int main()
{
    double a, b, f;
    scanf("%lf%lf%lf", &a, &b, &f);
    double alpha = f * 3.14159265358979 / 180;
    //double s = fabs(pow(a, 2) - pow(b, 2)) * tan(alpha) / 2;
    double s = tan(alpha) * ((a - b) / 2) * ((a + b) / 2);
    printf("%lf\n", s);
    return 0;
}
