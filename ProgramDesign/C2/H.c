#include <stdio.h>

double m;
int a, b, c, d;

int main() {
    while(scanf("%lf%d%d%d%d", &m, &a, &b, &c, &d) != EOF) {
        double acc = (a * 1.0 + b * 0.65) / (a + b + c + d);
        double rks = 0;
        if(acc > 0.7 - 1e-10) {
            rks = m * ((acc - 0.55) / 0.45) * ((acc - 0.55) / 0.45);
        }
        printf("%.4g%c %.4lf\n", acc * 100, '%', rks);
    }
    return 0;
}