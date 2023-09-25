#include <stdio.h>

double sq(double x) {
    return x * x;
}

int main() {
    double m;
    int a, b, c, d;
    while(scanf("%lf%d%d%d%d", &m, &a, &b, &c, &d) != EOF) {
        double acc = (a * 1.0 + b * 0.65) / (a + b + c + d);
        double rks;
        if(acc > 0.7 - 1e-10) {
            rks = m * sq((acc - 0.55) / 0.45);
        }
        else {
            rks = 0;
        }
        printf("%.4g", acc * 100);
        putchar('%');
        printf(" %.4lf\n", rks);
    }
    return 0;
}