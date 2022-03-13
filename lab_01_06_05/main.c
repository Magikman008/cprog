#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define EXPECTED_SCANF_VALUE 8
#define ERROR_SCANF 1
#define EPS 1E-7

int checking(double x1, double y1, double x2, double y2, double x3, double y3,
             double x4, double y4)
{
    double k1 = (x2 - x1) / (y2 - y1);
    double k2 = (x4 - x3) / (y4 - y3);
    if (fabs(k1 - k2) < EPS) return 0;
    double x = ((x1 * y2 - x2 * y1) * (x4 - x3) - (x3 * y4 - x4 * y3) *
                (x2 - x1)) / ((y1 - y2) * (x4 - x3) - (y3 - y4) * (x2 - x1));
    double y = ((y3 - y4) * x - (x3 * y4 - x4 * y3)) / (x4 - x3);
    int x_ok = 0;
    if (x <= x1 && x >= x2 && x <= x3 && x >= x4) x_ok = 1;
    if (x <= x1 && x >= x2 && x >= x3 && x <= x4) x_ok = 1;
    if (x >= x1 && x <= x2 && x <= x3 && x >= x4) x_ok = 1;
    if (x >= x1 && x <= x2 && x >= x3 && x <= x4) x_ok = 1;
    int y_ok = 0;
    if (y <= y1 && y >= y2 && y <= y3 && y >= y4) y_ok = 1;
    if (y <= y1 && y >= y2 && y >= y3 && y <= y4) y_ok = 1;
    if (y >= y1 && y <= y2 && y <= y3 && y >= y4) y_ok = 1;
    if (y >= y1 && y <= y2 && y >= y3 && y <= y4) y_ok = 1;
    if (x_ok == 1 && y_ok == 1) return 1;
    return 0;
}

int main()
{
    double x1, y1, x2, y2, x3, y3, x4, y4;
    int rc = scanf("%lf%lf%lf%lf%lf%lf%lf%lf", &x1, &y1, &x2, &y2, &x3, &y3, &x4, &y4);
    if (rc != EXPECTED_SCANF_VALUE)
    {
        printf("Wrong input\n");
        return ERROR_SCANF;
    }
    printf("%d", checking(x1, y1, x2, y2, x3, y3, x4, y4));
    return 0;
}
