#include <stdio.h>
#include <math.h>

int main()
{
    double v1, t1, v2, t2;
    scanf("%lf%lf%lf%lf", &v1, &t1, &v2, &t2);
    double ts = (v1 * t1 + v2 * t2) / (v1 + v2);
    double vs = v1 + v2;
    printf("%lf %lf\n", vs, ts);
    return 0;
}
