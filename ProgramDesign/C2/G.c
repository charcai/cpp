#include <stdio.h>
#include <math.h>

int main() {
    int a, b, c;
    scanf("%d%d%d", &a, &b, &c);
    if(a == 0) {
        if(b == 0) {
            if(c == 0) {
                puts("infinite solutions");
                return 0;
            }
            else {
                puts("No real root");
            }
        }
        else {
            printf("%.2lf\n", -1.0 * c / b);
            return 0;
        }
    }
    else {
        int delta = (b * b) - 4 * a * c;
        if(delta < 0) {
            puts("No real root");
            return 0;
        }
        else if(delta == 0) {
            printf("%.2lf\n", -1.0 * b / a / 2);
        }
        else {
            double s1 = (-1.0 * b + sqrt(delta)) / a / 2;
            double s2 = (-1.0 * b - sqrt(delta)) / a / 2;
            if(s1 > s2) {
                double tmp = s1;
                s1 = s2;
                s2 = tmp;
            }
            printf("%.2lf %.2lf\n", s1, s2);
        }
        return 0;
    }
}