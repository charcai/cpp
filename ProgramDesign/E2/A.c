#include <stdio.h>
#include <math.h>

int main() {
    double r, ti;
    scanf("%lf%lf", &r, &ti);
    printf("%.1lf %.1lf\n", r * cos(ti), r * sin(ti));
    return 0;
}